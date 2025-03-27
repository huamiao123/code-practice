#include<iostream>
#include<vector>
using namespace std;
int main()
{
    bool check=false;
    string m,n;
    cin>>m;
    cin>>n;
    if(m[0]=='-') m=m.substr(1);
    if(n[0]=='-') n=n.substr(1);
    if(m.size()<n.size()||(m.size()==n.size()&&m<n)) {swap(m,n);check=true;}
    vector<int> a,b,ret;
    int c[10000]={0};
    int d[10000]={0};
    for(int i=m.size()-1;i>=0;i--) a.push_back(m[i]-'0');
    for(int i=n.size()-1;i>=0;i--) b.push_back(n[i]-'0');
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {
            c[i+j]+=a[i]*a[j];
            c[i+j+1]+=c[i+j]/10;
            c[i+j]%=10;
        }
    }
    int glo=1000;
    while(c[glo]==0&&glo>=1) glo--;
    for(int i=0;i<b.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            d[i+j]+=b[i]*b[j];
            d[i+j+1]+=d[i+j]/10;
            d[i+j]%=10;
        }
    }
    int t=0;
    for(int i=0;i<=glo;i++)
    {
        t=t+c[i]-d[i];
        ret.push_back((t+10)%10);
        if(t>=0) t=0;
        else t=-1;
    }
    while(ret.back()==0&&ret.size()>0) ret.pop_back();
    if(check) cout<<'-';
    for(int i=ret.size()-1;i>=0;i--) cout<<ret[i];
    return 0;
}