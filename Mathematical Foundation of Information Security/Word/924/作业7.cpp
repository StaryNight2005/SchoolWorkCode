//��ҵ7�����ݶ�����ŷ������
#include<iostream>
#include<vector>
using namespace std;
vector<int>Euler;

int gcd(int a,int b){
	if(a<b){
		a^=b;
		b^=a;
		a^=b;
	}
	while(b!=0){
		int temp=a;
		a=b;
		b=temp%b;
	}
	return a;
}

int main(){
	cout<<"Please input a number:"<<endl;
	int n;
	cin>>n;
	int i=0;
	int primeNum=0;
	while(i<n){
		if(gcd(i,n)==1){
			primeNum++;
			Euler.push_back(i);
		}
		i++;
	}
	cout<<endl<<n<<"��ŷ������Ϊ��"<<primeNum<<endl;
	cout<<"��"<<n<<"���ص���Ϊ��";
	for(i=0;i<Euler.size();i++){
		cout<<Euler[i]<<" ";
	}
}
