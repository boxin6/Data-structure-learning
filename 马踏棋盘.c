#include <stdio.h>
struct list
{
	int x;
	int y;
}stack[70];
int top = -1;
int A[8][8];
void Push(int x, int y);
list Pop();
void horse(int x, int y);
int panduan(int x, int y);
int search(int a[10]);
int main()
{
	int x, y;
	int cnt=0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			A[i][j] = 0;
		}
	}
	printf("请输入起始位置\n");
	scanf("%d %d", &x, &y);//起始位置
	A[x][y] = 1;
	Push(x, y);
	//开始判断
	horse(x, y);
	int nizhi[2][64];
	int i = 63;
	while (1)
	{
		list temp = Pop();
		A[temp.x][temp.y] =top+2;
		nizhi[0][i] = temp.x;
		nizhi[1][i] = temp.y;
		i--;
			if (top == -1)
				break;
	}
	for (int i = 0; i < 64; i++)
	{
		printf("[%02d,%02d] -> ", nizhi[0][i], nizhi[1][i]);
		if ((i+1) % 8 == 0)
			printf("\n");
	}
	printf("\n");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%02d ", A[i][j]);

		}
		printf("\n");
	}

}
void Push(int x, int y)
{
	if (top == 63)
		printf("ERROE");
	else
	{
		top++;
		stack[top].x = x;
		stack[top].y = y;
	}
}
list Pop()
{
	if (top == -1)
		printf("ERROE");
	{
		top--;
		return stack[top+1];
	}
}
void horse(int x, int y)
{
	int his[10];
	his[9] = 10;
	int ppp = 0;
	while (1)
	{
		int a = 0;
		int cnt=0;
		cnt = 0;
		int min = 0;
		if (top == 62)
		{
			if (panduan(x - 2, y + 1) == 1)//1号点
			{
				if (A[x - 2][y + 1] == 0)
				{
					Push(x - 2, y + 1);
					break;
				}
			}
			if (panduan(x - 1, y + 2) == 1)//2号点
			{
				if (A[x - 1][y + 2] == 0)
				{
					Push(x - 1, y + 2);
					break;
				}
			}
			if (panduan(x + 1, y + 2) == 1)//3号点
			{
				if (A[x + 1][y + 2] == 0)
				{
					Push(x + 1, y + 2);
					break;
				}
			}
			if (panduan(x + 2, y + 1) == 1)//4号点
			{
				if (A[x + 2][y + 1] == 0)
				{
					Push(x + 2, y + 1);
					break;
				}
			}
			if (panduan(x + 2, y - 1) == 1)//5号点
			{
				if (A[x + 2][y - 1] == 0)
				{
					Push(x + 2, y - 1);
					break;
				}
			}
			if (panduan(x + 1, y - 2) == 1)//6号点
			{
				if (A[x + 1][y - 2] == 0)
				{
					Push(x + 1, y - 2);
					break;
				}
			}
			if (panduan(x - 1, y - 2) == 1)//7号点
			{
				if (A[x - 1][y - 2] == 0)
				{
					Push(x - 1, y - 2);
					break;
				}
			}
			if (panduan(x - 2, y - 1) == 1)//8号点
			{
				if (A[x - 2][y - 1] == 0)
				{
					Push(x - 2, y - 1);
					break;
				}
			}
		}
		else
		{
			if (panduan(x - 2, y + 1) == 1 )//1号点
			{
				if (A[x - 2][y + 1] == 1)
				{

				}
				else
				{
					int temp1,temp2;
					temp1 = x-2 ;
					temp2 = y+1 ;
					if (panduan(temp1-2, temp2+1) == 1)//1号点
					{
						if (A[temp1-2][temp2+1]==0)
						{
							cnt++;
						}
				    }
					 if (panduan(temp1-1, temp2+2) == 1)//2号点
					 {
						if ( A[temp1-1][temp2+2] == 0)
						{
							cnt++;
						}
					 }
					 if (panduan(temp1 + 1, temp2 + 2) == 1)//3号点
					 {
						if ( A[temp1 + 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					 }
					 if (panduan(temp1 + 2, temp2 + 1) == 1)//4号点
					 {
						 if ( A[temp1 + 2][temp2 + 1] == 0)
						 {
							 cnt++;
						 }
					 }
					 if (panduan(temp1 + 2, temp2 - 1) == 1)//5号点
					 {
						 if ( A[temp1 + 2][temp2 - 1] == 0)
						 {
							 cnt++;
						 }
					 }
					 if (panduan(temp1 + 1, temp2 - 2) == 1)//6号点
					 {
						 if (A[temp1 + 1][temp2 - 2] == 0)
						 {
							 cnt++;
						 }
					 }
					 if (panduan(temp1 - 1, temp2 - 2) == 1)//7号点
					 {
						 if (A[temp1 - 1][temp2 - 2] == 0)
						 {
							 cnt++;
						 }
					 }
					 if (panduan(temp1 - 2, temp2 - 1) == 1)//8号点
					 {
						 if (A[temp1 - 2][temp2 - 1] == 0)
						 {
							 cnt++;
						 }
					 }
				}
			}
			his[a] = cnt;
			if (cnt != 0)
				min = a;
			else
				min = 9;
			cnt = 0;
			a++;
			if (panduan(x - 1, y + 2) == 1)//2号点
			{
				if (A[x - 1][y + 2] == 1)
				{

				}
				else
				{
					int temp1, temp2;
					temp1 = x - 1;
					temp2 = y + 2;
					if (panduan(temp1 - 2, temp2 + 1) == 1)//1号点
					{
						if (A[temp1 - 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 + 2) == 1)//2号点
					{
						if (A[temp1 - 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 + 2) == 1)//3号点
					{
						if (A[temp1 + 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 + 1) == 1)//4号点
					{
						if (A[temp1 + 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 - 1) == 1)//5号点
					{
						if (A[temp1 + 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 - 2) == 1)//6号点
					{
						if (A[temp1 + 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 - 2) == 1)//7号点
					{
						if (A[temp1 - 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 2, temp2 - 1) == 1)//8号点
					{
						if (A[temp1 - 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
				}
			}
			his[a] = cnt;
			if (cnt != 0)
			{
				if(his[a]==0)
				{ }
				else if (his[min] > his[a])
					min = a;
			}
			cnt = 0;
			a++;
			if (panduan(x + 1, y + 2) == 1)//3号点
			{
				if (A[x + 1][y + 2] == 1)
				{

				}
				else
				{
					int temp1, temp2;
					temp1 = x + 1;
					temp2 = y + 2;
					if (panduan(temp1 - 2, temp2 + 1) == 1)//1号点
					{
						if (A[temp1 - 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 + 2) == 1)//2号点
					{
						if (A[temp1 - 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 + 2) == 1)//3号点
					{
						if (A[temp1 + 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 + 1) == 1)//4号点
					{
						if (A[temp1 + 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 - 1) == 1)//5号点
					{
						if (A[temp1 + 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 - 2) == 1)//6号点
					{
						if (A[temp1 + 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 - 2) == 1)//7号点
					{
						if (A[temp1 - 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 2, temp2 - 1) == 1)//8号点
					{
						if (A[temp1 - 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
				}
			}
			his[a] = cnt;
			if (cnt != 0)
			{
				if (his[a] == 0)
				{
				}
				else if (his[min] > his[a])
					min = a;
			}
			cnt = 0;
			a++;
			if (panduan(x + 2, y + 1) == 1)//4号点
			{
				if (A[x+2][y + 1] == 1)
				{

				}
				else
				{
					int temp1, temp2;
					temp1 = x + 2;
					temp2 = y + 1;
					if (panduan(temp1 - 2, temp2 + 1) == 1)//1号点
					{
						if (A[temp1 - 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 + 2) == 1)//2号点
					{
						if (A[temp1 - 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 + 2) == 1)//3号点
					{
						if (A[temp1 + 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 + 1) == 1)//4号点
					{
						if (A[temp1 + 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 - 1) == 1)//5号点
					{
						if (A[temp1 + 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 - 2) == 1)//6号点
					{
						if (A[temp1 + 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 - 2) == 1)//7号点
					{
						if (A[temp1 - 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 2, temp2 - 1) == 1)//8号点
					{
						if (A[temp1 - 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
				}
			}
			his[a] = cnt;
			if (cnt != 0)
			{
				if (his[a] == 0)
				{
				}
				else if (his[min] > his[a])
					min = a;
			}
			cnt = 0;
			a++;
			if (panduan(x + 2, y - 1) == 1)//5号点
			{
				if (A[x + 2][y - 1] == 1)
				{

				}
				else
				{
					int temp1, temp2;
					temp1 = x + 2;
					temp2 = y - 1;
					if (panduan(temp1 - 2, temp2 + 1) == 1)//1号点
					{
						if (A[temp1 - 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 + 2) == 1)//2号点
					{
						if (A[temp1 - 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 + 2) == 1)//3号点
					{
						if (A[temp1 + 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 + 1) == 1)//4号点
					{
						if (A[temp1 + 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 - 1) == 1)//5号点
					{
						if (A[temp1 + 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 - 2) == 1)//6号点
					{
						if (A[temp1 + 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 - 2) == 1)//7号点
					{
						if (A[temp1 - 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 2, temp2 - 1) == 1)//8号点
					{
						if (A[temp1 - 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
				}
			}
			his[a] = cnt;
			if (cnt != 0)
			{
				if (his[a] == 0)
				{
				}
				else if (his[min] > his[a])
					min = a;
			}
			cnt = 0;
			a++;
			if (panduan(x + 1, y - 2) == 1)//6号点
			{
				if (A[x + 1][y - 2] == 1)
				{

				}
				else
				{
					int temp1, temp2;
					temp1 = x + 1;
					temp2 = y - 2;
					if (panduan(temp1 - 2, temp2 + 1) == 1)//1号点
					{
						if (A[temp1 - 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 + 2) == 1)//2号点
					{
						if (A[temp1 - 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 + 2) == 1)//3号点
					{
						if (A[temp1 + 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 + 1) == 1)//4号点
					{
						if (A[temp1 + 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 - 1) == 1)//5号点
					{
						if (A[temp1 + 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 - 2) == 1)//6号点
					{
						if (A[temp1 + 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 - 2) == 1)//7号点
					{
						if (A[temp1 - 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 2, temp2 - 1) == 1)//8号点
					{
						if (A[temp1 - 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
				}
			}
			his[a] = cnt;
			if (cnt != 0)
			{
				if (his[a] == 0)
				{
				}
				else if (his[min] > his[a])
					min = a;
			}
			cnt = 0;
			a++;
			if (panduan(x - 1, y - 2) == 1)//7号点
			{
				if (A[x - 1][y - 2] == 1)
				{

				}
				else
				{
					int temp1, temp2;
					temp1 = x - 1;
					temp2 = y - 2;
					if (panduan(temp1 - 2, temp2 + 1) == 1)//1号点
					{
						if (A[temp1 - 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 + 2) == 1)//2号点
					{
						if (A[temp1 - 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 + 2) == 1)//3号点
					{
						if (A[temp1 + 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 + 1) == 1)//4号点
					{
						if (A[temp1 + 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 - 1) == 1)//5号点
					{
						if (A[temp1 + 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 - 2) == 1)//6号点
					{
						if (A[temp1 + 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 - 2) == 1)//7号点
					{
						if (A[temp1 - 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 2, temp2 - 1) == 1)//8号点
					{
						if (A[temp1 - 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
				}
			}
			his[a] = cnt;
			if (cnt != 0)
			{
				if (his[a] == 0)
				{
				}
				else if (his[min] > his[a])
					min = a;
			}
			cnt = 0;
			a++;
			if (panduan(x - 2, y - 1) == 1)//8号点
			{
				if (A[x - 2][y - 1] == 1)
				{

				}
				else
				{
					int temp1, temp2;
					temp1 = x - 2;
					temp2 = y - 1;
					if (panduan(temp1 - 2, temp2 + 1) == 1)//1号点
					{
						if (A[temp1 - 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 + 2) == 1)//2号点
					{
						if (A[temp1 - 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 + 2) == 1)//3号点
					{
						if (A[temp1 + 1][temp2 + 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 + 1) == 1)//4号点
					{
						if (A[temp1 + 2][temp2 + 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 2, temp2 - 1) == 1)//5号点
					{
						if (A[temp1 + 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 + 1, temp2 - 2) == 1)//6号点
					{
						if (A[temp1 + 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 1, temp2 - 2) == 1)//7号点
					{
						if (A[temp1 - 1][temp2 - 2] == 0)
						{
							cnt++;
						}
					}
					if (panduan(temp1 - 2, temp2 - 1) == 1)//8号点
					{
						if (A[temp1 - 2][temp2 - 1] == 0)
						{
							cnt++;
						}
					}
				}
			}
			his[a] = cnt;
			if (cnt != 0)
			{
				if (his[a] == 0)
				{
				}
				else if (his[min] > his[a])
					min = a;
			}
			cnt = 0;
			a++;
			if ( his[min] == 0)
				Pop();
			else
			{
				if (min == 0)
				{
					x = x - 2;
					y = y + 1;
					A[x][y] = 1;
					Push(x, y);
				}
				else if (min == 1)
				{
					x = x - 1;
					y = y + 2;
					A[x][y] = 1;
					Push(x, y);
				}
				else if (min == 2)
				{
					x = x + 1;
					y = y + 2;
					A[x][y] = 1;
					Push(x, y);
				}
				else if (min == 3)
				{
					x = x + 2;
					y = y + 1;
					A[x][y] = 1;
					Push(x, y);
				}
				else if (min == 4)
				{
					x = x + 2;
					y = y - 1;
					A[x][y] = 1;
					Push(x, y);
				}
				else if (min == 5)
				{
					x = x + 1;
					y = y - 2;
					A[x][y] = 1;
					Push(x, y);
				}
				else if (min == 6)
				{
					x = x - 1;
					y = y - 2;
					A[x][y] = 1;
					Push(x, y);
				}
				else if (min == 7)
				{
					x = x - 2;
					y = y - 1;
					A[x][y] = 1;
					Push(x, y);
				}
			}
		}
	}
}
int panduan(int x, int y)
{
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
		return 1;//在棋盘返回1
	else
		return -1;//不在棋盘返回-1
}
