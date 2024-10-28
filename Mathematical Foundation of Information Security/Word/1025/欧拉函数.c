//上传时间：2024-10-28
//作者：StaryNight2005
//算法描述：三种方法求欧拉函数


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

//辗转相除法求最大公约数 
int gcd(int a,int b){
	while(b != 0){
		int c = a;
		a = b;
		b = c % b;
	}
	return a;
}

//素数筛获取素数，返回素数 
int* prime_filter(int n){
	char* flag = (char*)malloc(sizeof(char) * (n + 1));//判断是否是素数 
	int* prime = (int*)malloc(sizeof(int) * (n + 1));//存储素数，0位存储长度 
	memset(flag, 0, (n + 1) * sizeof(char));
	memset(prime,0, (n + 1) * sizeof(int));
	
	int i = 2;
	for (; i <= sqrt(n); i++){
		if(!flag[i]){//如果是素数
			int j = i;
			for (;j * i <= n; j++){
				flag[i * j] = 1;
			} 
		}
	}
	
	for (i = 2; i <= n; i++){
		if (!flag[i]){
			prime[0]++;
			prime[prime[0]] = i;
//			printf("%d ",i);
		}
	}
	
	free(flag);
	prime = (int *)realloc(prime, (prime[0] + 1) * sizeof(int)); //优化内存 
	
	return prime;
}

//方法1：定义 
int Euller_1(int n){
	int i = 2;
	int count = 1;
	
	for (; i < n; i++){
		if (gcd(i, n) == 1){
			count++;
		}
	}
	
	return count;
}

//方法2：当其为互不相等的素数的乘积时，返回欧拉函数值，否则返回-1 
int Euller_2(int n){
	int* prime = prime_filter(n);//获取小于n的所有素数
	int num = 1;
	int i;
	
	for (i = 1; i <= prime[0]; i++){
		if( n % (prime[i] * prime[i]) == 0){//如果最高次幂不为1，return -1 
			return -1;
		}
		else{
			if(n % prime[i] ==0){
//				printf("%d\n",prime[i]);
				num *= prime[i] - 1;
			}
		}
	} 
	
	
	free(prime);
	
	return num; 
}

//方法3：利用公式分解求值 
int Euller_3(int n){
	int* prime = prime_filter(n);//获取小于n的所有素数
	int num = n;
	int i;
	
	for(i = 1; i <=prime[0]; i++){
		if(n % prime[i] == 0)
			num = num * (prime[i] - 1) / prime[i]; 
		while( n % prime[i] ==0){
			n /= prime[i];
		}
	}
	
	free(prime);
	return num;	
}

int main(){
	int nn;
	
	scanf("%d", &nn);
	
	printf("%d\n", Euller_1(nn));
	printf("%d\n", Euller_2(nn)); 
	printf("%d", Euller_3(nn));
	
	return 0;
} 
