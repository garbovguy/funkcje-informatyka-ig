#include <bits/stdc++.h>
using namespace std;

void Sortuj(string &s)
{
    int m;
    char znak;
    for(int i = 0; i < s.size()-1; i++)
    {
        m = i;
        for(int j = 0; i < s.size(); j++)
        {
            if(s[j] < s[m])
            {
                m = j;
            }
        }
        znak = s[i];
        s[i] = s[m];
        s[m] = znak;
    }
}

bool Anagramy(string s1, string s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }
    Sortuj(s1);
    Sortuj(s2);
    return (s1 == s2);
}

void Zlicz(string s, int ile[])
{
    for(int i = 0; i < 26; i++)
    {
        ile[i]=0;
    }
    for(int i = 0; i < s.size(); i++)
    {
        ile[s[i]-'A']++;
    }
}

bool AnagramyZZliczaniem(string s1, string s2)
{
    int ile1[26], ile2[26];
    if(s1.size() != s2.size())
    {
        return false;
    }
    Zlicz(s1, ile1);
    Zlicz(s2, ile2);
    for(int i = 0; i < 26; i++)
    {
        if(ile1[i] != ile2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s1;
    string s2;
    cout << "Pierwsze slowo: " << endl;
    cin >> s1;
    cout << "Drugie slowo: " << endl;
    cin >> s2;
    cout << Anagramy(s1, s2) << " " << AnagramyZZliczaniem(s1, s2) << endl;
}
