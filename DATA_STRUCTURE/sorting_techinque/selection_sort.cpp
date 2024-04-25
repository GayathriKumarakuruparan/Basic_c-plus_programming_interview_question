#include <iostream>
#include <vector>
using namespace std;

vector<int> selection_sort(vector<int>arr,int num)
{
	int i,j,min_idx;
	for(i=0;i<num-1;i++)
	{
		min_idx=i;
		for(j=i+1;j<num;j++)
		{
			if(arr[min_idx]>arr[j])
			{
				min_idx=j;
			}
		}
		if(min_idx !=i)
		{
			int temp=arr[min_idx];
			arr[min_idx]=arr[i];
			arr[i]=temp;
		}
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
	vector<int> arr1=selection_sort(arr,num);
	
	print(arr1,num);
	return 0;
	return 0;
}
