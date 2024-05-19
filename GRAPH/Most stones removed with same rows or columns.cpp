//Most stones removed with same rows or columns
class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrows=0;
        int maxcols=0;
        for(auto it:stones){
            maxrows=max(maxrows,it[0]);
            maxcols=max(maxcols,it[1]);
        }
        DisjointSet ds(maxrows+maxcols+1);
        unordered_map<int,int> stonenodes;
        for(auto it: stones){
            int nodeRow=it[0];
            int nodeCol=it[1]+maxrows+1;
            ds.unionBySize(nodeRow,nodeCol);
            stonenodes[nodeRow]=1;
            stonenodes[nodeCol]=1;

        }
        int cnt=0;
        for(auto it: stonenodes){
            if(ds.findUPar(it.first)==it.first) cnt++;
        }
        return n-cnt;
    }
};