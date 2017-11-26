#include <iostream>
using namespace std;
    
int search_pivot(int A[], int l, int r){
        if(l>r) return -1;
        else if(l==r) return l;
        else{
            int mid = l + ((r-l)/2);
            if(mid+1 <= r && A[mid+1] < A[mid])
                return mid;
            if(mid-1>=l && A[mid]<A[mid-1])
                return mid-1;
            else {
                if(A[mid]>=A[l])
                    return search_pivot(A,mid+1,r);
                else
                    return search_pivot(A,l,mid-1);
                
            }
        }       
        
    }

int rot_search(int A[], int n, int target) {
        
        int pivot = -1;
        pivot = search_pivot(A,0,n-1);
        return pivot;
        
    }

int main(){
    int A[] = {1,2,3,4,9,10,11,15};
    cout << rot_search(A,8,1) << endl;

    return 0;
}
