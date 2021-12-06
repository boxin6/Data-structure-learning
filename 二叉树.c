#include <stdio.h>
#include <stdlib.h>
struct tree* stact [50];
int cnt = -1;
int tail = 0,head=0;
struct tree
{
	char date;
	struct tree* lchild;
	struct tree* rchild;
};
struct tree* creattree(struct tree* node);
void Postorder(struct tree* node);
void Middleorder(struct tree* node);
void Push(struct tree* node);
struct tree* Pop();
void Join(struct tree* node);
struct tree* out();
void arrangement(struct tree* node);
int main()
{
	struct tree *root=NULL;
	printf("请以先序输入数据:\n");
	root=creattree(root);
	printf("\n");
	printf("按后序遍历打印输出:\n");
	Postorder(root);
	printf("\n");
	printf("按中序遍历打印输出:\n");
	Middleorder(root);
	printf("\n");
	printf("按层次遍历打印输出:\n");
	arrangement(root);
	
}
struct tree* creattree(struct tree* node)
{
	char temp;
	temp = getchar();
	if (temp == ' ')
	{
		node = NULL;
	}
	else
	{
		node = (struct tree*)malloc(sizeof(struct tree));
		node->date = temp;
		node->lchild=creattree(node->lchild);
		node->rchild=creattree(node->rchild);
	}
	return node;
}
void Postorder(struct tree* node)
{
	if (node != NULL)
	{
		Postorder(node->lchild);
		Postorder(node->rchild);
		printf("%c",node->date);
	}
}
void Middleorder(struct tree* node)
{
	struct tree *temp = node;
	while (temp!= NULL ||cnt!=-1)
	{
		while (temp)
		{
			Push(temp);
			temp = temp->lchild;
		}
		if (cnt != -1)
		{
			temp = Pop();
			printf("%c", temp->date);
			temp = temp->rchild;
		}
	}
}
void Push(struct tree* node)
{
	stact[++cnt] = node;
}
struct tree* Pop()
{
	return stact[cnt--];
}
void Join(struct tree* node)
{
	stact[tail++] = node;
}
struct tree* out()
{
	return stact[head++];
}
void arrangement(struct tree* node)
{
	struct tree* temp;
	temp = node;
	Join(temp);
	while (head != tail)
	{
		temp = out();
		printf("%c", temp->date);
		if (temp->lchild != NULL)
		{
			Join(temp->lchild);
		}
		if (temp->rchild != NULL)
		{
			Join(temp->rchild);
		}
	}
}
/*
建立二叉树时，使用递归思想拓展建立，若为‘ ’则为NULL，节点不存在，否则开辟新空间，存入数据
若为先序 则先存，后左右
若为中序 先左 再存 后右
若为后序 先左右 再存
 */

/* 
后序遍历，使用递归思想，先一直访问左，再一直访问右边，最后打印根数据
*/

/*
非递归遍历，中序输出，中序为 左根右 需要借助栈 先访问左直至空  如果栈不为空，出栈，打印数据 再访问右节点
*/

/*
按层次遍历时，借助队列，，先让根入队 再进入循环 出队 每次出队时让左右节点入队，同时打印当前节点数据即可
*/


