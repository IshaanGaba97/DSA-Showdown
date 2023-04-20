#include <iostream>
#include<vector>
#include<algorithm> 

using namespace std;

// tc : o(2^N * target) => o(n * target)  memoization
#include <vector>
bool f(int ind, int target, vector<int> &arr, vector<vector<int>>& dp){
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);
    if(dp[ind][target] != -1) return dp[ind][target];
    bool notTake = f(ind-1, target, arr, dp);
    bool take = false;
    if(arr[ind] <= target)
    take = f(ind-1, target-arr[ind], arr, dp);
    return dp[ind][target] = take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
        
    return f(n-1, k, arr, dp);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }
    if(arr[0]<=k)
    dp[0][arr[0]] = true;

    for(int ind = 1; ind < n; ind++){
        for(int target = 1; target <= k; target++){
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind] <= target)
            take = dp[ind-1][target - arr[ind]];
            dp[ind][target] = take || notTake;
        }
    }
    return dp[n-1][k];
}