#include <iostream>
#define MAX 1000
using namespace std;

class stack{
	int top;
	public:
		int arr[MAX];
		stack()
		{
			top = -1;
		}
		bool push(int);
		int pop();
		int peek();
		int peep();
		
};
bool stack::push(int data)
{
	if(top>=MAX-1){
		return false;
	}
	else
	{
		arr[++top]=data;
		return true;
	}
	
}
int stack::pop()
{
	if(top==-1)
	{
		return 0;
	}
	else
	{
		top--;
		return 1;
	}
}
int stack::peek()
{
	if(top==-1)
	{
		return 0;
	}
	else
	{
		return arr[top];
	}
}
int stack::peep()
{
	int temp=top;
	if(temp==-1)
	{
		return 0;
	}
	else
	{
		while(temp > -1)
		{
			cout<<arr[temp--]<<" ";
		}
		cout<<endl;
	}
}
int main() {
	
	stack s1;
	int opt,data;
	cout<<"MENU"<<endl<<"1.PUSH\n2.POP\n3.PEEK\n4.PEEP\n";
	cout<<"Enter your choice: ";
	while(1)
	{
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"enter the data: ";
				cin>>data;
				if(s1.push(data)==false)
				{
					cout<<"OUT OF RANGE"<<endl;
				}
				break;
			case 2:
				if(s1.pop()==0)
				{
					cout<<"the satck is empty"<<endl;
				}
				else
				{
					cout<<"the element is poped"<<endl;
				}
				break;
			case 3:
				if(s1.peek()==0)
				{
					cout<<"stack is empty"<<endl;
				}
				else
				{
					cout<<"top->"<<s1.peek()<<endl;
				}
				break;
			case 4:
				if(s1.peep()==0)
				{
					cout<<"stack is empty"<<endl;
				}
				else
				{
					s1.peek();
				}
				break;
		}
	}
	
	
	return 0;
}
