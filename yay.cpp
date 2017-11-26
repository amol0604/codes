#include <iostream>
#include <vector>
using namespace std;
void print_number(vector<int> result){
	int n = result.size();
	for(int i=0; i < n; i++){
		cout << result[i];
	}
	cout << endl;
}

vector<int> plus_one(vector<int> input){
	vector<int> res = input;
	int carry = 0 ;
	for(int i = res.size()-1; i >= 0; i--){
		if(res[i]<9){
			res[i]++;
			break;	
		}
		else{
			res[i] = 0;
			carry = 1;
		}
		if(i==0 && carry ==1){
			res.insert(res.begin(),1);
		}
	}
	return res;
}
int main(){
	vector<int> num ;
	num.push_back(9);
	num.push_back(9);
	num.push_back(9); 
	print_number(num);
	vector<int> result = plus_one(num);
	print_number(result);
	return 0;
