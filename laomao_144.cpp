#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n=0;
    int m=0;
    cin>>n>>m;
    vector<int> vec(n+1);
    for(int i=1;i<=n;i++)
        cin>>vec[i];
    for(int i=2;i<=n;i++)
        vec[i]+=vec[i-1];
    while(m--)
    {
        int i=0;
        int j=0;
        cin>>i>>j;
        cout<<vec[j]-vec[i-1]<<endl;
    }
    return 0;
}