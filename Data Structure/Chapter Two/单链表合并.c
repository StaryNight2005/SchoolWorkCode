//创建日期：2024年10月09日
//创建人：StaryNight2005
//程序说明： 单链表合并, 
//输入示例：8 9
//输出示例：0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16


#include<stdio.h>
#include<stdlib.h>
//单链表定义 
typedef struct line{
	int data;
	struct line* next;
}line,*Line;
//链表创建及初始化 
Line CreateLine_init(int n){
	static int t=0;
	Line head=(Line)malloc(sizeof(line));
	head->data=t++;
	head->next=NULL; 
	{	Line temp=head;
		int i=1;
		for(;i<n;i++){
			Line new_line=(Line)malloc(sizeof(line));
			new_line->data=t++;
			new_line->next=NULL;
			temp->next=new_line;
			temp=temp->next; 
		}
	}
	return head;
}
//链表合并，将hb合并到ha后面 
Line Combine_Line(Line ha,Line hb){
	Line temp=ha;
	while(temp->next){
		temp=temp->next;
	}
	temp->next=hb;
	return ha;
}
//链表展示 -
void Show_Line(Line h){
	Line temp=h;
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
//链表删除 
void Destroy_Line(Line h){
	Line temp;
	while(h->next){
		temp=h->next;
		free(h);
		h=temp;
	}
	free(h);
}


int main(){
	int m,n;
	printf("请输入要创建的ha、hb链表大小：\n");
	scanf("%d %d",&m,&n);
	Line ha=CreateLine_init(m);
	Line hb=CreateLine_init(n);
	printf("单向链表ha：");
	Show_Line(ha);
	printf("单向链表hb：");
	Show_Line(hb);
	//合并前先比较链表长度，将长链表合并到短链表后面，节省时间 
	Line hc=m<n?Combine_Line(ha,hb):Combine_Line(hb,ha);
	printf("合并后链表hc：");
	Show_Line(hc);
	Destroy_Line(hc);
	return 0;
}
