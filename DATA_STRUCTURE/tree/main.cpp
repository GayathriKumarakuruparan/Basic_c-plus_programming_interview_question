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
		bool insertion_node(int data);
		node * delete_node(node *,int data);
		void inorder(node *);
		void pre_order(node *);
		void post_order(node *);
};
extern int status;
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
node* tree::delete_node(node *root,int data)
{
	if(root==NULL)
	{
		return root;
	}
	if(root->data < data)
	{
		root->right=delete_node(root->right,data);
	}
	else if(root->data > data)
	{
		root->left=delete_node(root->left,data);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			root=NULL;
			status=1;
		}
		else if(root->left==NULL)
		{
			node *temp=root;
			root=root->right;
			delete temp;
			status=1;
		}
		else if(root->right ==NULL)
		{
			node *temp=root;
			root=root->left;
			delete temp;
			status=1;
		}
	}
	return root;
}

int main() {
	int data,opt1,opt2,i=1;
	tree t1;
	cout<<"MENU\n"<<"1.INSERTION\n2.DELETE_NODE\n3.DISPLAY NODE\n4.EXIST\nEnter the choice: ";
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
				cout<<"enter the data to delete: "<<endl;
				cin>>data;
				t1.delete_node(t1.root,data);
				if(status==1)
				{
					cout<<"deleted.."<<endl;
				}
				else
				{
					cout<<"data not found"<<endl;
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
