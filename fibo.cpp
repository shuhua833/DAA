#include <iostream>
using namespace std;
int main() {

	int f0 = 0,f1 = 1,i,n, temp;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<< f0<<"\t"<<f1;
    for(i=3;i<=n;i++)
    {
       
        temp = f0+f1;
        f0=f1;
        f1=temp;
        cout<<"\t"<<temp;
    }

}
