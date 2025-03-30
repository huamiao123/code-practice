#include<iostream>
#include<vector>
using namespace std;
class NumMatrix {
    public:
        vector<vector<int>> dp;
        NumMatrix(vector<vector<int>>& matrix) {
            int n=matrix.size();
            int m=matrix[0].size();
            dp.resize(n+1,vector<int>(m+1));
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+matrix[i-1][j-1];
                }
            }
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) 
        {
            return dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
        }
    };
int main()
{
    vector<vector<int>> dp1;
    dp1.resize(2,vector<int>(2));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            cout<< dp1[i][j]<<" ";
        cout<<endl;
    }
        
    return 0;
}