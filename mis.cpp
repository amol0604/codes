#include <iostream>
using namespace std;
int abs(int x){
        if(x>=0)
            return x;
        else 
            return (-1)*x;
    }
void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }

void printArray(int A[], int n){
	int i = 0;
	while(i<n){
		cout << A[i] << " " ;
		i++;
	}
	cout << endl;
}

void segregate_to_right(int A[], int n){
        int place = n-1;
        while(place >= 0 && A[place]<=0)
            place--;
        if(place < 0)
            return; //all elements are <=0 and so array is already segregated
        int i=0;
        while(i<place){
            if(A[i]>0){
                i++;
                continue;
            }
            if(A[i] <= 0 )
            {
                swap(&A[i], &A[place]);
                place--;
                while(place >= 0 && A[place]<=0)
                    place--;
                i++;
            }
        }
    }

int firstMissingPositive(int A[], int n) {
        segregate_to_right(A,n);
        int positive_count = 0;
        for(int i=0; i < n; i++){
            if (A[i] > 0 )
                positive_count++;
        }
        if(positive_count==0) return 1;
        if(positive_count==1)
        {
            if(A[0]==1) return 2;
            else return 1;
        }
        int index=0;
        while(index<positive_count){
            if(abs(A[index])-1 > positive_count-1 || A[abs(A[index])-1] <= 0)
                {
                    index++;
                    continue;
                }
            else{
                A[abs(A[index])-1] = (-1)*A[abs(A[index])-1];
                index++;
                continue;
            }
        }
        int res= 0;
        while(res < positive_count && A[res] <0) 
            res++;
        if(res==positive_count)
            return positive_count+1;
        else return res+1;
        
    }

int main(){
	int A[] = {-6,4,-6,4,3,3,-6,4,0,9,7};
	int n = sizeof(A)/sizeof(A[0]);
	segregate_to_right(A,n);
	printArray(A,n);
	cout << firstMissingPositive(A,n) << endl;
	return 0;
}
