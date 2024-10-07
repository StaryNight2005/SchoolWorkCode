//作业6：算术基本定理
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int>prime;
void getprime(int num){
	char is[num+1]={};
	for(int i=2;i<=sqrt(num);i++){
		if(!is[i]){
			for(int j=i;j*i<=num;j++){
				is[i*j]=1;
			}
		}
	}
	for(int i=2;i<=num;i++){
		prime.push_back(i);
	}
}

vector<int> decompose(int num){
	getprime(sqrt(num));
	int i=0;
	vector<int>pn;
	while(i<=prime.size()){
		if(num%prime[i]==0)
		num/=prime[i],pn.push_back(prime[i]);
		else
		i++;
	}
	return pn;
}
int main(){
	int num;
	cout<<"Please input a number:"<<endl;
	cin>>num;
	vector<int>pn=decompose(num);
	cout<<endl<<num<<"=";
	for(int i=0;i<pn.size()-1;i++)
	cout<<pn[i]<<" * ";
	cout<<pn[pn.size()-1];
}
