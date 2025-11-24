#include <bits/stdc++.h>
using namespace std;

const int ile = 10;

void Zad1(int zbior[])//Najdluzszy podciag malejacy
{
    int maks_dlugosc = 1, akt_dlugosc = 1, pocz=0, maks_pocz=0;

    for(int i=1;i<ile;i++)
    {
        if(zbior[i] < zbior[i-1])
        {
            akt_dlugosc++;
        }
        else
        {
            if(akt_dlugosc > maks_dlugosc)
            {
                maks_dlugosc=akt_dlugosc, maks_pocz=pocz;
            }
            akt_dlugosc = 1;
            pocz = i;
        }
    }

    if(akt_dlugosc > maks_dlugosc)
    {
        maks_dlugosc = akt_dlugosc;
        maks_pocz = pocz;
    }
}

void Zad2(int zbior[])//Najdluzszy rosnacy – wypisz ostatni
{
    int maks_dlugosc = 1, akt_dlugosc = 1, pocz=0, maks_pocz=0;

    for(int i=1;i<ile;i++)
    {
        if(zbior[i] > zbior[i-1])
        {
            akt_dlugosc++;
        }
        else
        {
            akt_dlugosc = 1;
            pocz = i;
        }
        if(akt_dlugosc >= maks_dlugosc)   // >= aby brac ostatni
        {
            maks_dlugosc = akt_dlugosc;
            maks_pocz = i - akt_dlugosc + 1;
        }
    }

    cout << "Najdluzszy spojny podciag malejacy: ";

    for(int i = maks_pocz; i < maks_pocz+maks_dlugosc; i++)
    {
        cout << zbior[i] << " ";
    }
    cout << endl;
}

void Zad3(int zbior[]) //Najdluzszy rosnacy – wypisz wszystkie
{
    int maks_dlugosc = 1, akt_dlugosc = 1, pocz;

    for(int i=1;i<ile;i++)// znajdz dlugosc
    {
        if(zbior[i] > zbior[i-1])
        {
            akt_dlugosc++;
        }
        else
        {
            akt_dlugosc=1;
        }
        maks_dlugosc = max(maks_dlugosc, akt_dlugosc);
    }

    cout << "Najdluzsze podciagi rosnace (wszystkie): " << endl;

    akt_dlugosc = 1;

    for(int i = 1; i < ile; i++)
    {
        if(zbior[i] > zbior[i-1])
        {
            akt_dlugosc++;
        }
        else
        {
            akt_dlugosc = 1;
        }
        if(akt_dlugosc == maks_dlugosc)
        {
            pocz = i-akt_dlugosc+1;

            for(int j = pocz; j <= i; j++)
            {
                cout<<zbior[j]<<" ";
            }
            cout << endl;
        }
    }
}

void Zad4(int zbior[]) //Najdluzszy spojny podciag liczb dodatnich
{
    int maks_dlugosc = 0, akt_dlugosc = 0, maks_pocz=0, pocz=0;

    for(int i=0;i<ile;i++)
    {
        if(zbior[i] > 0)
        {
            akt_dlugosc++;
        }
        else
        {
            if(akt_dlugosc > maks_dlugosc)
            {
                maks_dlugosc = akt_dlugosc;
                maks_pocz = pocz;
            }
            akt_dlugosc = 0;
            pocz = i+1;
        }
    }
    if(akt_dlugosc > maks_dlugosc)
    {
        maks_dlugosc = akt_dlugosc;
        maks_pocz = pocz;
    }

    cout << "Najdluzszy dodatni podciag spojny: ";
    for(int i = maks_pocz; i < maks_pocz+maks_dlugosc; i++)
    {
        cout<<zbior[i]<<" ";
    }
    cout << endl;
}

void Zad5(int zbior[]) //Maksymalna suma podciagu – tablica czytana max 2x
{
    int suma = MSPS(zbior);
    cout << "Maksymalna suma podciagu spojnego: " << suma << endl;
}

void Zad6(int zbior[]) //Liczba podciagow o danej sumie
{
    int akt_suma, suma;
    cout << "Podaj sume: ";
    cin >> akt_suma;

    int ile_suma = 0;

    for(int i = 0; i < ile; i++)
    {
        suma = 0;

        for(int j = i; j < ile; j++)
        {
            suma += zbior[j];
            if(suma == akt_suma)
            {
                ile_suma++;
            }
        }
    }

    cout << "Liczba podciagow o sumie " << akt_suma << ": " << ile_suma << endl;
}

void Zad7(int zbior[]) //Wypisz wszystkie podciagi o danej sumie
{
    int akt_suma, suma;
    cout << "Podaj sume: ";
    cin >> akt_suma;

    cout << "Podciagi o sumie " << akt_suma << ": " << endl;

    for(int i = 0; i < ile; i++)
    {
        suma = 0;
        for(int j = i; j < ile; j++)
        {
            suma += zbior[j];
            if(suma == akt_suma)
            {
                for(int k = i; k <= j; k++)
                {
                    cout << zbior[k] << " ";
                }
                cout << endl;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int zbior[ile];

    Losuj(zbior);
    Wypisz(zbior);

    Zad1(zbior);

    Zad2(zbior);

    Zad3(zbior);

    Losuj2(zbior); // potrzebne liczby dodatnie i ujemne

    Zad4(zbior);

    Zad5(zbior);

    Zad6(zbior);

    Zad7(zbior);

    return 0;
}
