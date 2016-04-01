#include<iostream>
#include<stdlib.h>
using namespace std;
int random_partion(int*p,int n){
	int index=rand()%n;
	int temp=p[n-1];
	p[n-1]=p[index];
	p[index]=temp;
	int i=-1;
	for(int j=0;j<n;++j){
		if(p[j]<p[n-1]){
			
			temp=p[++i];
		        p[i]=p[j];
			p[j]=temp;
		}
	}		
		temp=p[++i];
		p[i]=p[n-1];
		p[n-1]=temp;
		return i;
	
}
	int getmaxk(int*p,int n,int k){
		if(k<=0)return -1;
		if(k>n) return -1;
		int i=random_partion(p,n);
		if(i==(n-k)) return p[i];
		else if(i<n-k) return getmaxk(p+i+1,n-i-1,k);
		else return getmaxk(p,i,i+k-n);//   i-(n-k+1)+1
	}
	int main(){
		int a[]={4,6,12,1,8};
		int res=getmaxk(a,5,2);
		/*for(int i=0;i<5;++i)
		cout<<a[i]<<endl;*/
		cout<<res<<endl;
		cin.get();
		return 0;
	}




