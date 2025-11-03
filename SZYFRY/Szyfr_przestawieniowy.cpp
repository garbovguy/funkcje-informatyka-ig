#include <iostream>
#include <string>
using namespace std;
string przestaw(string tj, int kl){
string szyfrogram="";
int i, j;
while(tj.size()%kl!=0) tj=tj+'X';
for(j = 0; j<kl;j++)
    for(i = 0; i<tj.size()/kl; i++)
    szyfrogram+=tj[i*kl+j];
return szyfrogram;
}

string przestawIG(string tj, string kl){
string szyfrogram="";
int i, j;
while(tj.size()%kl.size()!=0) tj=tj+'X';
for(j = 0; j<kl.size();j++)
    for(i = 0; i<tj.size()/kl.size(); i++)
    szyfrogram+=tj[i*kl.size()+kl[j]-'0'];
return szyfrogram;
}

int main(){
string tj;
int kl;
cout<<"Podaj tekst: ";
getline(cin, tj);
cout<<"podaj klucz: ";
cin>>kl;
cout<<przestaw(tj, kl);
}
