#include <iostream>
#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> my={{1,0},{0,1},{2,0},{3,0},{4,1},{5,0},{6,1},{7,0},{8,2},{9,1}};
int test(int n)
{
  int sum=0;
  while(n)
  {
    sum+=my[n%10];
    n/=10;
  }
  return sum;
}
int main()
{

  int n=0;
  cin>>n;
  vector<int> vec(n);
  for(int i=0;i<n;i++)
    cin>>vec[i];
  sort(vec.begin(),vec.end(),[](int a,int b)
  {
    int as=test(a);
    int bs=test(b);
    if(as!=bs) return as<bs;
    else return a<b;
  });
  for(auto it:vec) 
    cout<<it<<" ";
  return 0;
}