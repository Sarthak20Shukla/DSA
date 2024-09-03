class Solution {
public:
    int getLucky(string s, int k) {
        //convert
        string num="";
        for(char ch:s){
            num+=to_string(ch-'a'+1);
        }
        //transform
        while(k>0){
            int temp=0;
            for(char x:num){
                temp+=x-'0';
            }
            num=to_string(temp);
            k--;
        }
        return stoi(num);
        
    }
};  