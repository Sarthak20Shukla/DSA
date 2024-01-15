// Count All Subarrays With Given Sum
#include<bits/stdc++.h>

using namespace std;
int findAllSubarraysWithGivenSumoptimal(vector < int > & arr, int k) {
    // Write Your Code Here
    int presum=0,cnt=0;
    map<int,int>mpp;
    mpp[0]=1;
    for(int i=0;i<n;i++){
        presum+=arr[i];
        int remove=presum-k;
        cnt+=mpp[remove];
        mpp[presum]+=1;
    }
    return cnt;
}
int findAllSubarraysWithGivenSumbetter(vector < int > & arr, int k) {
    // Write Your Code Here
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int s=0;
            s+=arr[j];
            if(s==k) cnt++;
        }
    }
    return cnt;
}
int findAllSubarraysWithGivenSumbruteforce(vector < int > & arr, int k) {
    // Write Your Code Here
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int s=0;
            for(int k=i;k<j;k++)
              s+=arr[k];
            if(s==k) cnt++;
        }
    }
    return cnt;
}

int main(){

    

    return 0;
}
