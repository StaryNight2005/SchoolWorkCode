//��ҵ2��֤��NΪ����
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
	cout<<"�⣺��ΪС�ڵ���sqtr<N>="<<int(sqrt(num))<<"����������Ϊ��";
	primeget(sqrt(num));
	for(int i=0;i<prime.size();i++)
	cout<<prime[i]<<","; 
	cout<<"������������������ȥ�Գ���"<<endl<<endl; 
	for(int i=0;i<prime.size();i++){
		cout<<num<<"="<<prime[i]<<"*"<<num/prime[i]<<"+"<<num%prime[i]<<endl; 
	}
	cout<<endl<<"���ݶ���9�����ۣ�������������������"<<num<<".���ݶ���7��N="<<num<<"Ϊ����\n"; 
	return 0;
} 
