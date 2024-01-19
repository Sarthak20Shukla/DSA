//Merge Sorted Arrays Without Extra Space
#include<bits/stdc++.h>

using namespace std;
void mergeTwoSortedArraysWithoutExtraSpaceoptimal1(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int n=a.size(),m=b.size();
	int left=n-1,right=0;
	while (left >= 0 && right < m) {
        if (a[left] > b[right]) {
            swap(a[left], b[right]);
            left--, right++;
        }
        else {
            break;
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(), b.end());
}


void swaps(vector<long long> &a, vector<long long> &b,int ind1,int ind2){
	if(a[ind1]>b[ind2]){
		swap(a[ind1],b[ind2]);
	}
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int n=a.size(),m=b.size();
	int len=n+m;
	int gap=(len/2)*(len%2);
	while(gap>0){
		int left=0,right=left+gap;
		while(right<len && right>=n){
		if(left<len){
			swaps(a,b,left,right-n);
		}
		else if(left>=n){
			swaps(b,b,left-n,right-n);
                } else {
                        swaps(a, a, left, right);
                }
                left++;
                right++;
                }
                if (gap == 1)
                break;
                gap = (gap / 2) * (gap % 2);
        }
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}