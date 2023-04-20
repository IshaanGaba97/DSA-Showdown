#include <iostream>
#include<vector>
#include<algorithm> 

using namespace std;

class Solution {
public:
    int maxNonAdjacentSum(int i, vector<int>& nums, vector<int>& dp){
        if(i == 0) return nums[0];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = maxNonAdjacentSum(i-2, nums, dp) + nums[i];
        int notPick = maxNonAdjacentSum(i-1, nums, dp) + 0;

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return maxNonAdjacentSum(n-1, nums, dp);
    }
};


//tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            int pick = nums[i];
            if(i > 1){
                pick += dp[i-2];
            }
            int notPick = dp[i-1] + 0;
            dp[i] = max(pick, notPick);
        }
        return dp[n-1];
    }
};


//space optimization
class Solution {
public:
    int maxNonAdjacentSum(vector<int>& nums){
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i = 1; i < n; i++){
            int take = nums[i];
            if(i > 1) take += prev2;
            int nontake = 0 + prev;
            
            int curri = max(take, nontake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        return maxNonAdjacentSum(nums);
    }
};