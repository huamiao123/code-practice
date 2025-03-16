#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
    public:
    typedef pair<string,int> PSI;
    struct com
    {
        bool operator()(PSI p1,PSI p2)
        {
            if(p1.second!=p2.second)
                return p1.second>p2.second;
            return p1.first<p2.first;
        }
    };
        vector<string> topKFrequent(vector<string>& words, int k) {
            vector<string> ret;
            priority_queue<PSI,vector<PSI>,com> q;
            unordered_map<string,int> my;
            for(auto it:words)
                my[it]++;
            for(auto it:my)
            {
                q.push(it);
                if(q.size()>k) q.pop();
            }
            while(!q.empty())
            {
                ret.push_back(q.top().first);
                q.pop();
            }
            reverse(ret.begin(),ret.end());
            return ret;
        }
};

int main()
{
    vector<string> vec={"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> ret;
    Solution so;
    ret=so.topKFrequent(vec,2);
    for(auto it:ret)
        cout<<it<<" ";
    return 0;
}