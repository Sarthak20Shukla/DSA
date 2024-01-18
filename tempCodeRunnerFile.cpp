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
    sort(a, a + n);
    sort(b, b + m);
}


void swap(vector<long long> &a, vector<long long> &b,int ind1,int ind2){
	if(a[ind1]>b[ind2]){
		swap(a[ind1],b[ind2]);
	}
}

void mergeTwoSortedArraysWithoutExtraSpaceoptimal2(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int n=a.size(),m=b.size();
	int len=n+m;
	int gap=(len/2)*(len%2);
	while(gap>0){
		int left=0,right=left+gap;
		while(right<len && right>=n){
		if(left<len){
			swap(a,b,left,right-n);
		}
		else if(left>=n){
			swap(b,b,left-n,right-n);}
		 else {
                swap(a, a, left, right);
            }
                left++;
                right++;
                }

                if (gap == 1) break;
                gap = (len / 2) * (len % 2);
        }
}
int main()
{
    long long a[] = {1, 4, 8, 10};
    long long b[] = {2, 3, 9};
    int n = 4, m = 3;
    mergeTwoSortedArraysWithoutExtraSpaceoptimal1(a,b);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}