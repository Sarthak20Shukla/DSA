//Allocate Books
#include<bits/stdc++.h>

using namespace std;

int students(vector<int>& arr, int m){
    long long last=0;int stu=1;
    for(int i=0;i<arr.size();i++){
        if(last+arr[i]<=m){
            last+=arr[i];
            
        } else {
            stu++;
            last=arr[i];
        }
    }
    return stu;

}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(n<m) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2,noofstudents=students(arr,mid);
        if(noofstudents>m) low=mid+1;
        else high=mid-1;

    }
    return low;
}

int main(){

    

    return 0;
}
