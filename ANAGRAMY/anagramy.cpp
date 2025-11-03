#include <iostream>
#include <fstream>
using namespace std;
void sortuj(string &s){
int i, j, m;
char ch;
for(i=0; i<s.size()-1; i++){
    m=i;
    for(int j = i+1; j<s.size(); j++)
        if(s[j]<s[m]) m=j;
    ch=s[i];
    s[i] = s[m];
    s[m] = ch;
}
}
bool anagramy(string s1, string s2){
if(s1.size() != s2.size())
   return false;
sortuj(s1); sortuj(s2);
return(s1==s2);
}
int main(){
string s1 = "";
string s2 = "";
string s[1000];
ifstream wejscie("slowa.txt");
int i = 0;
while(!wejscie.eof()){
    getline(wejscie, s[i]);
    i++;
}
for(int j = 0; j<1000; j++){
    cout<<s[j]<<endl;
}
wejscie.close();
}
