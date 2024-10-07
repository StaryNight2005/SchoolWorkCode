//创建日期：2024年10月7日
//创建人：StaryNight2005
//程序说明：创建线性表并将其中内容逆置（以整型线性表为例） 
//输入示例：7 8 5 3 2 9 6 8
//输出示例：8 6 9 2 3 5 8



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
	p->data[p->len++]=a;
}

void showLine(line* p){
	//数据表内容展示 
	int i;
	for(i=0;i<p->len;i++)
		printf("%d ",p->data[i]);
	printf("\n");
}

void reverse(line* p){
	int i=0,j=p->len-1;
	while(i!=j){
		if(p->data[i]!=p->data[j]){
			p->data[i]^=p->data[j];
			p->data[j]^=p->data[i];
			p->data[i]^=p->data[j];
		}
		i++;
		j--;
	}
} 

int main(){
	
	line p=CreatLine();//创建线性表
	
	
	printf("请输入要逆置的线性表长度：\n");//提示用户创建数据表 
	int n;
	scanf("%d",&n);
	printf("请输入要逆置的线性表内容:\n");
	int i;
	for(i=0;i<n;i++){
		int data;
		scanf("%d",&data);
		Insert(&p,data);
	}
	
	reverse(&p);
	
	printf("逆置后的线性表：\n");//展示逆置后的结果 
	showLine(&p);
	
	DestroyLine(&p);//释放线性表中内存 
	return 0;
}
