#include<iostream>
using namespace std;

class minheap
{
	minheapnode *harr;
	int heap_size;
public:
	minheap(minheapnode a[], int size);
	void minheapify(int);
	int left(int i){return(2*i+1)};
	int right(int i){return(2*i+2)};
	minheapnode getmin(){return harr[0]};
	void(replaceMin(minheapnode x)) {harr[0]=x; minheapify(0)};

};
minheap::minheap()

int *mergeArrays(int arr[][n], int k){

	int *output = new int[n*k];
};


int main(){
	int arr[][n] = {{2,6,12,34},{1,9,20,1000},{23,34,90,2000}};
	int k = sizeof(arr)/sizeof(arr[0]);
	int *output = mergeArrays(arr,k);
	cout << "mergeArrays" << endl;
	printArray(output,n*k);

	return 0;
};