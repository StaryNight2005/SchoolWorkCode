//��ҵ5�����ù���ŷ����ó��������Լ��
#include<iostream>
using namespace std;

int gcd(int a,int b){
	if(a<b){
		a^=b;
		b^=a;
		a^=b;
	}
	while(b!=0){
		cout<<a<<" = "<<a/b<<" * "<<b<<" + "<<a%b<<endl;
		int temp=a;
		a=b;
		b=temp%b;
	}
	return a;
} 

int main(){
	int a,b;
	cout<<"Please input two number:"<<endl;
	cin>>a>>b;
	cout<<"����ŷ����ó������У�\n"<<endl; 
	int g=gcd(a,b);
	cout<<endl<<"���ԣ����ݶ���4��("<<a<<","<<b<<")="<<g;
	return 0;
}
