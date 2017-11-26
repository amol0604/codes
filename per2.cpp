#include <iostream>
#include <vector>
using namespace std;
 void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

void permuteUnique_util(vector<int> &num, int l, int r, vector<vector<int> > &res){
        if(l==r){
            if(find(res.begin(), res.end(), num) == res.end()){
                res.push_back(num);
            }
            return;
        }
        for(int i=l; i <= r;i++){
            swap(&num[i], &num[l]);
            permuteUnique_util(num,l+1,r,res);
            swap(&num[i], &num[l]);
            
        }
        
    }

vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;    
        permuteUnique_util(num,0,num.size()-1,res);
        return res;
    }

int main(){
	vector<int> num;
	num.push_back(-1);
	num.push_back(2);
	num.push_back(-1);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-1);
	num.push_back(2);
	num.push_back(1);

	vector<vector<int> > res = permuteUnique(num);
	for(int i= 0; i < res.size(); i++){
		for(int j=0; j < res[i].size(); j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

