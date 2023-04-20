// f(n) = f(n-1) + f(n-2) and start from n, in base case return 1 for n=0,1
#include <iostream>
#include<vector>
#include<algorithm> 
using namespace std;


class Solution {
public:
    int f(int n, vector<int> &dp){
    if(n <= 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1, dp) + f(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};