#include<iostream>
#include<limits>
using namespace std;
int main()
{
    int n=0;
    int global_min=1;
    int global_max=INT_MAX;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        int min_v=a/(b+1)+1;
        int max_v=a/b;
        global_min=max(global_min,min_v);
        global_max=min(global_max,max_v);
    }
    cout<<global_min<<" "<<global_max;
}