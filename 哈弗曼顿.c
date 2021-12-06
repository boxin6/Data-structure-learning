#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tree
{
	int weight;
	int parent;
	int lchild;
	int rchild;
};
int judge(char a, char b[2][50], int n);
int count(char a[500], char b, int n);
int main()
{
	char Date[500];
	scanf("%s", &Date);
	int lenth;
	lenth= strlen(Date);
	char a[2][50];
	int cnt = 0;
	for (int i = 0; i < lenth; i++)
	{
		if (judge(Date[i],a,cnt) == 0)
		{
			a[0][cnt] = Date[i];
			a[1][cnt] = count(Date, a[0][cnt], lenth) + '0';
			cnt++;
		}
	}
	a[0][cnt] = '\0';
	a[1][cnt] = '\0';
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < cnt-i-1; j++)
		{
			if (a[1][j] - '0' > a[1][j + 1] - '0')
			{
				char temp1 = a[0][j];
				char temp2 = a[1][j];
				a[0][j]= a[0][j+1];
				a[1][j]= a[1][j+1];
				a[0][j + 1] = temp1;
				a[1][j + 1] = temp2;
			}
		}
		
	}
	int cnn = 2*cnt-1;
	struct tree hamden[50];
	for (int i = 0; i < cnt; i++)
	{
		hamden[i] = { a[1][i] - '0',0,0,0 };
	}
	for (int i = cnt; i < cnn; i++)
	{
		hamden[i] = { 0,0,0,0 };
	}
	for (int i = cnt; i < cnn; i++)
	{
		int min =0, mmin = 0;
		int min1 = 99, mmin1 = 99;
		for (int j = 0; j < i; j++)
		{
			if (mmin1 > hamden[j].weight && hamden[j].parent == 0)
			{
				mmin = j;
				mmin1 = hamden[j].weight;
			}
			if (min1 > hamden[j].weight && hamden[j].parent == 0)
			{
				if (mmin != j)
				{
					min = j;
					min1 = hamden[j].weight;
				}
			}

		}
		hamden[i].weight = hamden[mmin].weight + hamden[min].weight;
		hamden[i].lchild = mmin;
		hamden[i].rchild = min;
		hamden[mmin].parent = i;
		hamden[min].parent = i;
	}
	for (int i = 0; i < cnn; i++)
	{
		printf("%d %d %d %d\n", hamden[i].weight, hamden[i].parent, hamden[i].lchild, hamden[i].rchild);
	}
	printf("\n");
	char cd[50];
	char res[50][50];
	int u = 0;
	int v = 0;
	for (int i = 0; i < cnt; i++)
	{
		int start= 0;
		int c = i;
		int p = hamden[i].parent;
		v = 0;
		while (p != 0)
		{
			if (hamden[p].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = p;
			p = hamden[p].parent;
			start++;
		}
		cd[start] = '\0';
		int len = strlen(cd);
		for (int i = len - 1; i >= 0; i--)
		{
			res[u][v++] = cd[i];
		}
		res[u++][v] = '\0';
	}
	for (int i = 0; i < cnt; i++)
	{
		printf("%c的编码是: %s\n", a[0][i], res[i]);
	}
	printf("编码后结果:");
	for (int i = 0; i < lenth; i++)
	{
		for (int j = 0; j < cnt; j++)
		{
			if (Date[i] == a[0][j])
			{
				printf("%s", res[j]);
			}
		}
	}
}

int judge(char a, char b[2][50],int n)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a == b[0][i])
			cnt++;
	}
	if (cnt == 0)
		return 0;
	else
		return 1;
}
int count(char a[500], char b, int n)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b)
			cnt++;
	}
	return cnt;
}
/*
	首先用字符串接受字符，接着遍历，获取每个字符的权值，排序，接着创建静态链表
	有cnt不同的字符，创建2*cnt-1个空间的静态链表
	初始化前cnt项，将权值附上
	后面的进行初始化归0
	接着每次遍历前i-1个节点，每次找权值最小的两个，将父节点定为i
	i的左为最小权值节点 右为次小权值节点
	i的权值为最小和次小之和
	生成二叉树后，逐个遍历前cnt个节点，回到根，用当前节点和父节点进行比较编码
	编码为反序，进行处理获得正序编码
	建立一定对应关系，输出各个字符的编码
	最后遍历字符串，一一对应编码输出
	over
*/
