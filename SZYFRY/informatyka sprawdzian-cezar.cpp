#include <bits/stdc++.h>
using namespace std;

const string alfabet_m="aπbcÊdeÍfghijkl≥mnÒoÛpqrsútuvwxyzüø";
const string alfabet_d="A•BC∆DE FGHIJKL£MN—O”PQRSåTUVWXYZèØ";

string Cezar(int klucz, string s)
{
    string szyfr = "";
    int kod;
    for (int i = 0; i < s.size(); i++)      //caly string
    {
        kod = s[i] + klucz;                 //kod to kod ASCII litery przesunietej o podany klucz
        if (kod > 'Z')                      //jesli wyszedl poza zakres alfabetu
        {
            kod -= 26;                      //zaczynamy znowu od poczatku alfabetu
        }
        szyfr += char(kod);                 //zapisujemy zakodowana litere na string szyfr
    }
    return szyfr;
}

string CezarMD(int klucz, string s)
{
    string szyfr="";
    int kod;
    for(int i = 0; i < s.size(); i++)                            //caly string
    {
        if((toupper(s[i]) >= 'A') && (toupper(s[i]) <= 'Z'))     //jezeli powiekszona litera miesci sie w alfabecie
        {
            kod = s[i] + klucz;                                  //26-klucz? kod to kod ASCII litery przesunietej o podany klucz
            if((s[i]<='Z' && kod>'Z') || (s[i]>='a' && kod>'z')) //jezeli znak jest litera
            {
                kod -= 26;                                       //zaczynamy od poczatku alfabetu
            }
            szyfr += char(kod);                                  //zapisujemy zakodowana litere na string szyfr
        }
        else                                                     //jezeli znak nie litera
        {
            szyfr += s[i];                                       //zapisujemy znak bez zmian
        }
    }
    return szyfr;
}

char CezarPL(int klucz, char znak)
{
    int i = alfabet_m.find(znak);               //szukamy indeksu litery szukanej w stringu alfabecie polskim z malych liter
    if(i > 0 && i < 35)                         //jezeli sie miescimy w zakresie alfabetu polskiego
    {
        i = (i+klucz) % 35;                     //i to pozycja litery, ktora zastapi litere tekstu jawnego w szyfrogramie
        return alfabet_m[i];                    //wypisujemy ta litere z string alfabetu polskiego z malych liter
    }
    i = alfabet_d.find(znak);                   //szukamy indeks litery szukanej w stringu alfabecie polskim z suzych liter
    if(i > 0 && i < 35)                         //jezeli sie miescimy w zakresie alfabetu polskiego
    {
        i = (i+klucz) % 35;                     //ii to pozycja litery, ktora zastapi litere tekstu jawnego w szyfrogramie
        return alfabet_d[i];                    //wypisujemy ta litere z string alfabetu polskiego z duzych liter
    }
    return znak;
}

string CezarZCezarPL(int klucz, string s)
{
    string szyfr = "";
    for(int i = 0; i < s.size(); i++)           //caly string
    {
        szyfr += CezarPL(klucz, s[i]);          //zapisujemy zakodowane litery na string szyfr
    }
    return szyfr;
}


string Odszyfruj(int klucz, string s)
{
    string szyfr = "";
    int kod;
    for (int i = 0; i < s.size(); i++)          //caly string
    {
        kod = s[i] + 26 - klucz;                //kod ASCII litery poczatkowej przed przesunieciem o podany klucz
        if (kod > 'Z')                          //jezeli jestesmy poza alfabetem
        {
                kod -= 26;                      //zaczynamy od poczatku
        }
        szyfr += char(kod);                     //zapisujemy odszyfrowana litere na string
    }
    return szyfr;
}

int ZnajdzKlucz(string s)
{
    int Licznik[35];
    int klucz = 0;
    for(int i = 0; i < 35; i++)                 //pusta tablica
    {
        Licznik[i] = 0;
    }
    for(int i = 0; i < s.size(); i++)
    {
        int j = alfabet_m.find(s[i]);               //j to indeks alfabetu polskiego malego litery z ciagu znakow s
        if(j >= 0 && j < 35)                    //jezeli nalezy do tablicy
        {
            Licznik[j]++;                       //zliczamy ta litere
        }
        else
        {
            int j = alfabet_d.find(s[i]);
            if(j >= 0 && j < 35)
            {
                Licznik[j]++;
            }
        }
    }
    for(int i = 1; i < 35; i++)                 //tablica
    {
        if(Licznik[i] > Licznik[klucz])         //wartosc pod indeksem i jest wieksza od wartosci pod indeksem z klucza
        {
            klucz = i;                          //klucz to bedzie najwieksza wartosc pod indeksem i
        }
    }
    return klucz;
}

int IleRazy(string s)                           // MOØE NIE DZIA£A∆
{
    int Licznik[26];
    char znak;
    int indeks_m;
    for(int i = 0; i < 26; i++)                 //pusta tablica
    {
        Licznik[i] = 0;
    }
    for(int i = 0; i < s.size(); i++)           //litery alfabetycznie sortuje, zapisuje na odpowiednich miejscach i je zlicza
    {
        znak = toupper(s[i]);
        if(znak > 'A' && znak <= 'Z')           //jezeli jest litera
        {
            Licznik[znak-'A']++;                //indeksowanie musi byc od 0 dlatego s[i] - 'A'
        }
    }
    for(int i = 0; i < 26; i++)                 //wypisuje tylko te litery, ktore sa w tym slowie i ile ich jest (te ktore nie sa maja pod swoim indeksem 0 wiec ich nie wypisuje)
    {
        if(Licznik[i] > 0)
        {
            cout << char(i+'A') << "-" << Licznik[i] << endl;
        }
    }


    for(int i = 1; i < 26; i++)                 //Najczesciej wystepujaca
    {
        if(Licznik[i] > Licznik[indeks_m])
        {
            indeks_m = i;
        }
    }
    cout << "Najczesciej wystepujaca litera: " << char(indeks_m+'A') << endl;
}


int main()
{
    ifstream wejscie("tekst_jawny.txt");
    ofstream wyjscie("szyfrogram.txt");

    int Licznik[26];
    string s;
    int klucz;
    char znak;

    cout << "Klucz: ";
    cin >> klucz;
    cout<<endl;

    while (getline(wejscie, s))
   {
        wyjscie << CezarZCezarPL(klucz, s) << endl;
    }

    wejscie.close();
    wyjscie.close();

    cout << "Plik zrobiony" << endl;
    cout << Odszyfruj(8, "INTERNET") << endl;
    cout << "Klucz: " << ZnajdzKlucz("QWERTY") << endl;

    /*for(int i = 0; i < 26; i++)
    {
        cout << "Klucz: " << i << Odszyfruj(i, s) << endl;
    }*///To jest szukanie klucza by bruteforce

    IleRazy(s);                                 //zlicza litery w danym slowie
}
