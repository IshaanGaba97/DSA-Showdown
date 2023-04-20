#include <iostream>
#include<vector>
#include<algorithm> 
using namespace std;


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
    
    long long int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> temp1, temp2;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(maxNonAdjacentSum(temp1), maxNonAdjacentSum(temp2));
    }
};