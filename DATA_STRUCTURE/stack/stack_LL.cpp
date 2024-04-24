#include <iostream>
using namespace std;
class stack{
	stack *top;
	int data;
	stack *link;
	public:
		stack()
		{
			top=NULL;
			data=0;
			link=NULL;
		}
		stack(int data)
		{
			this->top=NULL;
			this->data=data;
			this->link=NULL;
		}
		bool push(int);
		
		int pop();
		
		int peek();
		
		int peep();
};
bool stack::push(int data)
{
	stack *newnode=new stack(data);
	if(top==NULL)
	{
		top=newnode;
		return true;
	}
	else 
	{
		newnode->link=top;
		top=newnode;
		return true;
	}
}
int stack::pop()
{
	stack *temp=top;
	if(temp==NULL)
	{
		return 0;
	}
	else
	{
		top=temp->link;
		delete temp;
	}
	return 1;
}
int stack::peek()
{
	stack *temp=top;
	if(top==NULL)
	{
		return 0;
	}
	else
	{
		return (temp->data);
	}
}
int stack::peep()
{
	stack *temp=top;
	if(temp==NULL)
	{
		return 0;
	}
	else
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->link;
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
				s1.push(data);
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
