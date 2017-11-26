#include <iostream>
#include <vector>
using namespace std;
 int max_three(int a, int b, int c)
    {
        int res = a;
        if(b > res)
            res = b;
        if(c > res)
            res = c;
            
        return res;
    }

int findMin(vector<int> &height, int l, int r){
        int min_index = l;
        int min_height = height[l];
        for(int i =l+1 ; i  <= r; i++){
            if(height[i] < min_height)
                {
                    min_height = height[i];
                    min_index = i;
                }
        }
        return min_index;
    }
    int lar(vector<int> &height, int l, int r){
        if(l>r) return 0;
        if(l==r) return height[l];
        int min_index = findMin(height,l,r);
        //cout << min_index << endl;
        int left = lar(height,l,min_index-1);
        int right = lar(height,min_index+1,r);
        return max_three(height[min_index]*(r-l+1), left, right);
        
    }
    

   
int largestRectangleArea(vector<int> &height) {
        
        //if(height.size()<1) return 0;
        //if(height.size()==1) return height[0];
        
        return lar(height,0,height.size()-1);
        
    }

int main(){
    vector<int> height;
    height.push_back(2);
    height.push_back(1);
    height.push_back(5);
    height.push_back(6);
    height.push_back(2);
    height.push_back(3);
    cout << largestRectangleArea(height) << endl;
    return 0;
}
    
    