#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void prove(){
	cout<<"֤����"<<endl;
	cout<<"������p������������q��ʹ��q|p\n";
	cout<<"�����kʹ��p=kq"<<endl;
	cout<<"���ԣ�2^p-1=2^(kq)-1=(2^q-1)*(2^((k-1)q)+2^((k-2)q)+...+2^q+1)\n";
	cout<<"(2^((k-1)q)+2^((k-2)q)+...+2^q+1)Ϊ����\n";
	cout<<"���ԣ�2^q-1|2^p-1"<<endl;
	cout<<"��pΪ��������qֻ��Ϊp��1\n";
	cout<<"��ֻ��2^1-1=1|2^p-1��2^p-1|2^p-1"<<endl;
	cout<<"��2^p-1ֻ��1��������Ϊ��������\n";
	cout<<"���ԣ���n=pΪ������a=2ʱ��a^n-1Ϊ����"<<endl; 
	
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
	//���ǰnum��Mersenne����
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
	cout<<"ǰ"<<num<<"��Mersenne����Ϊ��\n";
	for(int i=0;i<5;i++)
	cout<<Mersenne[i]<<" ";
	return 0;
}
