#include <iostream>
#include <string>
#include <fstream>
using namespace std;


const string alfabet_m="aąbcćdeęfghijklłmnńoópqrsśtuvwxyzźż";
const string alfabet_w="AĄBCĆDEКFGHIJKLŁMNŃOÓPQRSŚTUVWXYZŹŻ";
char cezar_pl(char znak, int klucz){
    int i = alfabet_m.find(znak);
    if(i>=0 && i<35){
        i=(i+klucz)%35;
        return alfabet_m[i];
}
    i=alfabet_w.find(znak);
    if(i>=0 && i<35){
        i=(i+klucz)%35;
        return alfabet_w[i];
}
return znak;
}
string cezar(string s, int klucz){
string szyfrogram="";
for(int i = 0; i<s.size(); i++){
    szyfrogram=szyfrogram+cezar_pl(s[i], klucz);
}
cout<<szyfrogram;
}




int main(){


ifstream wejscie("tekst-jawny.txt");
    ofstream wyjscie("szyfrogram.txt");
    string s;
    int klucz;
    cout<<"Klucz: ";
    cin>>klucz;
    while(!wejscie.eof()){
        getline(wejscie, s);
        wyjscie<<cezar(s,klucz)<<endl;
    }
    wejscie.close();
    wyjscie.close();
    cout<<"Plik szyfrogram.txt zostal utworzony"<<endl;



/*          Najprostsza wersja, ale tylko litery łacińskie + duże
string t_jawny, szyfrogram = "";
int i, klucz, kod;
cout<<"Tekst jawny : ";
cin>>t_jawny;
cout<<"Klucz: ";
cin>>klucz;
for(int i = 0; i < t_jawny.size(); i++){
    kod = t_jawny[i]+klucz;
    if(kod>'Z')
        kod=kod-26;
    szyfrogram+=char(kod);
}
cout<<"szyfrogram: "<<szyfrogram;
*/
}
