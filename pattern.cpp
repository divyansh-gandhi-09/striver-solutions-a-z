#include <bits/stdc++.h>
using namespace std;
void printpattern1(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void printpattern2(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void printpattern3(int n){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}
void printpattern4(int n){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;

    }

}
void printpattern5(int n){
    for (int i=0;i<n;i++){
        for (int j=n;j>i;j--){
            cout<<"*";
        }
        cout<<endl;

    }

}
void printpattern6(int n){
    for (int i=n;i>0;i--){
        for (int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<endl;

    }

}
void printpattern7(int n){
    for (int i=0;i<n;i++){
        for (int j=n;j>i+1;j--){
            cout<<" ";
        }
        for (int k=0;k<2*i+1;k++){
            cout<<"*";
        }
        
        cout<<endl;
    }
}
void printpattern8(int n){
    for (int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for (int k=2*n-1;k>2*i;k--){
            cout<<"*";
        }
        cout<<endl;
    }
}
void printpattern9(int n){
    printpattern7(n);
    printpattern8(n);

}
void printpattern10(int n){
    for (int i=0;i<2*n-1;i++){
        if (i<n){
            for (int j=0;j<=i;j++){
                cout<<"*";
            }

        }
        // else{
        //     for(int k=2*n-1;k>i;k--){
        //         cout<<"*";
        //     }
        // }
        // cout<<endl;
    }


}
int main(){
    int n;
    cin>>n;
    printpattern10(n); 
    
}