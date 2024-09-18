class Solution {
public:
    static bool comp(string a,string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums) {
        string ans="";
        int n=nums.size();
        vector<string> anss;
        for(int i=0;i<n;i++){
            anss.push_back(to_string(nums[i]));
        }
        sort(anss.begin(),anss.end(),comp);
        if(anss[0]=="0"){
            return "0";
        }
        for(auto it:anss){
            ans+=it;
        }
        return ans;

        
    }
};