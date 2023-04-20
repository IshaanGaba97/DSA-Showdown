// f(n) = f(n-1) + f(n-2) and use 3 pointer for space optimization

#include <iostream>
#include <vector>
using namespace std;

int f(int n, vector<int> &dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1, dp) + f(n-2, dp);
}
int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << f(n, dp);
}


//Tabulation 
int main() {
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    // base cases
    dp[0] = 0;  
    dp[1] = 1;
    // changing parameter is n
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
}


// space optimization
int main() {
        int n;
        cin >> n;
        vector<int> dp(n+1, -1);
        // 2 previous values needed only
        int prev2 = 0;  
        int prev1 = 1;

        for(int i = 2; i <= n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr; 
        }
        cout << prev1;
    }