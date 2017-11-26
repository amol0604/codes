#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> A){
	for(int i=0; i < A.size(); i++){
		cout << A[i] << " ";
	}
	cout << endl;
}

int longestConsecutive(vector<int> &num){   // runs in nlogn

	printVector(num);
	sort(num.begin(),num.end());
	printVector(num);
	int res =0;
	int curr = 1;
	for(int i=1;i < num.size(); i++ ){
		if(num[i]==num[i-1]+1){
			curr++;
			if(curr>res){
				res = curr;
			}
		}
		else if(num[i]==num[i-1]){		//to handle cases like 0 0 1 1 2 5
			continue;
		}
		else{
			curr =1;
		}
	}
	return res;
}

int main(){
	
	vector<int> num;
	num.push_back(203);
	num.push_back(204);
	num.push_back(200);
	num.push_back(1);
	num.push_back(3);
	num.push_back(2);
	num.push_back(5);
	num.push_back(201);
	//num.push_back(202);

	cout <<  "Ans = "<< longestConsecutive(num) << endl;
	



	return 0;
}