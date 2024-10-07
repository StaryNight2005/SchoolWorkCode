//创建日期：2024年10月7日
//创建人：StaryNight2005
//程序说明：创建升序线性表并向其中插入内容（以整型线性表为例） 
//输入示例：12
//输出示例;1 2 3 4 5 6 7 8 9 10 11 12 12 13 14 15 16 17 18 19 20 



#include<stdio.h>
#include<stdlib.h>
#define InitLen 20
#define AddLen 10

typedef struct{
	int *data;
	int len;
	int cap;
}line;

line CreatLine(){
	//创建线性表 
	line p;
	p.data=(int*)malloc(InitLen*sizeof(int));
	int i;
	for(i=0;i<InitLen;i++)
		p.data[i]=0;
	p.len=0;
	p.cap=InitLen;
	return p;
}

void DestroyLine(line *p){
	//销毁线性表 
	if(p->data){
		free(p->data);
		p->cap=0;
		p->len=0;
	}
}

void Insert(line* p,int a){
	//数据插入 
	if(p->len>=p->cap){
		int* tem=(int*)realloc(p->data,sizeof(int)*(p->cap+AddLen));
		if(tem){
			p->data=tem;
			p->cap+=AddLen;
		}
	}
	int i=0;
	while(p->data[i]<a&&i<p->len){
		i++;
	}
	int j;
	for(j=p->len;j>i;j--)
		p->data[j]=p->data[j-1];
	p->data[i]=a;
	p->len++;
}

void showLine(line* p){
	//数据表内容展示 
	int i;
	for(i=0;i<p->len;i++)
		printf("%d ",p->data[i]);
	printf("\n");
}

int main(){
	
	line p=CreatLine();//创建线性表
	{int i;
	for(i=0;i<InitLen;i++)
		Insert(&p,i+1);
	 } //初始化一组数据 
	printf("初始线性表:\n");
	showLine(&p); //展示初始化后的线性表 
	
	printf("请输入要插入的数据:\n");//提醒用户插入数据 
	int data;
	scanf("%d",&data);
	Insert(&p,data);
	
	printf("插入数据后线性表：\n");//展示插入后的结果 
	showLine(&p);
	
	
	DestroyLine(&p);//释放线性表中内存 
	return 0;
}
