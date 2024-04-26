#include <iostream>
using namespace std;
class node{
	public:
		node *left;
		int data;
		node *right;
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
		
		
		bool insertion_node(int data);
	
		int search_node(int data);
		void inorder(node *);
		void pre_order(node *);
		void post_order(node *);
		
		
};

//insertion
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



//search
int tree::search_node(int data)
{
	node *temp=root;
	if(root==NULL)
	{
		return 2;
	}
	while(temp!=NULL)
	{
		if(temp->data < data)
		{
			temp=temp->right;
		}
		else if(temp->data > data)
		{
			temp=temp->left;
		}
		else 
		{
			return temp->data;
		}
	}
	return 0;
}
//print_node
void tree::inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<"->";
		inorder(root->right);
	}
	
}
void tree::pre_order(node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"->";
		inorder(root->left);
		inorder(root->right);
	}
	
}
void tree::post_order(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		inorder(root->right);
		cout<<root->data<<"->";
	}
	
}

int main() {
	int data,opt1,opt2,i=1;
	tree t1;
	cout<<"MENU\n"<<"1.INSERTION\n2.SEARCH_NODE\n3.DISPLAY NODE\n4.EXIST\nEnter the choice: ";
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
				cout<<"enter the data to search: "<<endl;
				cin>>data;
				if(t1.search_node(data)==2)
				{
					cout<<"tree is empty "<<endl;
				}
				else if(t1.search_node(data)==0)
				{
					cout<<"data not found "<<endl;
				}
				else
				{
					
					cout<<t1.search_node(data)<<" is found"<<endl;
				}
				break;
			case 3:
				cout<<"MENU\n"<<"1.INODER\n2.PRE_ORDER\n3.POST_ORDER\n\nEnter the choice: ";
				cin>>opt2;
				switch(opt2)
				{
					case 1:
						t1.inorder(t1.root);
						break;
					case 2:
						t1.pre_order(t1.root);
						break;
					case 3:
						t1.post_order(t1.root);
						break;
					default:
						cout<<"enter the valid choice"<<endl;
						break;
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
