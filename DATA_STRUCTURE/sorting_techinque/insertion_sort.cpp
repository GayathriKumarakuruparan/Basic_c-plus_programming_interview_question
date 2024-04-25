#include <iostream>
#include <vector>
using namespace std;

vector<int> insertion_sort(vector<int> arr,int num)
{
	
	int i,j,key;
	for(i=1;i<num;i++)
	{
		
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j-=1;
		}
		arr[j+1]=key;
	}
	return arr;
}
 void print(vector <int> arr,int num)
 {
 	int i;
 	cout<<"insertion_sorted:\n";
 	for(i=0;i<num;i++)
 	{
 		cout<<arr[i]<<" ";
	}
 }
int main() {
	vector <int> arr;
	int num;
	cout<<"enter the n of array"<<endl;
	cin>>num;
	cout<<"enter the array:"<<endl;
	for(int i=0;i<num;i++)
	{
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}
	vector<int> arr1=insertion_sort(arr,num);
	
	print(arr1,num);
	return 0;
}
