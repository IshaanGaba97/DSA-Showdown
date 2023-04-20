#include <iostream>
#include<vector>
#include<algorithm> 
using namespace std;


int f(int ind, vector<int> &dp, vector<int> &heights){
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int left = f(ind-1, dp, heights) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    if(ind > 1)
    right = f(ind-2, dp, heights) + abs(heights[ind] - heights[ind-2]);

    return dp[ind] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return f(n-1, dp, heights);
}


// tabulation
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int ind = 1; ind <= n-1; ind++){
        int left = dp[ind-1] + abs(heights[ind] - heights[ind-1]);
        int right = INT_MAX;
        if(ind > 1)
        right = dp[ind-2] + abs(heights[ind] - heights[ind-2]);
        dp[ind] = min(left,right);
    }
    return dp[n-1];
}

//space optimization
int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;
    for(int ind = 1; ind <= n-1; ind++){
        int left = prev1 + abs(heights[ind] - heights[ind-1]);
        int right = INT_MAX;
        if(ind > 1)
        right = prev2 + abs(heights[ind] - heights[ind-2]);
        int curr = min(left,right);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

