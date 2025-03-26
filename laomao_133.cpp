#include <iostream>
#include<unordered_map>
using namespace std;
int main()
{
  // 请在此输入您的代码
  unordered_map<string,int> my={{"零",13},{"一",1},{"二",2},{"三",3},{"四",5},{"五",4},{"六",4},{"七",2},{"八",2},{"九",2}};
  unordered_map<int,string> my1={{0,"零"},{1,"一"},{2,"二"},{3,"三"},{4,"四"},{5,"五"},{6,"六"},{7,"七"},{8,"八"},{9,"九"}};
  unordered_map<int,int> my2={{1,31},{3,31},{5,31},{7,31},{8,31},{10,31},{12,31},{2,29},{4,30},{6,30},{9,30},{11,30}};
  int count=0;
  for(int i=2000;i<=2024;i++)
  {
    int sum1=0;
    int temp=i;
    while(temp)
    {
        sum1+=my[my1[temp%10]];
        temp/=10;
    }
    int month=0;
    month=i==2024?4:12;
    for(int j=1;j<=month;j++)
    {
      int sum2=0;
      int temp1=j;
       while(temp1)
      {
        sum2+=my[my1[temp1%10]];
        temp1/=10;
      }
      if(j<10) sum2+=13;
       if((i%4==0&&i%100!=0)||i%400==0) my2[2]=29;
       else my2[2]=28;
       int day=0;
       if(i==2024&&j==4) day=13;
       else day=my2[j];
      for(int k=1;k<=day;k++)
      {
        int temp2= k;
        int sum=sum1+sum2;
        if(k<10) sum+=13;
        while(temp2)
        {
          sum+=my[my1[temp2%10]];
          temp2/=10;
        }
        if(sum>50) count++;
      }
    }
  }
  cout<<count;
  
  return 0;
}