class Solution {
public:
    int countPairDistance(vector<int>& nums, int k){
        int n=nums.size();
        int count=0;
        int i=0;


        for(int j=1;j<n;++j){
            while(nums[j] - nums[i] > k){ i++ ;}
            count+=(j-i);
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int r=nums[n-1]-nums[0];
        while(l<r){
            int mid=l+ (r-l)/2;
            if(countPairDistance(nums,mid)<k){
                l=mid+1;
            } else {
                r=mid;
            }
        }
        return l;
    }
};