#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> inp)
{
	int n = inp.size();
	for(int i=0; i < n; i++)
	{
		cout << inp[i] << " ";
	};	
	cout << endl;
};

int parent_index(int inp_index)
{
	return(inp_index/2);
};

vector<int> min_heap(vector<int> inp)
{
	vector<int> res;
	int n = inp.size();

	for(int i=0; i < n; i++)
	{
		//code to insert key in res
		res.push_back(inp[i]);
		int j=i;
		while(res[parent_index(j)] > res[j] )
		{			
			//reload the min heap property
			int temp = res[parent_index(j)];
			res[parent_index(j)]=res[j];
			res[j]=temp;
			j = parent_index(j);
		};	
	};	
	return(res);
};

using namespace std;
int main()
{
	cout << "Program to build a min heap of given n numbers..." << endl;
	int arr[] = {10,9,5,1,11,6,8,4,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> inp;
	for(int i=0; i < n; i++)
	{
		inp.push_back(arr[i]);
	};	

	cout << "Input array:" << endl;
	print_vector(inp);
	vector<int> res = min_heap(inp);
	cout << "Min heap of input array:" << endl;
	print_vector(res);
};