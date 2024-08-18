class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        long long n=energyDrinkA.size();
        long long uttar;

        vector<long long> dpa(n),dpb(n);
        dpa[0]=energyDrinkA[0];
        dpb[0]=energyDrinkB[0];
        for(int i=1;i<n;i++){
            dpa[i]=max(dpa[i-1]+energyDrinkA[i],dpb[i-1]);
            dpb[i]=max(dpb[i-1]+energyDrinkB[i],dpa[i-1]);
        }
        uttar=max(dpa[n-1],dpb[n-1]);
        return uttar;
    }
};