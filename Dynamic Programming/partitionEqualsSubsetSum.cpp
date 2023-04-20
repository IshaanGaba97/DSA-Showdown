#include <iostream>
#include<vector>
#include<algorithm> 

using namespace std;
// same as subsets sum equals k
class Solution {
public:
    bool f(int ind, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return (nums[ind] == target);

        if(dp[ind][target] != -1) return dp[ind][target];

        int nt = f(ind-1, target, nums, dp);
        int t = false;
        if(target >= nums[ind]){
            t = f(ind-1, target-nums[ind], nums, dp);
        }

        return dp[ind][target] = t || nt;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }
        if(totalSum % 2 == 1) return false;

        int s = totalSum/2;

        vector<vector<int>> dp(n, vector<int>(s+1, -1));
        int ans = f(n-1, s, nums, dp);
        return ans==1? true : false;
    }
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2){return false;}
        sum/=2;
        vector<vector<bool>>dp(nums.size(), vector<bool>(sum+1, false));
        for(int i=0; i<nums.size()-1; i++){
            dp[i][0]=true;
        }
        if(nums[0]<sum){dp[0][nums[0]]=true;}
        for(int i=1; i<nums.size(); i++){
            for(int j=1; j<=sum; j++){
                bool nt=dp[i-1][j];
                bool t=false;
                if(nums[i]<=j){
                    t=dp[i-1][j-nums[i]];
                }
                dp[i][j]=(t|nt);
            }
        }
        return dp[nums.size()-1][sum];
    }
};