#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node *left;
		node *right;
		node()
		{
			data=0;
			left=NULL;
			right=NULL;
		}
		node(int data)
		{
			this->data=data;
			this->left=NULL;
			this->right=NULL;
		}
};
class tree{
	public:
		node *root;
		tree()
		{
			root=NULL;
		}
		bool insertion_node(int);
		int max_node();
		int min_node();
		
};
bool tree::insertion_node(int data)
{
	node *newnode=new node(data);
	node *temp=root;
	int flag;
	if(newnode==NULL)
	{
		return false;
	}
	if(root==NULL)
	{
		root=newnode;
		return true;
	}
	node *parent;
	while(temp!=NULL)
	{
		parent=temp;
		
		if( (newnode->data)  >  (temp->data) )
		{
			temp=temp->right;
			flag=1;
		}
		else if( (newnode->data)  <  (temp->data) )
		{
		    temp=temp->left;
			flag=0;
		}
		else
		{
			cout<<"duplicate data is found"<<endl;
			return 0;
		}
	}
	if(flag==1)
	{
		parent->right=newnode;
		return true;
	}
	else
	{
		parent->left=newnode;
		return true;
	}
}

int tree::min_node()
{
	node* temp=root;
	if(root==NULL)
	{
		return 0;
	}
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp->data;
}
int tree::max_node()
{
	node* temp=root;
	if(root==NULL)
	{
		return 0;
	}
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	return temp->data;
}
int main() {
	int data,opt1,opt2,i=1;
	tree t1;
	cout<<"MENU\n"<<"1.INSERTION\n2.MINIMUM DATA\n3.MAXIMUM DATA\n4..EXIST\nEnter the choice: ";
	while(i){
		cin>>opt1;
		switch(opt1)
		{
			case 1:
				cout<<"enter the data to insert: "<<endl;
				cin>>data;
				if(t1.insertion_node(data)==false)
				{
					cout<<"node is not created"<<endl;
				}
				break;
		
			case 2:
				
				if(t1.min_node()==0)
				{
					cout<<"tree is empty "<<endl;
				}
				
				else
				{
					
					cout<<t1.min_node()<<" is the minimum data"<<endl;
				}
				break;
			case 3:
				if(t1.max_node()==0)
				{
					cout<<"tree is empty "<<endl;
				}
				
				else
				{
					
					cout<<t1.max_node()<<" is the maximum data"<<endl;
				}
				break;
			case 4:
				i=0;
				cout<<"exiting......"<<endl;
				break;
			default:
				cout<<"plz enter the valid choice"<<endl;
				break;
		}
	}
	
	return 0;
}
