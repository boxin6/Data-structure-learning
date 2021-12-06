#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Store
{
	int x;
	int y;
}A[100];
int cnt = 0;
int* top=(int*)malloc(sizeof(int));
int Mg[10][10];
void Push(int x, int y);
void Pop();
void Judge( int x, int y);;
int main()
{
	srand((unsigned)time(NULL));
	*top = -1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0 || j == 0 || i == 9 || j == 9)
			{
				Mg[i][j] = 0;
			}
			else
			Mg[i][j] = rand() % 2;/*0为墙，1为路*/
		}
	}
	int temp1 = rand() % 8 + 1;
	int temp2;
	int temp3;
	while (1)
	{
		temp2 = rand() % 8 + 1;
		temp3 = rand() % 8 + 1 ;
		if (temp2 != temp3)
			break;
	}
	Mg[0][temp1] = 1;
	Mg[9][rand() % 8 + 1] = 1;
	Mg[9][rand() % 8 + 1] = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d ", Mg[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	Push(0, temp1);
	Judge(0, temp1);
	if (*top != -1)
	{
		while (1)
		{
			Mg[A[*top].x][A[*top].y] = 6;
			Pop();
			if (*top == -1)
				break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Mg[i][j] == 0)
				printf("■");
			if (Mg[i][j] == 6)
				printf("★");
			if (Mg[i][j] == 2)
				printf("  ");
			if (Mg[i][j] == 1)
				printf("  ");
		}
		printf("\n");
	}
	if (cnt == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (Mg[i][j] ==6)
				{
					if(i!=9)
					Mg[i][j] = 1;
					else
					Mg[i][j] = 0;
				}
			}
		}
	}
	if (cnt == 1)
	{
		printf("\n");
		Push(0, temp1);
		Judge(0, temp1);
		if (*top != -1)
		{
			while (1)
			{
				Mg[A[*top].x][A[*top].y] = 6;
				Pop();
				if (*top == -1)
					break;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (Mg[i][j] == 0)
					printf("■");
				if (Mg[i][j] == 6)
					printf("★");
				if (Mg[i][j] == 2)
					printf("  ");
				if (Mg[i][j] == 1)
					printf("  ");
			}
			printf("\n");
		}
	}
}
void Push(int x, int y)
{
	if ((*top) == 99)
	{
		printf("ERROR");
	}
	else
	{
		(*top)++;
		A[*top].x = x;
		A[*top].y = y;
	}
}
void Pop()
{
	if ((*top) == -1)
	{
		printf("ERROR1");
	}
	else
	{
		(*top)--;
	}
}
void Judge(int x,int y)
{
	if (x == 9 )
	{
		cnt++;
	}
	else
	{
		if (Mg[x - 1][y] == 1)
		{
			if (x - 1 >= 0)
			{
				Push(x - 1, y);
				Mg[x - 1][y] = 2;/*走过*/
				x--;
				Judge(x, y);
			}
		}
		else if (Mg[x + 1][y] == 1)
		{
			if (x + 1 <= 9)
			{
				Push(x + 1, y);
				Mg[x + 1][y] = 2;/*走过*/
				x++;
				Judge(x, y);
			}
		}
		else if (Mg[x][y - 1] == 1)
		{
			if (y - 1 >= 0)
			{
				Push(x, y - 1);
				Mg[x][y - 1] = 2;/*走过*/
				y--;
				Judge(x, y);
			}
		}
		else if (Mg[x][y + 1] == 1)
		{
			if (y + 1 <= 9)
			{
				Push(x, y + 1);
				Mg[x][y + 1] = 2;/*走过*/
				y++;
				Judge(x, y);
			}
		}
		else if (Mg[x - 1][y] == 6)
		{
			if (x - 1 >= 0)
			{
				Push(x - 1, y);
				Mg[x - 1][y] = 2;/*走过*/
				x--;
				Judge(x, y);
			}
		}
		else if (Mg[x + 1][y] == 6)
		{
			if (x + 1 <= 9)
			{
				Push(x + 1, y);
				Mg[x + 1][y] = 2;/*走过*/
				x++;
				Judge(x, y);
			}
		}
		else if (Mg[x][y - 1] == 6)
		{
			if (y - 1 >= 0)
			{
				Push(x, y - 1);
				Mg[x][y - 1] = 2;/*走过*/
				y--;
				Judge(x, y);
			}
		}
		else if (Mg[x][y + 1] == 6)
		{
			if (y + 1 <= 9)
			{
				Push(x, y + 1);
				Mg[x][y + 1] = 2;/*走过*/
				y++;
				Judge(x, y);
			}
		}
		else
		{
			Pop();
			x = A[*top].x;
			y = A[*top].y;
			if (*top == -1)
			{
				printf("无路可走\n");
			}

			else
				Judge(x, y);
		}
	}
}
