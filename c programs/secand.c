#include <stdio.h>
float quadratic_eq(float x){
    return x*x-4;
}
int main(){
    int n;
    float a,b,c,fa,fb,fc;
    printf("Enter the number of iteration:");
    scanf("%d",&n);
    up:
        
        printf("enter 2 initial values :");
        scanf("%f%f",&a,&b);
        fa=quadratic_eq(a);
        fb=quadratic_eq(b);
        if (fa*fb<0){
            printf("approximate root of the given equation:-\n");
            for (int i=0;i<n;i++){
                c=(a*fb-b*fa)/(fb-fa);
                fc=quadratic_eq(c);
                if (fa*fc<0){
                    b=c;
                }
                else{
                    a=c;
                }
                printf("%f\n",c);
                 
            }
            
        }
        else if(fa*fb==0){
            if ((fa==0 && fb==0)){
                printf("roots of the given equation are %f,%f",a,b);
            }
            else if (fa==0){
                printf("root of the given eqation is %f",a);
            }
            else {
                printf("root of the given eqation is %f",b);
            }

        }
        else{
            printf("wrong initial values\n");
            goto up;

        }
        return 0;
       

}