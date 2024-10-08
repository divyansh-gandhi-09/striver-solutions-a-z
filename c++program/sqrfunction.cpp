#include<bits\stdc++.h>
using namespace std;
template <class T>
inline T square(T x){
    T result;
    result=x*x;
    return result;
}
int main(){
    int i,ii;
    float x,xx;
    double y,yy;
    i=2;
    x=2.2;
    y=2.2222;
    ii=square<int>(i);
    cout<<i<<":"<<ii<<endl;
    xx=square<float>(x);
    cout<<x<<":"<<xx<<endl;
    yy=square<double>(y);
    cout<<y<<":"<<yy<<endl;
    cout<<"implicit use of template "<<endl<<"yy=square(y):";
    yy=square(y);
    cout<<y<<":"<<yy<<endl;
    return 0;


}