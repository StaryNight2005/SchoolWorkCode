//上传时间：2024-10-28
//作者：StaryNight2005
//算法说明：中国剩余定理实现

#include <stdio.h>
#include <stdlib.h>

//求a和b的最大公约数，若a和b互素，则s为a模b的逆元，t为b模a的逆元 
int gcd_(int a, int b,int *s,int *t){
	
	//能被整除，直接返回最大公约数 
	if(a%b==0){
		
		*s = 1; 
		*t = a/b;
		
		return b;	
	}
	
	
	if(a%b == 1 || b%(a%b)==0){//到底初始化 
		*s = 1;
		*t = -a/b;
	}
	else{
		gcd_(b,a%b,s,t);//递归到底初始化，然后自下而上返回 
	
		int temp = *t;
		*t = *s - a/b*(*t);
		*s = temp;
	}
	return *s * a + *t * b;
}

//中国剩余定理，输入数组和模数 
int CRT(int a[], int m[], int n){
	int* M = (int*)malloc(sizeof(int) * n);
	int* M_ = (int*)malloc(sizeof(int) * n);//逆元 
	int MM = 1;
	int i;
	int x;
	
	//大 
	for (i = 0; i < n; i++){
		MM *= m[i];
	}
	
	//衍 
	for (i = 0; i < n; i++){
		M[i] = MM/m[i];
		int t;
		gcd_(M[i], m[i], &M_[i], &t);
	}
	
	//求一
	for (i = 0; i < n; i++){
		x = (x + a[i] * M[i] * M_[i]) % MM;
	} 
	
	//术 
	return x;
	
}

int main(){
	int s,t;
	int b[] = {1, 3, 5};
	int m[] = {7, 5, 9};
	
	//测试最大公约数 
	printf("\n%d\n",gcd_(3, 26, &s, &t));
	
	//测试逆元 
	printf("%d %d\n",s,t);
	
	//测试中国剩余定理 
	printf("\n%d", CRT(b, m, 3));
	
	
	return 0;
}
