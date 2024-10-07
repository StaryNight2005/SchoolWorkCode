#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

void Eratos_prime(vector<int>*a,const int num){
	//用vector来存储素数，用num表示要求的范围 
	char is[num+1]={0};
	for(int i=2;i<sqrt(num);i++){
		if(!is[i]){
			for(int j=i;j*i<=num;j++){
				is[i*j]=1;
			}
		}
	}
	for(int i=2;i<num;i++){
		if(!is[i])
		a->push_back(i);
	}
}


int main(){
	vector<int> a;
	const int num=500;
	Eratos_prime(&a,num);
	printf("%d以内的素数共%d个，详细结果如下：\n",num,a.size());
	for(int i=0;i<a.size();i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	
	return 0;
} 
