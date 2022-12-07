#include <iostream>
using namespace std;
void LinearSearch(int [],int,int);
int main() {
    int i, key,n,A[30];
    cout<<"Enter the total number of array elements:";
    cin>>n;
    cout<<"Enter the array elements:";
    for(i=1;i<=n;i++){
        cin>>A[i];
    }
    cout<<"Enter the search element:";
    cin>>key;
    LinearSearch(A,n,key);
}
void LinearSearch(int A[],int n,int key){
    int flag=0,index;
    for(int i=1;i<=n;i++){
     if(key==A[i])
     {
        flag =1; 
        index = i;
     }
    }
    if(flag==1)
    cout<<"Search element found at index "<<index;
    else
    cout<<"Search element not found";
}

