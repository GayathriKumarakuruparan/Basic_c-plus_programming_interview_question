#include <iostream>

using namespace std;
void build_heap(int*,int);
void heap_sort(int*,int);
void heapify(int*,int ,int);
void swap(int *,int *);
void build_heap(int * heap,int size)
{
	int index=(size/2)-1;
	while(index>=0)
	{
		heapify(heap,index,size);
		index--;
	}

}
void heapify(int* heap,int index,int size)
{
	int large,L,R;
	L=(2*index)+1;
	R=(2*index)+2;
	if(heap[index]<heap[L] && L<size)
	{
		large=L;
	}
	else
	{
		large=index;
	}
	if(heap[large]<heap[R] && R<size)
	{
		large=R;
	}
	
	if(index!=large)
	{
		swap(&heap[index],&heap[large]);
		heapify(heap,index,size);
	}
}

void heap_sort(int* heap, int size)
{
	build_heap(heap,size);
	int index=size-1;
	while(index>=0)
	{
		swap(&heap[0],&heap[index]);
		heapify(heap,0,index);
		index--;
	}
	
}

void swap(int *element1,int *element2)
{
	int temp=*element1;
	*element1=*element2;
	*element2=temp;
}

int main() {
	
	int limit;
	cout<<"Enter the limit for heap: "<<endl;
	cin>>limit;
	int heap[limit];
	for(int i=0;i<limit;i++)
	{
		cin>>heap[i];
	}
	build_heap(heap,limit);
	heap_sort(heap,limit);
	
	for(int i=0;i<limit;i++)
	{
		cout<<heap[i]<<" ";
	}
	return 0;
}
