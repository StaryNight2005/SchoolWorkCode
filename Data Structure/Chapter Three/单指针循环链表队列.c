//创建日期：2024年10月28日
//创建人：StaryNight2005
//程序说明： 以带头结点的循环链表表示队列，只设一个指针指向队尾元素节点，实现队列初始化、入队列、出队列 
//输入示例：7 12
//输出示例：1 2 3 4 5 6 7  1 2 3 4 5 6 7 12   3 4 5 6 7 12



#include <stdio.h>
#include <stdlib.h>

//结构体定义 
typedef struct line{
	int data;
	struct line* next;
}line,*Line;

//链表初始化
Line InitLine(){
	Line l = (Line)malloc(sizeof(line));
	l->data = 0;
	l->next = l;
	return l;
	
} 

//链表块创建
Line CreatLine(int n){
	Line l = (Line)malloc(sizeof(line));
	l->data = n;
	l->next = NULL;
	return l;
} 

//入队列
void PushLine(Line* tail,int n){
	Line temp = CreatLine(n);
	temp->next = (*tail)->next;
	(*tail)->next = temp;
	*tail = temp;
} 

//出队列
void PopLine(Line* tail){
	Line temp = (*tail)->next;
	(*tail)->next = temp->next;
	free(temp);
} 

//循环打印队列 
void PrintLine(Line* tail){
	Line temp = (*tail)->next;
	while(temp != *tail){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("%d",temp->data);
}

//队列释放 
void DestroyLine(Line* tail){
	//将链表先优化为单链表 
	Line temp = *tail;
	(*tail)->next = NULL;
	*tail = temp->next;
	
	//单链表释放 
	while(*tail){
		free(temp);
		temp = *tail;
		*tail = temp->next;
	}
	free(temp);
	
}

int main(){
	//创建循环链表 
	Line tail = InitLine();
	int n;
	int i;
	int data;
	
	//初始化循环链表
	printf("请输入循环链表大小\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		PushLine(&tail,i+1);
	}
	PopLine(&tail);
	PrintLine(&tail);
	
	//功能测试 
	printf("\n请输入插入队列中数据\n");
	scanf("%d",&data);
	PushLine(&tail,data);
	printf("插入数据后队列:");
	PrintLine(&tail);
	
	PopLine(&tail);
	PopLine(&tail);
	printf("\n出队列两次后队列:");
	PrintLine(&tail);
	
	
	
	DestroyLine(&tail); 
	return 0;
}
