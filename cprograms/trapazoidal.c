#include<stdio.h>
float function(float x){
    return x*x+1;
}
//function to calculate the approx integral using trapezoidal rule
float trapezoidal(float a ,float b,int n){
    float h=(b-a)/n;
    float sum=(function(a)+function(b))/2;
    for (int i=1;1<n;i++){
        sum+=function(a+i*h);
    }
    return (sum*h);
}
int main(){
    float a,b;
    int n;
    printf("enter lower limit a:");
    scanf("%f",&a);
    printf("enter upper limit b:");
    scanf("%f",&b);
    printf("Enter the number of intervals n: ");
    scanf("%d", &n);
    float result =trapezoidal(a,b,n);
    printf("The approximate value of the integral is: %f\n", result);
    return 0;
}