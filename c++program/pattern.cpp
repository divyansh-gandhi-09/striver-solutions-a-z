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
        else{
            for(int k=2*n-1;k>i;k--){
                cout<<"*";
            }
        }
        cout<<endl;
    }

}
void printpattern11(int n){
    int first_value=1;
    for (int i=0;i<n;i++){
        if (i%2==0) first_value=1 ;
        else first_value=0;
        for (int j=0;j<=i;j++){
            cout<<first_value;
            first_value=1-first_value;
        }
        cout<<endl;
    }
}
void printpattern12(int n){

    for(int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            cout<<j+1;
        }
        for (int k=2*n-2;k>2*i;k--){
            cout<<" ";
        
        }
        for (int l=i+1;l>0;l--){
            cout<<l;
        }
        cout<<endl;
    }
}
void printpattern13(int n){
    int count=1;
    for (int i=0;i<n;i++){
        for (int j=0;j<=i;j++){
            cout<<count;
            count++;
        }
        cout<<endl;
    }

}
void printpattern14(int n){
    for (int i=0;i<n;i++){
        for (char j='A';j<='A'+i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}
void printpattern15(int n){
    for (int i=n;i>0;i--){
        for (char j='A';j<'A'+i;j++){
            cout<<j;
        }
        cout<<endl;
    }
}
void printpattern16(int n){
    for (int i=0;i<n;i++){
        char ch='A'+i;
        for (int j=0;j<=i;j++){
            cout<<ch;
        }
        cout<<endl;
    }
}
void printpattern17(int n){
    for (int i=0;i<n;i++){
        for (int j=n;j>i+1;j--){
            cout<<" ";
        }
        for (char ch='A';ch<='A'+i;ch++){
            cout<<ch;
        }
        for (char j='A'+i-1;j>='A';j--){
            cout<<j;
            
        }
        cout<<endl;

    }
}
void printpattern18(int n){
    for (int i=0;i<n;i++){
        for (char ch='A'+n-1-i;ch<=('A'+n-1);ch++)
        {cout<<ch;}
        cout<<endl;
    }
}
void printpattern19(int n){
    for (int i=0;i<2*n;i++){
        if (i<n){
            for (int j=n;j>i;j--){
                cout<<"*";
            }
            for (int k=0;k<2*i;k++){
                cout<<" ";
            }
            for (int l=n;l>i;l--){
                cout<<"*";
            }
        }
        else{
            for (int a=n;a<=i;a++){
                cout<<"*";
            }
            for (int s=2*n-2;s>2*(i-n);s--){
                cout<<" ";
            }
            for (int d=n;d<=i;d++){
                cout<<"*";
            }

        }
        cout<<endl;
   } 
}
void printpattern20(int n){
    for (int i=0;i<2*n-1;i++){
        if (i<n){
            for (int a=0;a<=i;a++){
                cout<<"*";
            }
            for (int s=2*n-2;s>2*(i);s--){
                cout<<" ";
            }
            for (int d=0;d<=i;d++){
                cout<<"*";
            }

        }
        else{
            for (int j=2*n-1;j>i;j--){
                cout<<"*";
            }
            for (int k=0;k<2*(i-n)+2;k++){
                cout<<" ";
            }
            for (int l=2*n-1;l>i;l--){
                cout<<"*";
            }
        }
        cout<<endl;
    }

}
void printpattern21(int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i==0||j==0||i==n-1||j==n-1){
                cout<<"*";
            }
            else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
void printpattern22(int n){
    for (int i=0;i<2*n-1;i++){
        for (int j=0;j<2*n-1;j++){
            int up=i;
            int down=(2*n-2)-i;
            int left=j;
            int right=2*n-2-j;
            int min=up;
            if (down<min) min=down;
            if (left<min) min=left;
            if (right<min) min=right;
            cout<<n-min;
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    printpattern1(n); 
    printpattern2(n);
    printpattern3(n);
    printpattern4(n);
    printpattern5(n);
    printpattern6(n);
    printpattern7(n);
    printpattern8(n);
    printpattern9(n);
    printpattern10(n);
    printpattern11(n);
    printpattern12(n);
    printpattern13(n);
    printpattern14(n);
    printpattern15(n);
    printpattern16(n);
    printpattern17(n);
    printpattern18(n);
    printpattern19(n);
    printpattern20(n);
    printpattern21(n);
    printpattern22(n);
}