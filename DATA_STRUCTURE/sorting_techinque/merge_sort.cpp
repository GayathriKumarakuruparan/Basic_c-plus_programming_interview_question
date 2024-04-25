#include <iostream>
using namespace std;
int merge_sort(int *arr,int narray);
void merge(int *,int ,int *,int ,int *,int );
int merge_sort(int *arr,int narray)
{
	int i,j,mid=(narray/2);
	if(narray==1)
	{
		return 0;
	}
	int LSA[mid];
	
	for(i=0;i<mid;i++)
	{
		LSA[i]=arr[i];
	}
	int RSA[narray-mid];
	for(j=mid;j<narray;j++)
	{
		RSA[j-mid]=arr[j];
	}
	merge_sort(LSA,mid);
	merge_sort(RSA,(narray-mid));
	merge(arr,narray,LSA,mid,RSA,(narray-mid));
	

	
}

void merge(int *arr,int narray,int *left,int nleft,int *right,int nright)
{
	int i=0,j=0,k=0;
	while(i<nleft && j<nright)
	{
		if(left[i]<right[j])
		{
			arr[k]=left[i];
			k++,i++;
		}
		else
		{
			arr[k]=right[j];
			k++,j++;
		}
	}
	while(j<nright)
	{
		arr[k]=right[j];
		k++,j++;
	}
	while(i<nleft)
	{
		arr[k]=left[i];
		k++,i++;
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
	merge_sort(arr,num);
	cout<<"merge_sort:\n";
	for(int i=0;i<num;i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}
