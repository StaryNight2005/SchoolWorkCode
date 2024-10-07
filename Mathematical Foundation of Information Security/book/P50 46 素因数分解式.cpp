#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> prime;

void prime_get(int num){
	//存入num+1以内素数到prime中 
	char is[num+1]={};
	int n;
	if(!prime.size())
	prime.push_back(2);
		for(int i=2;i<=sqrt(num+1);i++){
			if(!is[i]){
				for(int j=i;i*j<=num;j++)
					is[i*j]=1;
			}
		}
		for(int i=prime[prime.size()-1]+1;i<=num;i++)
		if(!is[i])
		prime.push_back(i);
}
int is_prime(int num){
	prime_get(num);
	for(int i=0;i<prime.size();i++){
		if(num==prime[i])
		return 1;
		if(num<prime[i])
		return 0;
	}
	return 0;
} 

void decompose(int a){
	cout<<a<<"=";
	while(!is_prime(a)){
		for(int i=0;i<prime.size();i++){
			if(a%prime[i]==0){
				cout<<prime[i]<<"*";
				a/=prime[i];
				break;
			}
		}
	}
	cout<<a<<endl;
}

int main(){
	int a[4]={36,69,200,289}; 
	for(int i=0;i<4;i++)
		decompose(a[i]);
	
	return 0;
}
