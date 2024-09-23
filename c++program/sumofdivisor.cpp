#include<bits\stdc++.h>
using namespace std;
int main(){
    int choice,N;
    cout<<"enter the choice:";
    cin>>choice;
    cout<<"enter the value of N";
    cin>>N;
    long long total_sum=0;
    int sum=0;
    switch (choice){
        case 1:
            for (int i=1;i<=N;i++){
                cout<< "less optimal";
                sum=0;
                for (int j=1;j<sqrt(i);j++){
                    if (i%j==0){
                        sum+=j;
                    }
                    if (j!=i/j){
                        sum+=i/j;
                    }
                }
                total_sum+=sum;
                break;
            }
        case 2:
            cout<<"better method";
            for(int i=1;i<=N;i++){
                total_sum+=i*(N/i);
            }
            break;
        default:
            cout<<"wrong choice";
    }
    cout<<"total_sum is "<<total_sum;
}