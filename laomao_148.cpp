#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
    int T=0;
    cin>>T;
    while(T--)
    {
        int n=0,m=0,k=0;
    cin>>n>>m>>k;
    ll total=0;
    vector<vector<ll>> vec(n+1,vector<ll>(m+1));
    vector<vector<ll>> pre(n+1,vector<ll>(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {   
            cin>>vec[i][j];
            total+=vec[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)   
            pre[i][j]=vec[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];

        
    if(total<k+1)
    {
        cout<<-1<<endl;
        continue;
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vec[i][j]==0) continue;
            if(vec[i][j]>=k+1)
            {
                ans=min(ans,0);
            }
            int low=0;
            int high=(n+m)*2;
            while(low<=high)
            {
                int mid=(low+high)>>1;
                int a=max(1,i-mid);
                int b=max(1,j-mid);
                int c=min(n,i+mid);
                int d=min(m,j+mid);
                int current=pre[c][d]-pre[c][b-1]-pre[a-1][d]+pre[a-1][b-1];
                if(current>=k+1)
                {
                    ans=min(mid,ans);
                    high=mid-1;
                }
                else
                    low=mid+1;
                
            }
        }
    }
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
    }
    return 0;
}