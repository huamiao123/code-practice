#include<vector>
#include<iostream>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<int> dp0(n),dp1(n);
            dp0[0]=0;
            dp1[0]=-prices[0];
            for(int i=1;i<n;i++)
            {
                dp0[i]=max(dp0[i-1],dp1[i-1]+prices[i]);
                dp1[i]=max(dp1[i-1],dp0[i-1]-prices[i]);
            }
            return dp0[n-1];
        }
    };
