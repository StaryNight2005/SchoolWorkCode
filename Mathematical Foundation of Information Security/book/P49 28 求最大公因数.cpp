#include<iostream>
using namespace std;

int gcd(int m,int n){
	if(m<n){
		m^=n;
		n^=m;
		m^=n;
	} 
	while(m%n){
		int temp=m;
		m=n;
		n=temp%n;
	}
	return n;
} 

int main(){
	int a[4]={55,202,666,20785};
	int b[4]={85,282,1414,44350};
	for(int i=0;i<4;i++){
		cout<<"gcd("<<a[i]<<","<<b[i]<<")="<<gcd(a[i],b[i])<<endl;
	}
	return 0;
}
