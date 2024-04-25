#include <iostream>
#include <queue>
using namespace std;
void showq(queue<int> gp)
{
	queue<int> g=gp;
	if(g.empty()==true)
	{
		cout<<"queue is empty";
		return;
	}
	cout<<"queue list"<<endl;
	while(!g.empty())
	{
		cout<<"\t"<<g.front();
		g.pop();
	}
	cout<<endl;
}

int main() {
	queue <int> item;
	int data,opt;
	cout<<"MENU\n"<<"1.INSERT\n2.DISPLAY LIST\n3.POP\n4.PEEP\nENTER THE CHOICE: "<<endl;
	
	while(1){
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"enter the data to insert: ";
				cin>>data;
				item.push(data);
				break;
			case 2:
				showq(item);
				break;
			case 3:
				if(item.empty()==true)
				{
					cout<<"there is no data to poped"<<endl;
				}
				else{
					item.pop();
				    cout<<"poped successfully"<<endl;
				}
			
				break;
			case 4:
				cout<<"front->"<<item.front()<<endl;
				break;
			default:
				cout<<"enter the valid choice";
				break;
				
		}
	}
	return 0;
}
