#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
    public:
    typedef pair<int,int> PII;
        int numIslands(vector<vector<char>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            vector<vector<int>> rcd(m,vector<int>(n,0));
            int dx[4]={0,0,1,-1};
            int dy[4]={1,-1,0,0};
            int ret=0;
            queue<PII> q;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(rcd[i][j]==0&&grid[i][j]=='1')
                    {
                        q.push({i,j});
                        rcd[i][j]=1;
                        while(q.size())
                        {
                            auto [a,b]=q.front();
                            rcd[a][b]=1;
                            q.pop();
                            for(int k=0;k<4;k++)
                            {
                                int x=a+dx[k];
                                int y=b+dy[k];
                                if(x>=0&&x<m&&rcd[x][y]==0&&y>=0&&y<n&&grid[x][y]=='1')
                                    q.push({x,y});
                            }
                        }
                        ret++;
                    }
                }
            }
            return ret;
        }
    };
int main()
{
    vector<vector<char>> vec={{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    Solution so;
    cout<<so.numIslands(vec);
    return 0;
}