//创建日期：2024年10月09日
//创建人：StaryNight2005
//程序说明： 创建频率双链表，每次查询时会将查询到的链表块频率加一，链表按频率降序 
//输入示例：5 3 3 2 4 1 1 -1
//输出示例：
//频率 数据
//2		1
//2		3
//1		4
//1		2
//0 	5



#include<stdio.h>
#include<stdlib.h>

typedef struct line{
	int freq;
	int data;
	struct line* prior;
	struct line* next;
}line,*Line;
//链表创建和初始化 
Line Create_Line(int n){
	Line head=(Line)malloc(sizeof(line));
	head->prior=NULL;
	head->next=NULL;
	{int i=1;
	head->freq=0;
	head->data=i;
	Line temp=head;
	for(;i<n;i++){
		Line new_line=(Line)malloc(sizeof(line));
		new_line->prior=temp;
		new_line->next=NULL;
		new_line->freq=0;
		new_line->data=i+1;
		temp->next=new_line;
		temp=new_line;
	}
	}
	return head; 
}
//链表数据定位 
Line LOCATE(Line*L,int d){
	Line temp=*L;
	if(!*L)
	return NULL;//空指针返回空
	//找到定位数据 
	while(temp&&temp->data!=d){
		temp=temp->next;
	}
	//找到后处理 
	if(temp&&temp->data==d){
		temp->freq++;
		//准备交换 
		Line pr=temp->prior;
		while(pr&&temp->freq>=pr->freq){
			if(pr->prior)
			pr->prior->next=temp;
			if(temp->next)
			temp->next->prior=pr;
			
			temp->prior=pr->prior;
			pr->next=temp->next;
			pr->prior=temp;
			temp->next=pr;
			pr=temp->prior;
		}
		//头指针移到最前 
		while((*L)->prior)
		*L=(*L)->prior;
		return temp;
	}
	//未找到返回空指针 
	return NULL;
}
//展示链表内容：频率、数据 
void Show_Line(Line* head){
	Line temp=*head;
	printf("频率\t数据\n");
	while(temp){
		printf("%d \t%d\n",temp->freq,temp->data);
		temp=temp->next;
	}
	printf("\n");
}
//链表释放 
void Destroy_Line(Line* head){
	Line temp=(*head)->next;
	while(temp){
		free(*head);
		*head=temp;
		temp=temp->next;
	}
	free(*head);
}


int main(){
	int n;
	printf("请输入要创建的频率双链表长度\n");
	scanf("%d",&n);
	Line head=Create_Line(n);
	Show_Line(&head);
	int q=1;
	while(q!=-1){
		printf("请输入要查询的数字（-1退出）\n");
		scanf("%d",&q);
		LOCATE(&head,q);
	}
	printf("查询后链表\n");
	Show_Line(&head);
	Destroy_Line(&head);
	return 0;
}
