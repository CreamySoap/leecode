#include<iostream>
#include<string>
using namespace std;
int getnext(int *next,string T){
	next[0]=0;int k=0;//k max perfixes and suffixes
	for(int i=1;i<T.size();++i){
		// since the second char;
		while(k>0&&T[i]!=T[k])
			k=next[k-1];
		if(T[i]==T[k])
			++k;
		next[i]=k;
	}

}

int kmp(string S,string T,int *next){
	int j=0;
	for(int i=0;i<S.size();++i){
		while(j>0&&T[j]!=S[i])
			j=next[j-1];
				if(T[j]==S[i])
					++j;
				if(j==T.size()){
					cout<<"OK"<<endl;
					return 0;
						}
	}
				return -1;

}

int main(){
	string s="ABCDABE";
	string t="DAB";
	int next[3]={0};
	getnext (next,t);
	return kmp(s,t,next);
}
