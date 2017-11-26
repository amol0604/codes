#include <iostream>
using namespace std;
void swap(int *a, int *b){

	int temp = *a;
	*a = *b;
	*b = temp;
}

void printcomb(int arr[], int n,int l, int k){

	if(l==k)
	{
		//print combinations
		for(int j=0; j < k; j++)
			cout << arr[j] << " " ;
		cout << endl;
		return;
	}
	for(int j=l;j < n; j++){
		swap(arr[l],arr[j]);
		printcomb(arr,n,l+1,k);
		swap(arr[l],arr[j]);
	}

}
int main(){

	int arr[] = {1,2,3,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << n  << endl;
	int k=2;
	printcomb(arr,n,0,k);

	return 0;
}