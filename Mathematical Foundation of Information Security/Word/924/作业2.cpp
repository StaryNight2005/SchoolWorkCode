//作业2：证明N为素数
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int> prime;

void primeget(int num){
	if(!prime.size())
	prime.push_back(2);
	char is[num+1]={};
	for(int i=2;i<sqrt(num);i++){
		if(!is[i]){
			for(int j=i;j*i<=num;j++){
				is[i*j]=1;
			}
		}
	}
	for(int i=prime[prime.size()-1]+1;i<=num;i++)
	if(!is[i])
	prime.push_back(i);
} 

int main(){
	int num=0;
	while(num<=2){
		cout<<"Please input a number:\n";
	cin>>num;
	}
	cout<<"解：因为小于等于sqtr<N>="<<int(sqrt(num))<<"的所有素数为：";
	primeget(sqrt(num));
	for(int i=0;i<prime.size();i++)
	cout<<prime[i]<<","; 
	cout<<"所以依次用上述素数去试除："<<endl<<endl; 
	for(int i=0;i<prime.size();i++){
		cout<<num<<"="<<prime[i]<<"*"<<num/prime[i]<<"+"<<num%prime[i]<<endl; 
	}
	cout<<endl<<"根据定理9的推论，上述素数都不能整除"<<num<<".根据定理7，N="<<num<<"为素数\n"; 
	return 0;
} 
