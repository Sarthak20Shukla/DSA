//rotate matrix by 90 degree
#include<bits/stdc++.h>

using namespace std;
void rotateMatrixoptimal(vector<vector<int>> &mat){
	// Write your code here.
	int n=mat.size();
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			swap(mat[i][j],mat[j][i]);
		}
	}
	for(int i=0;i<n;i++){
		reverse(mat[i].begin(),mat[i].end());
	}
}
void rotateMatrixbruteforce(vector<vector<int>> &mat){
	// Write your code here.
	int n=mat.size();
    int ans[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans[i][n-1-i]=mat[i][j]
		}
	}
}
int main(){

    

    return 0;
}
