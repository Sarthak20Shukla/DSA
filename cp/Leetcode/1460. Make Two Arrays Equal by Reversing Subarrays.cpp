//approach 1
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto &it : target){
            mp[it]++;
        }
        for(auto &num:arr){
            if(mp.find(num)==mp.end()) return false;
            mp[num]--;
            if(mp[num]==0) mp.erase(num);
        }
        return (mp.size()==0);
    }
};

//approach2
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i]!=target[i]){
                return false;
            }
        }
        return true;
        
    }
};