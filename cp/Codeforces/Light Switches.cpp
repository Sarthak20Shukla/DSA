#include<bits/stdc++.h>

using namespace std;

bool funBrahma(int value , vector < int > &value_array , int k)
{
    for(int i = 0; i < value_array.size(); i++)
    {
        int difference = value - value_array[i];
        int Uttar = difference/ k;
        if(Uttar % 2 == 1) return false;
        if(value >= value_array[i] + Uttar * k && value <= value_array[i] + (Uttar + 1) * k)
        {
            continue;
        }
        else return 0;
    }
    return true;
}

int main()
{
   
    int teStShiv; cin >> teStShiv;
    while(teStShiv--)
    {
        int numbbb , k;
        cin >> numbbb >> k;
        vector < int > origiNAl_Array(numbbb);
        for(int i = 0; i < numbbb; i++)  cin >> origiNAl_Array[i];
        
        sort(origiNAl_Array.begin() , origiNAl_Array.end());
         bool flaGGGG = 0;
        for(int i = origiNAl_Array[numbbb - 1]; i <= origiNAl_Array[numbbb - 1] + k; i++)
        {
            bool flag = funBrahma(i , origiNAl_Array , k);
            if(flag)
            {
                cout << i << endl;
                flaGGGG = 1;
                break;
            }
        }
        if(!flaGGGG)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}