#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> arr;
	int num,i,j;
	cout<<"enter the num of array"<<endl;
	cin>>num;
	for(i=0;i<num;i++)
	{
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(i=0;i<num;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
