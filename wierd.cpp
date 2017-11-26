#include <iostream>
#include <deque>
using namespace std;

void printvec(deque<int> v){
    for(int i=0; i < v.size(); i++ ){
        cout << v[i] << " " ;
    }
    cout << endl;
}


deque<int> myadd(deque<int> v1, deque<int> v2){
    //cout << "here" << endl;
    //deque<int> v1 = va;
    //deque<int> v2 = vb;
    deque<int> res;
    int j = v2.size()-1;
    for(int i = v1.size()-1; i >=0 ; i--){
        if(j < 0){
        
            res.push_front(v1[i]);
        }
        else{
            int temp = v1[i] + v2[j];
            if(temp <= 9){
                //res.insert(res.begin(), temp);
                res.push_front(temp);
            }
            else{
                res.push_front(temp%10);
                if(i-1 >=0){
                    v1[i-1] =   v1[i-1] + temp/10;
                }
                else if(j-1 >=0){
                    v2[j-1] =   v2[j-1] + temp/10;
                }
                else{
                    res.push_front(temp/10);
                }
            }
            j--;
        }
    }
    
    while(j >=0){
        res.push_front(v2[j]);
        j--;
    }
    
    return res;
    }

deque<int> mult(deque<int> v1, int k){
    deque<int> res;
    int carry = 0;
    for(int i = v1.size()-1; i >=0 ; i--)
    {
        int temp = v1[i]*k + carry;
            if(temp <= 9){
                res.push_front(temp);
                carry = 0;
            }
            else{
                res.push_front(temp%10);
                carry = temp/10;
                if(i==0){
                    res.push_front(carry);
                }
            }   
    }
        
    return res;
}


int main()
{
    //cout << "Hello World!" << endl;
    int t;
    cin >> t;
    while(t--){
        int k = 0, n = 0;
        cin >> k >> n;
        //cout << k  << n ;
        //find sum of digits in total number of nodes in the k-ary tree!
        deque<int> numberofnodes;
        deque<int> current_nodes ;
        numberofnodes.push_back(1);
        current_nodes.push_back(1);
        
        for(int i= 0; i < n; i++){
            current_nodes = mult(current_nodes,k);
            //printvec(current_nodes);

            numberofnodes = myadd(numberofnodes,current_nodes );
             printvec(numberofnodes);
        }
        
        
        int ans = 0;
        for(int i=0; i < numberofnodes.size(); i++){
            ans = ans+ numberofnodes[i];
        }
        cout << ans << endl;
    }
    return 0;
}
