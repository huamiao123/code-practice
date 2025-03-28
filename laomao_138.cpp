#include <iostream>
using namespace std;

int main()
{
  int a[200][200]={0};
  int n=0;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=i;j++)
    {
      cin>>a[i][j];
    }
  }
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=i;j++)
      a[i][j]+=max(a[i-1][j],a[i-1][j-1]);
  }
  cout<<max(a[n][(n+1)/2],a[n][(n+2)/2]);

  return 0;
}