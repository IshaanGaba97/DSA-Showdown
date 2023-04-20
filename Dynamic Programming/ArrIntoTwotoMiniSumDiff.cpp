#include <iostream>
#include<vector>
#include<algorithm> 
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;

        for (int i = 0; i < n; i++) {
            totSum += nums[i];
        }

        vector < vector < bool >> dp(n, vector < bool > (totSum + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if (nums[0] <= totSum)
            dp[0][totSum] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= totSum; target++) {

            bool notTaken = dp[ind - 1][target];

            bool taken = false;
            if (nums[ind] <= target)
                taken = dp[ind - 1][target - nums[ind]];

            dp[ind][target] = notTaken || taken;
            }
        }

        int mini = 1e9;
        for (int i = 0; i <= totSum; i++) {
            if (dp[n - 1][i] == true) {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
            }
        }
        return mini;
       }
};
