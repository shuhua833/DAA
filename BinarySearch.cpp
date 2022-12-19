#include <iostream>
using namespace std;
class Binary{
    public:
    int a[20],i,n,key;
    void getdata();
    void search();
    void binarysearch(int A[],int beg,int end,int data);
};
void Binary::getdata(){
    cout<<"Enter array size:";
    cin>>n;
    cout<<"Enter array elements";
    for(i=0;i<n;i++)
    cin>>a[i];
}
void Binary::search(){
    cout<<"Enter the search element";
    cin>>key;
    binarysearch(a,0,n-1,key);
}
void Binary:: binarysearch(int A[],int beg,int end,int data)
{
int mid;
if(beg<=end)
{
mid = (beg + end)/2;
if(A[mid] == data)
{
printf("data found at location: %d ",mid+1);
}
else
{
if(data <A[mid])
binarysearch(A,beg,mid-1,data);
else
binarysearch(A,mid+1,end,data);
}}
else
printf("\nData Not Found "); }

int main()
{
    Binary obj;
    obj.getdata();
    obj.search();
}
