//print lis

 vector<int> dp(n,1) , hash(n);
        int maxi = 1 , last = 0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev = 0;prev<i;prev++){
                if(nums[i]>nums[prev] && 1+dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                last = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[last]);
        while(last != hash[last]){
            last = hash[last];
            ans.push_back(nums[last]);
        }
        reverse(ans.begin() , ans.end());
        return ans;