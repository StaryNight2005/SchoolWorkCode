//作业7：根据定义求欧拉函数
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
	cout<<endl<<n<<"的欧拉函数为："<<primeNum<<endl;
	cout<<"与"<<n<<"互素的数为：";
	for(i=0;i<Euler.size();i++){
		cout<<Euler[i]<<" ";
	}
}
