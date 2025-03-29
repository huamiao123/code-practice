#include<bits/stdc++.h>
#include<sstream>
using namespace std;
int a[100100]={0};
int main()
{
  int n=0;
  cin>>n;
  cin.ignore();
  int ml=0;
  int ret=0;
  int min_val=INT_MAX;
  int max_val=0;
  for(int i=0;i<n;i++)
  {
    string s;
    getline(cin,s);
    int num=0;
    stringstream ss(s);
    while(ss>>num)
    {
      if(num<min_val) min_val=num;
      if(num>max_val) max_val=num;
      a[num]++;
    }
  }
  for(int i=min_val;i<=max_val;i++)
  {
    if(a[i]==0) ret=i;
    if(a[i]==2) ml=i;
  }
  cout<<ret<<" "<<ml;
  return 0;
}