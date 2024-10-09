//创建日期：2024年10月09日
//创建人：StaryNight2005
//程序说明： 将混有多种元素的列表进行分离 
//输入示例：9 s13b*&k/9
//输出示例：sbk 139 *&/ 



#include<stdio.h>
#include<stdlib.h>

typedef struct line{
	char data;
	struct line* next;
}line,*Line;

Line Create_Line(int n){
	Line head=(Line)malloc(sizeof(line));
	head->next=NULL;
	printf("请输入列表内容:\n");
	scanf(" %c",&head->data);
	{int i=1;
	Line temp=head;
	for(;i<n;i++){
		Line new_line=(Line)malloc(sizeof(line));
		new_line->next=NULL;
		scanf(" %c",&new_line->data);
		temp->next=new_line;
		temp=new_line;
	}
	}
	return head;
}
//链表数据筛查 
void Line_Filter(Line* head,Line* ha,Line* hb,Line* hc){
	if(!*ha)
	*ha=(Line)malloc(sizeof(line));
	if(!*hb)
	*hb=(Line)malloc(sizeof(line));
	if(!*hc)
	*hc=(Line)malloc(sizeof(line));
	Line hha,hhb,hhc;
	hha=*ha;
	hhb=*hb;
	hhc=*hc;
	while(*head){
		if((*head)->data>='A'&&(*head)->data<='Z'||(*head)->data>='a'&&(*head)->data<='z'){
			hha->next=*head;
			hha=hha->next;
		}
		else if((*head)->data>='0'&&(*head)->data<='9'){
			hhb->next=*head;
			hhb=hhb->next;
		}
		else{
			hhc->next=*head;
			hhc=hhc->next;
		}
		*head=(*head)->next;
	}
	hha->next=hhb->next=hhc->next=NULL;
	hha=*ha;
	*ha=hha->next;
	free(hha);
	hhb=*hb;
	*hb=hhb->next;
	free(hhb);
	hhc=*hc;
	*hc=hhc->next;
	free(hhc);
}
//链表展示
void Show_Line(Line*const head){
	Line temp=*head;
	while(temp){
		printf("%c ",temp->data);
		temp=temp->next;
	}
	printf("\n");
} 

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
	printf("请输入混合链表长度：\n");
	scanf("%d",&n);
	Line head=Create_Line(n);
	Line ha,hb,hc;
	ha=hb=hc=NULL;
	Line_Filter(&head,&ha,&hb,&hc);
	printf("字母链表：\n");
	Show_Line(&ha);
	printf("数字链表：\n");
	Show_Line(&hb);
	printf("其他字符链表：\n");
	Show_Line(&hc);
	Destroy_Line(&ha);
	Destroy_Line(&hb);
	Destroy_Line(&hc);
	
	return 0;
}
