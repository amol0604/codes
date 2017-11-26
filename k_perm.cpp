#include <iostream>
#include <vector>
using namespace std;

int fact (int n){
	if(n==0)
		return 1;
	else
		return n*fact(n-1);
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void k_perm(vector<int> &num, int k){
		int n = num.size();
		int temp = k;
		int i=1;
		int start = 0;
		int flag = 1;
		while(flag > 0){
			int temp1 = temp/fact(n-i);
			int temp2 = temp%fact(n-i);
			
			cout << "temp 1 = " << temp1 << " temp2 = " << temp2 << endl;
			int arbit = temp1+start;
			cout << "swapping " << start << " and " << arbit << endl;
			swap(&num[start],&num[temp1+start]);
			i++;
			start++;
			temp = temp2;
			if(temp2 == 0) flag= 0;
		}

		for(int i=0; i < num.size(); i++){
			cout << num[i] << " ";
		}

		cout << endl;
}

int main(){
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);

	int k=6;  //k starts from 0 
	k_perm(num,k);

	//for(int k=0; k < 24; k++){
	//	k_perm(num,k);	
	//}

	return 0;
}