#include <iostream>

using namespace std;
int partition(int *arr,int low,int high);
void swap(int *element1,int *element2);
void quick_sort(int *arr,int low,int high);
void swap(int *element1,int *element2)
{
	int temp=*element1;
	*element1=*element2;
	*element2=temp;
}
int partition(int *arr,int low,int high)
{
	int p,q,pivot;
	p=low+1;q=high;pivot=low;
	while(p<=q)
	{
		while(arr[p]<arr[pivot])
		{
			p++;
		}
		while(arr[q]>arr[pivot])
		{
			q--;
		}
		if(p<q)
		swap(&(arr[p]),&(arr[q]));
	}
	swap(&(arr[pivot]),&(arr[q]));
	return q;
	
}
void quick_sort(int *arr,int low,int high)
{
	int index;
	if(low<high)
	{
		index=partition(arr,low,high);
		quick_sort(arr,low,index-1);
		quick_sort(arr,index+1,high);
		
	}
}
int main() {
	int num;
	cout<<"enter the n of array"<<endl;
	cin>>num;
	int arr[num];
	cout<<"enter the array"<<endl;
	for(int i=0;i<num;i++)
	{
		cin>>arr[i];
	}
	quick_sort(arr,0,num-1);
	cout<<"quick_sort:\n";
	for(int i=0;i<num;i++)
	{
		cout<<arr[i]<<endl;
	}
	
	return 0;
}
