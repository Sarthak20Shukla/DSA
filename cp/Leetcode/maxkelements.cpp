class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum=0;
        priority_queue<int> pq(begin(nums),end(nums));
        while(k--){
             long long t=pq.top();
             pq.pop();
             sum+=t;
            long long x=ceil(t/3.0);
            pq.push(x);

        }
        return sum;
    }
};