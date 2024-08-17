#include <bits/stdc++.h>
using namespace std;
void printpattern1(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<4;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    printpattern1(n);

}