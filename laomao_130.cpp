#include<iostream>
#include<vector>
const int Max_num=9e5+10;
using namespace std;
int main()
{
    int n=0;
    cin>>n;
    vector<int> vec(n);
    unordered_map<int,int> my={{0,1}};
    vector<int> squres;
    for(int i=0;i<n;i++);
    {
        cin>>vec[i];
    }
    for(int k=0;k*k<=Max_num;k++)
        squres.push_back(k*k);
    for(int i=1;i<n;i++)
        vec[i]+=vec[i-1];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int current=vec[i];
        for(auto it:squres)
        {
            int target=current-it;
            if(target>=0)
                ans+=my[target];
        }
        my[current]++;
    }
    cout<<ans;
}