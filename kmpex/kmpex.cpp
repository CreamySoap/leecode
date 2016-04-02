#include<iostream>
#include<string>
using namespace std;
int initnext(int *next,string t){
	int k=-1,i=0,m=t.size();next[0]=-1;
	while(i<m-1){
	if(k==-1||t[i]==t[k]){
		++k;
		++i;
		if(t[i]!=t[k])
		next[i]=k;
		else
		next[i]=next[k];
	}
		else
		k=next[k];

			}
}

int kmpex(string s,string t,int*next){
	int i=0,j=0,slen=s.size(),tlen=t.size();
	while(i<slen&&j<tlen){
		if(j==-1||s[i]==t[j]){
			++i;
			++j;

		}
		else j=next[j];
	}
	if(j==tlen)
	       return i-j;
      else return -1;	
}
int main(){
	string s="BBC ABCDAB ABCDABCDABDE";
	string t="ABCDABD";
	int next[7]={0};
	initnext(next,t);
	cout<<kmpex(s,t,next)<<endl;

}








