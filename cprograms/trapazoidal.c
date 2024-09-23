#include<stdio.h>
double function(double x){
    return x*x+1;
}
//function to calculate the approx integral using trapezoidal rule
double trapezoidal(double a ,double b,int n){
    double h=(b-a)/n;
    double sum=(function(a)+function(b))/2;
    for (int i=1;1<n;i++){
        sum+=function(a+i*h);
    }
    return sum*h;
}
int main(){
    double a,b;
    int n;
    printf("enter lower limit a:");
    scanf("%lf",&a);
    printf("enter upper limit b:");
    scanf("%lf",&b);
    printf("Enter the number of intervals n: ");
    scanf("%d", &n);
    double result =trapezoidal(a,b,n);
    printf("The approximate value of the integral is: %.6f\n", result);
    return 0;
}