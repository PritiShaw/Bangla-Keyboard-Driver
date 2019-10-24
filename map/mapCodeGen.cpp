#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int main(){
    fstream f;
    f.open("shift.csv");
    while(f){
        string s;
        f>>s;
        int pos =s.find(',');
        string s1=s.substr(0,pos);
        string s2=s.substr(pos+1,s.length()-(pos+1));
        if(s1.length()>0)
          cout<<"\tunimap_shift[\""<<s2<<"\"]="<<'"'<<s1<<'"'<<';'<<endl;
    }
    f.close();
    f.open("unshift.csv");
    while(f){
        string s;
        f>>s;
        int pos =s.find(',');
        string s1=s.substr(0,pos);
        string s2=s.substr(pos+1,s.length()-(pos+1));
        if(s1.length()>0)
          cout<<"\tunimap_unshift[\""<<s2<<"\"]="<<'"'<<s1<<'"'<<';'<<endl;
    }
    f.close();
}