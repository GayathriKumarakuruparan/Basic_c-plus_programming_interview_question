#include <iostream>
using namespace std;


class node{
	public:
		int data;
		node *next;
		node()
		{
			data=0;
			next=NULL;
		}
		node(int data){
			this->data=data;
			this->next=NULL;
		}
		
};

class linkedlist{
	public:
		node *head;
		linkedlist()
		{
			head=NULL;
		}
		

		void insertnode(int);
		
		
		void printlist();
		
		
		void deletenode(int);
};

void linkedlist::insertnode(int setdata)
{
	node *newnode =new node(setdata);
	
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
}

void linkedlist::printlist()
{
	node *temp=head;
	if(head==NULL)
	{
		cout<<"List empty"<<endl;
		return;
	}
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void linkedlist::deletenode(int deldata)
{
	node *temp=head,*temp2;
	if(head==NULL)
	{
		cout<<"The list is empty"<<endl;
		return;
	}
	
	while(temp->data!=deldata)
	{
		temp2=temp;
		temp=temp->next;
	}
	temp2->next=temp->next;
	delete temp;
}
int main() {
	
	linkedlist list;
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
				list.insertnode(data);
				break;
			case 2:
				list.printlist();
				break;
			case 3:
				cout<<"enter the data to delete\n";
				cin>>data;
				list.deletenode(data);
				break;
				default:
					cout<<"enter the valid choice";
					break;
					
			
		}
}
	/*list.insertnode(1);
	list.insertnode(2);
	list.insertnode(3);
	list.insertnode(4);
	list.printlist();
	list.deletenode(3);
	list.printlist();*/
	return 0;
}
