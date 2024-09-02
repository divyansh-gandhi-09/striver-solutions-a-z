# include<bits\stdc++.h>
using namespace std;
class Complex_sum{
    private:
        float real;
        float imaginary;
    public:
     Complex_sum(){
            real=0;
            imaginary=0;
        }
     Complex_sum(float r,float i){
            real=r;
            imaginary=i;
        }
     Complex_sum(const Complex_sum &c1,const Complex_sum &c2){
            real=c1.real+c2.real;
            imaginary=c1.imaginary+c2.imaginary;
        }
        void display() const{
            cout<<real<<"+("<<imaginary<<")i"<<endl;
        }
};
int main(){
    float r1,r2,i1,i2;
    cout<<"enter the real and imaginary part of Complex no 1:";
    cin>>r1>>i1;
    cout<<"enter the real and imaginary part of Complex no 2:";
    cin>>r2>>i2;
    Complex_sum c1(r1,i1);
    Complex_sum c2(r2,i2);
    Complex_sum c3(c1,c2);
    cout<< "Comple number1:\n";
    c1.display();
    cout<< "Complex number2:\n";
    c2.display();
    cout<< "sum of the complex number:\n";
    c3.display();
}
