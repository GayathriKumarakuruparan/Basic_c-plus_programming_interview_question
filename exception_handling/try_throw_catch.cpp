#include <iostream>
using namespace std;
/* complie time error---> mistake in syntax
   run time error-----> logical error*/

int main() {
	
	int num1,num2,flag=0;
	cout<<"enter the numbers:"<<endl;
	cin>>num1>>num2;
	
	int res;
	try{
		if(num2==0)
		{
			 throw num2;
		}	
		else if((num1<0)||(num2<0))
		{
			throw "negative number";
		}
		else
		{
			res=num1/num2;
			flag=1;
		}
	}
	catch(int err)
	{
		cout<<"error : invalid number - the num2 is :"<<err<<endl;
	}
	catch(const char *err)
	{
		cout<<err<<endl;
	}
	if(flag==1)
	{
		cout<<"after try"<<endl;
	    cout<<"res is: "<<res<<endl;
	}

	
	return 0;
}
