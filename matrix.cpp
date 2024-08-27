#include<bits\stdc++.h>
using namespace std;
int main(){
    int r1,r2,c1,c2;
    cout<<"enter the number of rows and column for matrix1:";
    cin>>r1>>c1;
    cout<<"enter the number of rows and column for matrix2:";
    cin>>r2>>c2;
    int arr1[r1][c1],arr2[r2][c2],arr3[r1][c2];
    cout<<"enter the elements of matrix 1:\n";
    for(int i=0;i<r1;i++){
        for (int j=0;j<c1;j++){
            cin>>arr1[i][j];
        }
    }
    cout<<"enter the elements of matrix 2:\n";
    for(int i=0;i<r2;i++){
        for (int j=0;j<c2;j++){
            cin>>arr2[i][j];
        }
    }
    for(int i=0;i<r1;i++){
        for (int j=0;j<c2;j++){
            arr3[i][j]=0;
            for (int k=0;k<c1;k++){
                arr3[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
    cout<<"elements of matrix 3 after multiplication:"<<endl;
    for(int i=0;i<r1;i++){
        for (int j=0;j<c2;j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }


}