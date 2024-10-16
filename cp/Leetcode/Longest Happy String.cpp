class Solution {
public:
    
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>,vector<pair<int,char>>> pq;
        string ans="";
        if(a>0){
            pq.push({a,'a'});
        }if(b>0){
            pq.push({b,'b'});
        }if(c>0){
            pq.push({c,'c'});
        }
        while(!pq.empty()){
            int currcount=pq.top().first;
            char currchar=pq.top().second;
            pq.pop();
            if(ans.length()>=2 && ans[ans.length()-1]==currchar && ans[ans.length()-2]==currchar){
                if(pq.empty()) break;

                int nextcount=pq.top().first;
                char nextchar=pq.top().second;
                pq.pop();
                ans.push_back(nextchar);
                nextcount--;
                if(nextcount>0) {
            pq.push({nextcount,nextchar});
        }


            } else{
                 currcount--;
                    ans.push_back(currchar);
                   
            }

        if(currcount>0) {
            pq.push({currcount,currchar});
        }
        }
        return ans;
    }
};