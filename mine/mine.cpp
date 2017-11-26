#include <iostream>
#include <fstream>
using namespace std;

void reveal_ij(char *board, int N, int i, int j){

	if(i < 0 || i >= N || j < 0 || j >= N )
		return

	//if ij or its neighbours have a mine, return
	for(int i1 = -1; i1 <=1 ; i1++){
		for(int j1 = -1; j1 <=1 ; j1++){

			if(i+i1 >=0 && i+i1 < N && j+j1 >=0 && j+j2 <N )
			{
				if ( (*((board + i*N)+j)) == '*') 
					return;
			}
		}
	}

}

int min_clicks(char *board, int N){

	/*for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout << *((board + i*N)+j);

			}
			cout << endl;
		}*/

			

	return 0;
}


int main(){
	ifstream temp;
	temp.open("A-small-practice.in");
	int t;
	temp >> t;
	int count = 1;

	ofstream temp1;
	temp1.open("output.txt");

	while(t--){
		int N;
		temp >> N;
		cout << N << endl;

		char board[N][N];
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				temp >> board[i][j];
			}
		}

		//code to print the board
		/*   
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout << board[i][j];

			}
			cout << endl;
		}	*/

		int res = 1;

		res = min_clicks((char*)board,N);


		temp1 << "Case #" << count << " " << res << endl;
		count++;

	}
	temp1.close();
	temp.close();

	return 0;
}