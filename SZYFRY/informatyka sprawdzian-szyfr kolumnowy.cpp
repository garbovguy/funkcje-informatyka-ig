#include <bits/stdc++.h>
using namespace std;

string Kolumnowy(int klucz, string s)
{
    string szyfr = "";
    for(int i = 0; i < klucz; i++)
    {
        for(int j = i; j < s.size(); j += klucz)
        {
            szyfr += s[j];
        }
    }
    return szyfr;
}

string KolumnowyZX(int klucz, string s)
{
    string szyfr = "";
    while (s.size()%klucz != 0)
    {
        s += 'X';
    }
    for (int i = 0; i < klucz; i++)
    {
        for(int j = 0; j < s.size()/klucz; j++)
        {
            szyfr += s[j*klucz+i];
        }
    }
    return szyfr;
}

string KolumnowyZX2 (string klucz, string s)
{
    string szyfr = "";
    int i, j;
    while (s.size()%klucz.size() != 0)                      //ostatni wiersz
    {
        s += 'X';                                           //uzupelniony literami X
    }
    for(i = 0; i < klucz.size(); i++)                       //kolumny
    {
        for(int j = 0; j < s.size()/klucz.size(); j++)      //wiersze
        {
            szyfr += s[j*klucz.size()+klucz[i]-'0'];        //tworzenie szyfru z koleinych znakow znajdujacych sie w j-tej kolumni i i-tym wierszu
        }
    }
}

int main()
{
    string s, klucz2;
    int klucz;

    cout << "Klucz: " << endl;
    getline(cin, klucz2);
    cout << KolumnowyZX2(klucz2, s) << endl;
}
