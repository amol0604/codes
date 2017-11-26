#include <iostream>
#include <string>
using namespace std;

bool strseq(string str1, string str2){

	int m  = str1.length();
	int n  = str2.length();
	if(m <1) return true;
	int i = 0,j=0;
	while(i< m){
		if(j<n){
			if(str1[i]==str2[j]){
				i++;
				j++;
			}
			else{
				j++;
			}
		}
		else
			return false;
	}

	return true;

}

int main(){
	string str1 = "gksrek", str2 = "geeksforgeeks";
	cout << strseq(str1, str2)<< endl;

	return 0;
}