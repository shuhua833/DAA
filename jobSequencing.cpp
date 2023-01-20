#include<iostream>
#include <algorithm>
using namespace std;
class jobSequencing{
	private:
		int n,i,j,d[20],p[20],slot[20],x,job[20],sum=0;
	public:
		void input(){
				cout<<"Enter total jobs";
		cin>>n;
		cout<<"Enter  profit and deadline";
		for(i=0;i<n;i++)
		{
			job[i]=i+1;
			cin>>p[i];
			cin>>d[i];
		}
		}
	  void sortJobs(){
	  		for(i=0;i<n-1;i++){
	  			for(j=0;j<n-1-i;j++){
	  				if(p[j]<p[j+1])
	  				{
	  					swap(p[j],p[j+1]);
	  					swap(d[j],d[j+1]);
	  					swap(job[j],job[j+1]);
					  }
				  }
			  }
	  		
	  }
	  void assignSlots(){
	    int max = d[0]; // to find maximum deadline
     for ( i = 1; i < n; i++) {
        if (d[i] > max) {
            max = d[i];
        }
    }
	  	for(i=0;i<=max;i++){
	  		slot[i]=0;
		  }
		  
		  for(i=0;i<n;i++){
		  	
		  	x=d[i];
		  
			  	for(j=x;j>0;j--){
			  		if(slot[j]==0){
			  			slot[j]=job[i];
			  			sum+=p[i];
			  			break;
					  }
				  }
			  }
		  
		  }
	  

	void display(){
		
		for(i=1;i<n;i++){
			cout<<endl<<"J"<<slot[i]<<"-->";
		}
		cout<<"Total profit ="<<sum;
	}
};
int main(){
	jobSequencing j;
	j.input();
	j.sortJobs();
	j.assignSlots();
	j.display();
}
