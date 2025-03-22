#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    typedef pair<int,int> PII;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    void bfs(vector<vector<char>>& vec,int x,int y)
    {
        int m=vec.size();
        int n=vec[0].size();
        queue<PII> q;
        q.push({x,y});
        vec[x][y]=';';
        while(!q.empty())
        {
            auto [a,b]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int x1=a+dx[i];
                int y1=b+dy[i];
                if(x1>=0&&x1<m&&y1>=0&&y1<n&&vec[x1][y1]=='O')
                {
                    q.push({x1,y1});
                    vec[x1][y1]=';';
                }
            }
        }
    }
    void solve(vector<vector<char>>& board)
    {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O') bfs(board,0,i);
            if(board[m-1][i]=='O') bfs(board,m-1,i);
        }
        for(int i=1;i<m-1;i++)
        {
            if(board[i][0]=='O') bfs(board,i,0);
            if(board[i][n-1]=='O') bfs(board,i,n-1);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                board[i][j]='X';
                if(board[i][j]==';')
                board[i][j]='O';
            }
        }
    }
};