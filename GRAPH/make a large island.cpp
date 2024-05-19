//make a large island
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
bool isValid(int newr,int newc,int n){
    return (newr>=0 && newr<n && newc>=0 && newc<n);
}
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0){
                    continue;
                }
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                for(int i=0;i<4;i++){
                    int newr=row+dr[i];
                    int newc=col+dc[i];
                    if(isValid(newc,newr,n) && grid[newr][newc]==1){
                        int nodeno=row*n+col;
                        int adjno=newr*n+newc;
                        ds.unionBySize(nodeno,adjno);
                    }
                }
            }
            
        }
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                    continue;
                }
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                set<int> components;
                for(int i=0;i<4;i++){
                    int newr=row+dr[i];
                    int newc=col+dc[i];
                    if(isValid(newr,newc,n)){
                        if(grid[newr][newc]==1){
                            components.insert(ds.findUPar(newr*n+newc));
                        }
                    }
                }
                int sizetotal=0;
                for(auto it:components){
                    sizetotal+=ds.size[it];

                }
                mx=max(mx,sizetotal+1);
            }
            }
            for(int i=0;i<n*n;i++){
                mx=max(mx,ds.size[ds.findUPar(i)]);
            }
            return mx;
    }
};
