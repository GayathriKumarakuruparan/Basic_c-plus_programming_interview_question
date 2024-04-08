
#include <iostream>
using namespace std;
int main()
{
    int num1,num2,num3;
    cout<<"Enter the num:"<<endl;
    cin>>num1>>num2>>num3;
    int res=(num1>num2)?(num1>num3?num1:num3):(num2>num3?num2:num3);
    cout<<"the largest number is: "<<res<<endl;
   

    return 0;
}
