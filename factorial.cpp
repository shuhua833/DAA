#include <iostream>
using namespace std;
int factorial(int);
int main() {

	int n;
	cout<<"Enter a number: ";
	cin>>n;
	cout<<"Factorial of "<<n<<"\tis\t"<<factorial(n);
}
int factorial(int n){
    if(n==0)
    return 1;
    else{
    int fact=1;
    for(int i=1;i<=n;i++)
    {
        fact=fact *i;
    }
    return fact;
    }
}
