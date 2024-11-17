class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ssl=INT_MAX;
        long long sum=0;
        priority_queue<pair<long long,int>,vector<pair<long long, int>>,greater<>> heap;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=k) ssl=min(ssl,i+1);
            while(!heap.empty() && sum-heap.top().first>=k){
                ssl=min(ssl,i-heap.top().second);
                heap.pop();
            }
                        heap.emplace(sum, i);

        }
        return ssl==INT_MAX?-1:ssl;
    }
};