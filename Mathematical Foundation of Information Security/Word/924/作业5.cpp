//作业5：运用广义欧几里得除法求最大公约数
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
	cout<<"运用欧几里得除法，有：\n"<<endl; 
	int g=gcd(a,b);
	cout<<endl<<"所以，根据定理4，("<<a<<","<<b<<")="<<g;
	return 0;
}
