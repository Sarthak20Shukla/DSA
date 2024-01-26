// Koko Eating Bananas

#include<bits/stdc++.h>

using namespace std;

long long maxhrs(vector<int> &v, int h){
    long long totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(h));
    }
    return totalH;
}
int minimumRateToEatBananas(vector<int> v, int h) {
    // Write Your Code Here
         long long low=1,high=*max_element(v.begin(),v.end());
    while(low<=high){
        long long mid=(low+high)/2;
        long long totalhrs=maxhrs(v,mid);
        if(totalhrs<=h){
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    return low;
}

int main(){

    

    return 0;
}
