#include<iostream>
#include<queue>
using namespace std;
class Solution
{
public:
    typedef pair<int,int> PII;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        queue<PII> q;
        int count=0;
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>> visit(m,vector<int>(n));
        q.push({entrance[0],entrance[1]});
        visit[entrance[0]][entrance[1]]=1;
        while(1)
        {
            vector<PII> vec;
            while(!q.empty())
            {
            auto [a,b]=q.front();
            q.pop();
            for(int j=0;j<4;j++)
            {
                int x=a+dx[j];
                int y=b+dy[j];
                if(x>=0&&x<m&&y>=0&&y<n&&maze[x][y]=='.'&&visit[x][y]==0)
                {
                    if(x==0||x==m-1||y==0||y==n-1)
                        return ++count;
                    vec.push_back({x,y});
                    visit[x][y]=1;
                }
            }
            }
            if(vec.size()==0) return -1;
            else
            {
                count++;
                for(int k=0;k<vec.size();k++)
                    q.push(vec[k]);
            }
        }
    }
};
int main()
{
    vector<vector<char>> vec={{'+','+','+'},{'.','.','.'},{'+','+','+'}};
    vector<int> en={1,0};
    Solution so;
    cout<<so.nearestExit(vec,en);
    return 0;
}