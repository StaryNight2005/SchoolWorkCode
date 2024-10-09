//创建日期：2024年10月09日
//创建人：StaryNight2005
//程序说明： 删除递增链表中范围元素 
//输入示例：9 1 2 3 4 5 6 7 8 9 4 7
//输出示例：1 2 3 8 9 



#include<stdio.h>
#include<stdlib.h>

typedef struct line{
	int data;
	struct line* next;
}line,*Line;
//创建链表 
Line Create_Line(int n){
	Line head=(Line)malloc(sizeof(line));
	head->next=NULL;
	{int i=1;
	Line temp=head;
	scanf("%d",&temp->data);
	for(;i<n;i++){
		Line new_line=(Line)malloc(sizeof(line));
		new_line->next=NULL;
		scanf("%d",&new_line->data);
		temp->next=new_line;
		temp=new_line;
	}
	}
	return head;
}
//删除链表中区间内数据
void Delete_LineData(Line* h,int a,int b){
	Line temp=*h;
	//如果一开始就满足，那么一开始就开始删除 
	while(temp->data>=a&&temp->data<=b){
	*h=temp->next;
	free(temp);
	temp=*h;
	}
	//先找到要删除的数据 
	Line tt=temp->next;
	while(tt&&tt->data<a){
		temp=temp->next;
		tt=temp->next;
	}
	//temp不动，开始删除 
	while(tt&&tt->data<=b){
		temp->next=tt->next;
		free(tt);
		tt=temp->next;
	}
} 
//链表展示
void Show_Line(Line h){
	Line temp=h;
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
} 

//删除链表
void Destroy_Line(Line h){
	Line temp=h;
	while(h){
		temp=h->next;
		free(h);
		h=temp;
	}
	
} 

int main(){
	int n;
	printf("请输入创建链表大小：");
	scanf("%d",&n);
	printf("请顺序输入链表数据:");
	Line head=Create_Line(n); 
	Show_Line(head);
	printf("请输入要删除的数据范围:");
	int a,b;
	scanf("%d %d",&a,&b);
	Delete_LineData(&head,a,b);
	printf("删除后链表:");
	Show_Line(head);
	Destroy_Line(head);
	 
	return 0;
}
