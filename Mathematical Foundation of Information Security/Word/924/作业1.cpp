//用爱拉托斯散筛法求出N以内的全部素数 
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int> prime;
void simple_primeget(int num){
	if(!prime.size())
	prime.push_back(2);
	char is[num+1]={};
	for(int i=2;i<sqrt(num);i++){
		if(!is[i])
		for(int j=i;j*i<=num;j++)
		is[j*i]=1;
	}
	for(int i=prime[prime.size()-1]+1;i<num;i++)
	if(!is[i])
	prime.push_back(i);
}

void prime_get(int num){
	cout<<"解：因为小于等于sqrt<N>="<<sqrt(num)<<"的所有素数为：";
	simple_primeget(sqrt(num));
	char is[num+1]={};
	for(int i=0;i<prime.size();i++)
	cout<<prime[i]<<",";
	cout<<"依次删除上述素数的倍数：\n\n";
	for(int i=0;i<prime.size();i++){
		cout<<"对于素数p"<<i+1<<"="<<prime[i]<<",删除：\n";
		for(int j=prime[i];j*prime[i]<=num;j++){
			if(!is[prime[i]*j]){
				is[prime[i]*j]=1;
			cout<<prime[i]*j<<" ";
			}
		}
		cout<<endl<<endl;
	}
	for(int i=prime[prime.size()-1]+1;i<=num;i++)
	if(!is[i])
	prime.push_back(i); 
}

int main(){
	cout<<"input a num:";
	int num;
	cin>>num;
	prime_get(num);
	cout<<"\n所以不超过N="<<num<<"的素数有：\n";
	for(int i=0;i<prime.size();i++)
	cout<<prime[i]<<" ";
	return 0;
}
 
