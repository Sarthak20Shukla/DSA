//Network Delay Time
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }


     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
     pq.push({k,0});
     vector<int> dist(n+1,1e9);
     dist[k]=0;
     while(!pq.empty()){
        int node=pq.top().first;
        int time=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int node2=it.first;
            int wt=it.second;
            if(wt+time<dist[node2]){
                dist[node2]=wt+time;

                pq.push({node2,wt+time});
            }
        }

     }
     int mx=*max_element(dist.begin()+1,dist.end());
     return mx==1e9 ?-1:mx;
    }
};