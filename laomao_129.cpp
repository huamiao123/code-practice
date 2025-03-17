#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution
{
    typedef pair<int,int> PII;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        queue<PII> q;
        int maxs=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int ret=0;
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    grid[i][j]=0;
                    ret++;
                    while(!q.empty())
                    {
                        auto [a,b]=q.front();
                        q.pop();
                        for(int k=0;k<4;k++)
                        {
                            int x=a+dx[k];
                            int y=b+dy[k];
                            if(x>=0&&x<m&&y>=0&&y<n&&grid[x][y]==1)
                            {
                                q.push({x,y});
                                grid[x][y]=0;
                                ret++;
                            }
                        }
                    }
                }
                maxs=max(maxs,ret);
            }
        }
        return maxs;
    }
};
int main()
{
    vector<vector<int>> vec={{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},
                            {0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},
                            {0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},
                            {0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<13;j++)
            cout<<vec[i][j]<<" ";
        cout<<endl;
    }
    Solution so;
    cout<<so.maxAreaOfIsland(vec);
    return 0;
}