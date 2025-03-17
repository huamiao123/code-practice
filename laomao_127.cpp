#include<queue>
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    typedef pair<int,int> PII;
    vector<int> dx={0,0,1,-1};
    vector<int> dy={1,-1,0,0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int prev=image[sr][sc];
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> wrt(m,vector<int>(n,0));
        queue<PII> q;
        q.push(make_pair(sr,sc));
        while(q.size())
        {
            auto [a,b]=q.front();
            q.pop();
            if(wrt[a][b]==0)
            {
                image[a][b]=color;
                wrt[a][b]=1;
                for(int i=0;i<4;i++)
                {
                    int x=a+dx[i];
                    int y=b+dy[i];
                    if(x>=0&&x<m&&y>=0&&y<n&&image[x][y]==prev)
                        q.push({x,y});
                }
            }
        }
        return image;
    }
};

int main()
{
    vector<vector<int>> vec={{1,1,1},{1,1,0},{1,0,1}};
    Solution so;
    vec=so.floodFill(vec,1,1,2);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            cout<<vec[i][j];
        cout<<endl;
    }
    return 0;
}