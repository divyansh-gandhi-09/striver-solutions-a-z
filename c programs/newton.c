#include <stdio.h>
#include<math.h>
float function(float x){
    return x*x*x-x-2;
}
float derivative(float x){
    return 3*x*x-1;
}
void newtonRaphson(float x0,int iteration){
    float x1,fx0,fdx0;
    int iter;
    for (iter=1;iter<=iteration;iter++){
        fx0=function(x0);
        fdx0=derivative(x0);
        x1=x0-fx0/fdx0;
        printf("iteration %d: x=%f\n",iter,x1);
        x0=x1;

    }
    printf("after %d iteration approx root is:%f ",iteration,x1);
}
int main(){
    float a,b,x0;
    printf("enter two initial values:");
    scanf("%f%f",&a,&b);
    float fa=function(a);
    float fb=function(b);
     if (fabs(fa) < fabs(fb)) {
        x0=a;
    } else if (fabs(fb) < fabs(fa)) {
        x0=b;
    } else {
        x0=a;
    }
    printf("%f\n",x0);
    int iteration;
    printf("Enter the number of iterations: ");
    scanf("%d", &iteration);

    printf("Using Newton-Raphson method to find root of equation x^3 - x - 2 = 0\n");
    newtonRaphson(x0, iteration);

    return 0;
}


