#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void prove(){
	cout<<"证明："<<endl;
	cout<<"对整数p，若存在整数q，使得q|p\n";
	cout<<"则存在k使得p=kq"<<endl;
	cout<<"所以，2^p-1=2^(kq)-1=(2^q-1)*(2^((k-1)q)+2^((k-2)q)+...+2^q+1)\n";
	cout<<"(2^((k-1)q)+2^((k-2)q)+...+2^q+1)为整数\n";
	cout<<"所以，2^q-1|2^p-1"<<endl;
	cout<<"若p为素数，则q只能为p或1\n";
	cout<<"则只有2^1-1=1|2^p-1和2^p-1|2^p-1"<<endl;
	cout<<"即2^p-1只有1和它本身为它的因子\n";
	cout<<"所以，当n=p为素数，a=2时，a^n-1为素数"<<endl; 
	
}
vector<int> prime;
void prime_get(int num){
	int t=2;
	while(prime.size()<=num){
		int flag=1;
		for(int i=2;i<=sqrt(t);i++){
			if(t%i==0){
				flag=0;
				break;
			}
		}
		if(flag)
		prime.push_back(t);
		t++;
	}
}
vector<long long> Mersenne;
void Mersenne_prime(int num){
	//获得前num个Mersenne素数
	prime_get(num);
	for(int i=0;i<num;i++){
		Mersenne.push_back(pow(2,prime[i])-1);
	}
}

int main(){
	prove();
	cout<<endl;
	int num=5;
	Mersenne_prime(num);
	cout<<"前"<<num<<"个Mersenne素数为：\n";
	for(int i=0;i<5;i++)
	cout<<Mersenne[i]<<" ";
	return 0;
}
