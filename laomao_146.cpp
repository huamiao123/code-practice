#include <iostream>
#include<vector>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n=0;
  int m=0;
  int l=0;
  cin>>n>>m>>l;
  int ret=0;
  vector<vector<int>> vec(n+1,vector<int>(m+1));
  vector<vector<int>> dp(n+1,vector<int>(m+1));
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
      cin>>vec[i][j];
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+vec[i][j];
  for(int i=1;i<=min(n,m);i++)
  {
    for(int j=i;j<=n;j++)
    {
      for(int k=i;k<=m;k++)
      {
        if(i*i-(dp[j][k]-dp[j][k-i]-dp[j-i][k]+dp[j-i][k-i])==l)
          ret++;
      }
    }
  }
  cout<<ret;
  return 0;
}