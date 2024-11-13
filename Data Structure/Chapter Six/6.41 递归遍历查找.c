//创建日期：2024年11月13日
//创建人：StaryNight2005
//程序说明： 递归查找先序遍历第k个位置的结点的值 
//输入示例：3 12 23 46 81 22 32 11 5
//输出示例：22



#include<stdio.h>
#include<stdlib.h>

typedef struct BinTree {
	int num;
	struct BinTree* Parent;
	struct BinTree* Left;
	struct BinTree* Right;
}bin, * Bin;

//创建新节点 
Bin CreateCode(Bin Par, int num) {
	Bin newcode = (Bin)malloc(sizeof(bin));

	newcode->Parent = Par;
	newcode->num = num;
	newcode->Left = NULL;
	newcode->Right = NULL;

	return newcode;
}

//递归建立n层完全满二叉树 
void CreateTree(Bin* Tree, int n) {
	if (n == 0) {
		return;
	}

	int num;


	if (*Tree == NULL) {
		printf("输入新增节点:");
		scanf("%d", &num);
		*Tree = CreateCode(NULL, num);
		n--;
	}

	//递归建立左子树 
	if ((*Tree)->Left == NULL) {
		printf("输入新增节点:");
		scanf("%d", &num);
		(*Tree)->Left = CreateCode(*Tree, num);
		CreateTree(&((*Tree)->Left), n - 1);//左子树为根建立新树 
	}

	//递归建立右子树 
	if ((*Tree)->Right == NULL) {
		printf("输入新增节点:");
		scanf("%d", &num);
		(*Tree)->Right = CreateCode(*Tree, num);
		CreateTree(&((*Tree)->Right), n - 1);//右子树为根建立新树 
	}
}

//查找先序遍历第n个节点的值 
int FindCode(Bin Tree,int index){
	static int n = 1;
	int res;

	//根节点 
	if(n == index){
		n = 1;
		return Tree->num;
	}
	else{
		n++;
		//左节点 
		if(Tree->Left){
			res = FindCode(Tree->Left, index);
			
			if(res)
				return res;
		}
			
		//右节点 
		if(Tree->Right){
			res = FindCode(Tree->Right, index);
			
			if(res)
				return res;
		}
		
	} 
}

//释放树 
void DestroyTree(Bin* Tree){
	
	//释放左子树 
	if((*Tree)->Left){
		DestroyTree(&((*Tree)->Left));
		
		(*Tree)->Left = NULL;
	}
	
	//释放右子树 
	if((*Tree)->Right){
		DestroyTree(&(*Tree)->Right);
		
		(*Tree)->Right = NULL;
	}
	
	//释放自己 
	if((*Tree)->Left == NULL && (*Tree)->Right == NULL){
		free(*Tree);
	}
} 

int main() {

	Bin tree = NULL;
	int high, num;
	
	printf("请输入创建的树的高度:");
	scanf("%d", &high);

	CreateTree(&tree, high);
	
	printf("请输入要查找的节点：");
	scanf("%d", &num);
	
	printf("%d\n",FindCode(tree, num));
	
	DestroyTree(&tree); 
	
	return 0;
}
