#include<stdio.h>
int main(){
	int f0 = 0,f1 = 1,i,n, temp;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	printf("%d,%d ", f0,f1);
    for(i=3;i<=n;i++)
    {
       
        temp = f0+f1;
        f0=f1;
        f1=temp;
        printf(",%d\t",temp);
    }
}
