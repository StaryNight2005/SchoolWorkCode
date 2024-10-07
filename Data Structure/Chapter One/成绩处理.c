//创建日期：2024年10月7日
//创建人：StaryNight2005
//程序说明：对10名同学成绩求最高分最低分和平均分 
//输入示例：93 85 72 73 69 57 76 99 34 88
//输出示例：
//最高分:99 
//最低分：34 
//平均分：75 

#include<stdio.h>

int main(){
	int grade;
	int max=-1,min=999;//存储最高最低成绩
	float ave=0;//存储平均分
	int i=0; 
	for(;i<10;i++){
		printf("请输入第%d位同学成绩:\n",i+1);//提醒输入成绩
		scanf("%d",&grade); 
		ave+=grade;
		max=max>grade?max:grade;
		min=min<grade?min:grade;
	} 
	ave/=10;
	printf("最高分：%d\n最低分：%d\n平均分：%.f",max,min,ave);//输出最高分、最低分、平均分 
	return 0;
} 
