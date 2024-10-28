//上传时间：2024-10-28
//作者：StaryNight2005
//算法描述：递归求逆元

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
