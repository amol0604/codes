#include <iostream>
using namespace std;

void bubble_sort(int arr[],int n)
{
	for(int i=1; i <= n-2; i++)
	{
		for(int j=0;j<=n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			};	
		}	
	};
};
void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	return;
};

int partition(int arr[], int l, int r)
{
	int key = arr[r];
	int i = l-1;
	for(int j=l; j <= r-1; j++ )
	{
		if(arr[j]<=key)
		{
			i++;
			swap(arr,i,j);
		}	
	};	
	swap(arr,i+1,r);
	return i+1;
};

void quick_sort(int arr[], int l,int r)
{
	if(l < r)
	{
		int p1 = partition(arr,l,r);
		quick_sort(arr,l,p1-1);
		quick_sort(arr,p1+1,r);
	};	

};


void print_array(int arr[], int n){

	for(int i=0; i < n; i++)
		cout << arr[i] << " ";
	
	cout << endl;	
};

int main(){

	/*int arr[] = {1,2,3,10,5,6,7,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,n);
	print_array(arr,n);*/

	int arr1[] = {1,2,3,10,5,6,7,2,3};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	quick_sort(arr1,0,n1-1);
	print_array(arr1,n1);

	return 0;

};