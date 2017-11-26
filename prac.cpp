#include <iostream>
#include <vector> 
using namespace std;

int main(){

	vector<int> temp_vector;
	for(int i=0; i< 10; i++){

		temp_vector.push_back(2*i);
	};

	for(int i=0; i < temp_vector.size(); i++){

		cout << temp_vector[i] << endl;
	};

	cout << temp_vector.front() << endl;
	cout << temp_vector.back() << endl;
	
	temp_vector.pop_back();
	cout<< "printing again " << endl;
	for(int i=0; i < temp_vector.size(); i++){

		cout << temp_vector[i] << endl;
	}

	return 0;
}