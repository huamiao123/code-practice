#include<iotream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
    public:
        int maxProfit(vector<int>& prices) 
        {
            int n=prices.size();
            int dp0=0;
            int dp1=-prices[0];
            int tp0=0;
            int tp1=0;
            for(int i=1;i<n;i++)
            {
                tp0=max(dp0,dp1+prices[i]);
                tp1=max(dp1,dp0-prices[i]);
                dp0=tp0;
                dp1=tp1;
            }
            return tp0;
        }
};
int main()
{
    
}