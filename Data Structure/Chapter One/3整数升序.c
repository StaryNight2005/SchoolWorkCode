//创建日期：2024年10月7日
//创建人：StaryNight2005
//程序说明：模拟冒泡法从小到大排序三个整数 
//输入示例：9 1 2
//输出示例：1 2 9

#include<stdio.h>

void swap(int* x,int* y){
	//交换函数
	if(*x==*y)
	return;
	*x^=*y;
	*y^=*x;
	*x^=*y;//位运算快速交换整型数据 
} 

int main(){
	int x,y,z;
	printf("请输入x，y，z的值：\n");//提醒输入x，y，z内容 
	scanf("%d %d %d",&x,&y,&z);
	//模拟冒泡法排序 
	if(x>y)
	swap(&x,&y);
	if(y>z)
	swap(&y,&z);
	if(x>y)
	swap(&x,&y);
	
	printf("%d %d %d",x,y,z);
	return 0;
}
