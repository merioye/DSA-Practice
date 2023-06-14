// Create	an	N*M	matrix	and	take	input	from	the	user	to	populate	it	
// and	then	print	the	matrix

#include<iostream>
using namespace std;

int main(){
    int n, m;
    cout<<"Enter the no of rows of matrix: ";
    cin>>n;
    cout<<"Enter the no of columns of matrix: ";
    cin>>m;

    int matrix[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int element;
            cout<<"Enter the element of index ["<<i<<"]["<<j<<"]: ";
            cin>>element;
            matrix[i][j] = element;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}