#include <iostream>
using namespace std;
class node
{
	public:
		int data;
		node *prev;
		node *next;
		
		node()
		{
			data=0;
			prev=NULL;
			next=NULL;
		}
		node(int data)
		{
			this->data=data;
			this->prev=NULL;
			this->next=NULL;
		}
};

class double_linked_list
{
	node *head;
	public:
		double_linked_list()
		{
			head=NULL;
		}
		
		void insertdata(int);
		
		void printlist();
		
		void deletedata(int);
		
};

void double_linked_list::insertdata(int setdata)
{
	node *newnode=new node(setdata);
	
	if(head==NULL)
	{
		head=newnode;
		newnode->prev=NULL;
		newnode->next=NULL;
		return;
	}
	node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}

void double_linked_list::printlist()
{
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void double_linked_list::deletedata(int deldata)
{
	node *temp=head,*temp2;
	if(head==NULL)
	{
		cout<<"list id empty"<<endl;
		return;
	}
	while(temp->data!=deldata)
	{
		temp2=temp;
		temp=temp->next;
	}
	temp2->next=temp->next;
	temp->next->prev=temp;
	delete temp;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	double_linked_list list;
	int opt,data;
	cout<<"MENU"<<endl<<"1.INSERT NODE \n2.PRINT NODE\n3.DELETE NODE"<<endl;
	cout<<"enter the choice: "<<endl;
	while(1){
		cin>>opt;
		
		switch(opt)
		{
			case 1:
				cout<<"enter the data to insert\n";
				cin>>data;
				list.insertdata(data);
				break;
			case 2:
				list.printlist();
				break;
			case 3:
				cout<<"enter the data to delete\n";
				cin>>data;
				list.deletedata(data);
				break;
				default:
					cout<<"enter the valid choice";
					break;
		}
}
	return 0;
}
