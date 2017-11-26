#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_res(vector<vector<int> > res){

	for(int i = 0 ; i < res.size(); i++){
		for(int j=0; j < res[i].size(); j++){
			cout << res[i][j] << " "; 
		}
		cout << endl;
	}

}
vector<vector<int> > subsetsWithDup(vector<int> &S) {
        
        sort(S.begin(),S.end());
        vector<vector<int> > res;
        vector<int> temp;
        res.push_back(temp);
        for(int i=0; i < S.size(); i++){
            vector<vector<int> > res_temp;
            
            for(int j=0; j < res.size();j++){
                
                vector<int> temp1 = res[j];
                res_temp.push_back(temp1);
                temp1.push_back(S[i]);

                if(find(res.begin(), res.end(), temp1) == res.end()) 
                    res_temp.push_back(temp1);
                    
                
            }
            
            res = res_temp;
            
        }      
    
        return res;
        
        
    }

int main(){
	vector<int> inp;
	inp.push_back(1);
	inp.push_back(1);
	vector<vector<int> > res = subsetsWithDup(inp); 
	print_res(res);
	return 0;
}