#include <iostream>
using namespace std;
    

    
    int bin_search(int A[], int l, int r, int key)
    {
        if(l<=r){
            int mid= l + ((r-l)/2);
            if(A[mid]==key)
                return mid;
            else if(A[mid] < key)
                return bin_search(A, mid+1, r,key);
            else 
                return bin_search(A, l, mid-1,key);
        }
        return -1;
    }
    
    int search_pivot(int A[], int l, int r){
        cout << l << " " << r << endl;
        if(l>r) return -1;
        if(l==r) return l;
        if(l<r){
            int mid = l + ((r-l)/2);
            if(mid+1 <= r && A[mid+1] < A[mid])
                return mid;
            if(mid-1>=l && A[mid]<A[mid-1])
                return mid-1;
            else {
                if(A[mid]>A[l])
                    return search_pivot(A,mid+1,r);
                else if(A[mid] < A[l])
                    return search_pivot(A,l,mid-1);
                else
                {   
                    if(l==mid) return r;
                    search_pivot(A,l,mid);
                }
            }
        }       
        
    }

    bool rot_search(int A[], int n, int target) {
        
        int pivot = -1;
        pivot = search_pivot(A,0,n-1);
        cout << pivot << endl;
        if(pivot==n-1)
            {
                return ( bin_search(A,0,n-1,target) == -1 ) ? false : true;
            }
        else if(target >= A[0] )
                return ( bin_search(A,0,pivot,target) == -1 ) ? false : true;
        else return ( bin_search(A,pivot+1,n-1,target)== -1 ) ? false : true;
        
    }

int main(){
    int A[] = {1,2,3,4,5};
    cout << rot_search(A,5,5) << endl;

    return 0;
}
