#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream hout("sample60.txt");
    string name;
    cout<<"enter a name";
    cin>>name;
    hout<<name+" is my name";
    hout.close();
    
    
    ifstream hin("sample60.txt");
    string content;
    hin>>content;
    cout<<"the content of file is "<<content;
    hin.close();

    return 0;

}