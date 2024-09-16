class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int> minutes(n);
        for(int i=0;i<timePoints.size();i++){
            int h=stoi(timePoints[i].substr(0,2));
            int m=stoi(timePoints[i].substr(3));
            minutes[i]=h*60+m;

        }
        sort(minutes.begin(),minutes.end());
        int mini=INT_MAX;
        for(int i=0;i<minutes.size()-1;++i){
            mini=min(mini,minutes[i+1]-minutes[i]);
        }
        mini=min(mini,24*60-minutes.back()+minutes.front());

        return mini;

    }
};