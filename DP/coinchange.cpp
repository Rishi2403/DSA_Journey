#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minCoins(int n , vector<int> &a,vector<int> &dp){

    if (n==0) return 0;

    int ans=INT8_MAX;
    
    for(int i=0;i<a.size();i++){
        if (n-a[i]>=0){
            
            int subAns=0;
            if(dp[n-a[i]] != -1){
                subAns=dp[n-a[i]];
                dp.push_back()
            }else{
                 subAns=minCoins(n-a[i],a,dp);
            }
            
            if(subAns !=INT8_MAX && subAns+1<ans){
                ans=subAns+1;
            }
        }
    }    
    return dp[n]=ans;
}

int main()
{
    int n=18;
    vector<int> a={7,5,1};
    vector<int> dp(n+1,-1);
    dp[0]=0;
    int ans=minCoins(n,a,dp);
    cout<<ans;
     for (int i = 0; i < dp.size(); ++i) {
        std::cout << "dp[" << i << "] = " << dp[i] << std::endl;
    }

    return 0;
}



// #include <iostream>
// #include <vector>
// #include <climits> // For INT_MAX
// #include <algorithm> // For std::fill

// using namespace std;

// int minCoins(int n, vector<int>& a, vector<int>& dp) {
//     if (n == 0) return 0;

//     int ans = INT_MAX;

//     for (int i = 0; i < a.size(); i++) {
//         if (n - a[i] >= 0) {
//             int subAns = 0;
//             if (dp[n - a[i]] != -1) {
//                 subAns = dp[n - a[i]];
//             } else {
//                 subAns = minCoins(n - a[i], a, dp);
//             }
//             if (subAns != INT_MAX && subAns + 1 < ans) {
//                 ans = subAns + 1;
//             }
//         }
//     }
//     return dp[n] = ans;
// }

// int main() {
//     int n = 18;
//     vector<int> a = {7, 5, 1};

//     vector<int> dp(n + 1, -1);
//     dp[0] = 0;

//     int ans = minCoins(n, a, dp);
//     cout << ans << endl;

//     for (int x : dp) {
//         cout << x << " ";
//     }

//     return 0;
// }
