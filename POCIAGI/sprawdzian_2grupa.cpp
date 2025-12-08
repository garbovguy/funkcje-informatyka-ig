#include <iostream>
#include <cctype>
#include <ctime>
using namespace std;

const int ile = 10;

int DNSPNM(int zbior[])                     //Dlugosc Najdluzszego Spojnego Podciagu Niemalejacego
{
    int maks_dlugosc=1, akt_dlugosc=1;

    for(int i = 1; i < ile; i++)
    {
        if(zbior[i] >= zbior[i-1])
        {
            akt_dlugosc++;
            maks_dlugosc = max(maks_dlugosc, akt_dlugosc);
        }
        else
        {
            akt_dlugosc = 1;
        }
    }
    return maks_dlugosc;
}

void PSMS (int zbior[], int &maks_suma, int &maks_poczatek, int &maks_koniec) //Podciag Spojny o Maksymalnej Sumie NIE DZIA£A??
{
    maks_suma = zbior[0];
    maks_poczatek = 0;
    maks_koniec = 0;

    int akt_suma = zbior[0];
    int akt_poczatek = 0;

    for(int i = 1; i < ile; i++)
    {
        if(akt_suma + zbior[i] < zbior[i])
        {
            akt_suma = zbior[i];
            akt_poczatek = i;
        }
        else
        {
            akt_suma += zbior[i];
        }

        if(akt_suma > maks_suma)
        {
            maks_suma = akt_suma;
            maks_poczatek = akt_poczatek;
            maks_koniec = i;
        }
    }
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


void Losuj(int zbior[]) //dla reszty algorytmow 0-99
{
    for (int i = 0; i < ile; i++)
    {
        zbior[i] = rand()%100;
    }
}
void Losuj2(int zbior[]) //dla algorytmu MSPS bo potrzebuje conajmniej jedna liczbe nieujemna -50 - 49
{
    for(int i = 0; i < ile; i++)
    {
        zbior[i] = rand()%100-50;
    }

    zbior[rand()%ile] = rand()%50; //>=0
}

void Wypisz(int zbior[])
{
    for(int i = 0; i < ile; i++)
    {
        cout << zbior[i] <<" ";
    }
}
int main()
{
    int zbior[ile];
    srand(time(NULL));
    int poczatek, dlugosc, suma, tmp=0, koniec, i;

    Losuj2(zbior);
    Wypisz(zbior);

    //--------------------------------------------------------------
    //cout<<endl<<DNSPNM(zbior);
    //--------------------------------------------------------------
    /*
    PSMS(zbior, suma, poczatek, koniec);
    cout << endl << "Maksymalna suma podciagu spojnego: " << suma << endl;
    cout << "Podciag spojny o maksymalnej sumie: " << endl;

    i = poczatek;

    for(int j = poczatek; j <= koniec; j++)
{
    cout << zbior[j] << " ";
}
*/
    //---------------------------------------------------------------
    //Zad3(zbior);
    //---------------------------------------------------------------
    //Zad4(zbior);
    //---------------------------------------------------------------
    //Zad7(zbior);
}
