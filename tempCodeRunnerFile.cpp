// 

#include<bits/stdc++.h>

using namespace std;
string getnumbers(string &userInput){
unordered_map<string,string> mp={{"one","1"},{"two","2"},{"three","3"},{"four","4"},{"five","5"},{"six","6"},{"seven","7"},{"eight","8"},{"nine","9"},{"zero","0"},{"double","2"},{"triple","3"}};
string res="";
int i=0;
stringstream ss(userInput);
string word="";
vector<string> arr;
while(ss>>word){
    arr.push_back(word);
}
while(i<arr.size()){
    string val=mp[arr[i]];
    if(arr[i]=="double"){
        val=mp[arr[i+1]]+mp[arr[i+1]];
        i+=2;
    } else if(arr[i]=="triple"){
        val=mp[arr[i+1]]+mp[arr[i+1]]+mp[arr[i+1]];
        i+=2;
    } else i+=1;
    res+=val;
}

return res;
}

int main(){


    string userInput;
    getline(cin,userInput);
    string result=getnumbers(userInput);
    cout<<result<<endl;

    return 0;
}
