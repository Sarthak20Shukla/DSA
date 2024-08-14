class KthLargest {
public:
int a;
priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        a=k;
        for(auto &it:nums){
            pq.push(it);
            if(pq.size()>a) pq.pop();

        }
        
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>a) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */