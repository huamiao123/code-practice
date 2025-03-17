#include<iostream>
#include<queue>
using namespace std;
class MedianFinder {
    public:
        priority_queue<int,vector<int>,less<int>> q1;
        priority_queue<int,vector<int>,greater<int>> q2;
        MedianFinder() {
            ;
        }
        
        void addNum(int num) {
            int m=q1.size();
            int n=q2.size();
            if(m==n)
            {
                if(m==0||num<=q1.top())
                    q1.push(num);
                else
                {
                    q2.push(num);
                    q1.push(q2.top());
                    q2.pop();
                }
            }
            else
            {
                if(num<=q1.top())
                {
                    q1.push(num);
                    q2.push(q1.top());
                    q1.pop();
                }
                else
                    q2.push(num);
            }
        }
        
        double findMedian() {
            int m=q1.size();
            int n=q2.size();
            if(m>n)
                return q1.top();
            else
                return (q1.top()+q2.top())/2.0;
        }
    };

int main()
{
    MedianFinder m;
    m.addNum(1);
    cout<<m.findMedian()<<endl;
    m.addNum(2);
    cout<<m.findMedian()<<endl;
    m.addNum(3);
    cout<<m.findMedian()<<endl;
    return 0;
}