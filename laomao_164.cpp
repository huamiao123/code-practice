#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<vector<int>> ret;
        vector<int> path;
        bool check[3];
        vector<vector<int>> permute(vector<int>& nums) {
            dfs(nums);
            return ret;
        }
       void dfs(vector<int> nums)
       {
            if(path.size()==nums.size())
                ret.push_back(path);
            else
            {
                for(int i=0;i<nums.size();i++)
                {
                    if(check[i]==false)
                    {
                        path.push_back(nums[i]);
                        check[i]=true;
                        dfs(nums);
                        path.pop_back();
                        check[i]=false;
                    }
                }
            }
       }
    };
int main()
{
    Solution so;
    vector<int> vec={1,2,3};
    for(auto it: so.permute(vec))
    {
        for(auto num:it)
            cout<<num<<" ";
        cout<<endl;
    }
}
//https://leetcode.cn/problems/VvJkup/solutions/