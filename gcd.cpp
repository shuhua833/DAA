#include <iostream>
using namespace std;
void GCD(int,int);
int main() {

	int m,n;
	cout<<"Enter two numbers: ";
	cin>>m>>n;
	GCD(m,n);
}
void GCD(int m,int n){
    int rem;
    if(n==0)
	cout<<m<<" is the GCD";
	else if(m==0)
	cout<<n<<" is the GCD";
	else{
	    while(n!=0){
	        rem=m%n;
	        m=n;
	        n=rem;
	    }
	    cout<<m<<" is the GCD";
	}
}
