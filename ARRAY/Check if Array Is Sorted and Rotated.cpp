//Check if Array Is Sorted and Rotated
#include<bits/stdc++.h>
using namespace std;


int main(){
int count=0;
int n=nums.size();
for(int i=0;i<nums.size();i++){
    if(nums[i-1]>nums[i]){
  count++;
    }
}if(nums[n-1]>nums[0]) count++;
return count=1;

    return 0;
}