#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool way_to_sort(int i, int j )
	{
		return (i>j)? true : false;
	}

int main(){

	//sort array
	int arr[] = {0,1,4,2,10,9,6};
	int n = sizeof(arr)/sizeof(arr[0]);

	sort(arr, arr+n);

	for(int i=0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	//sorting a vector
	vector<int> intVec; // = {56, 32, -43, 23, 12, 93, 132, -154};
	intVec.push_back(56);
	intVec.push_back(32);
	intVec.push_back(-43);
	intVec.push_back(23);
	intVec.push_back(12);
	intVec.push_back(93);

	sort(intVec.begin(),intVec.end());

	for(int i=0; i < intVec.size(); i++){
		cout << intVec[i] << " ";
	}
	cout << endl;


	//sorting in descending order or any specified order
	
	vector<int> intVec1; // = {56, 32, -43, 23, 12, 93, 132, -154};
	intVec1.push_back(56);
	intVec1.push_back(32);
	intVec1.push_back(-43);
	intVec1.push_back(23);
	intVec1.push_back(12);
	intVec1.push_back(93);

	sort(intVec1.begin(),intVec1.end(), way_to_sort);

	for(int i=0; i < intVec1.size(); i++){
		cout << intVec1[i] << " ";
	}
	cout << endl;


	//reversing the vector

	vector<int> intVec2; // = {56, 32, -43, 23, 12, 93, 132, -154};
	intVec2.push_back(56);
	intVec2.push_back(32);
	intVec2.push_back(-43);
	intVec2.push_back(23);
	intVec2.push_back(12);
	intVec2.push_back(12);
	intVec2.push_back(93);
	intVec2.push_back(56);

	reverse(intVec2.begin(),intVec2.end());

	cout << "Reversed vector : " << endl;
	for(int i=0; i < intVec2.size(); i++){
		cout << intVec2[i] << " ";
	}
	cout << endl;

	//find the max_element //take care of the star!!
	int mm = *max_element(intVec2.begin(), intVec2.end());
	cout << mm << endl;

	//find the min_element //take care of the star!!
	mm = *min_element(intVec2.begin(), intVec2.end());
	cout << mm << endl;

	

	return 0;
}