#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    unordered_map<int,int> my;
    vector<int> vec(7);
    int n=0;
    cin>>n;
    for(int i=0;i<7;i++)
        cin>>vec[i];
    vector<int> m(7);
    for(int k=0;k<n;k++)
    {
        int count=7;
        for(int i=0;i<7;i++)
        {
        cin>>m[i];
        if(find(vec.begin(),vec.end(),m[i])!=vec.end())
        {
            count--;
        }
        }
        my[count]++;
    }
    for(int i=0;i<7;i++)
        cout<<my[i]<<" ";
    return 0;
}