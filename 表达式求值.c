#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <graphics.h>
#include <windows.h>
#include <conio.h>
char* creat(int *top);
void Push(char* stact,int* top,char temp);
char Pop(char* stact, int* top);
char GetTop(char* stact, int* top);
int main()
{
	/*initgraph(550, 640);

	setfillcolor(DARKGRAY);
	solidcircle(50,250,40);
	solidcircle(160, 250, 40);
	solidcircle(270, 250, 40);

	setfillcolor(BROWN);
	solidcircle(380, 250, 40);

	setfillcolor(DARKGRAY);
	solidcircle(50, 350, 40);
	solidcircle(160, 350, 40);
	solidcircle(270, 350, 40);

	setfillcolor(BROWN);
	solidcircle(380, 350, 40);

	setfillcolor(DARKGRAY);
	solidcircle(50, 450, 40);
	solidcircle(160, 450, 40);
	solidcircle(270, 450, 40);

	setfillcolor(BROWN);
	solidcircle(380, 450, 40);

	setfillcolor(DARKGRAY);
	solidcircle(50, 550, 40);

	setfillcolor(BROWN);
	solidcircle(380, 550, 40);
	solidcircle(490, 550, 40);
	solidcircle(490, 450, 40);
	solidcircle(490, 350, 40);
	solidcircle(490, 250, 40);
	solidcircle(160, 550, 40);
	solidcircle(270, 550, 40);

	settextcolor(WHITE);
	settextstyle(55, 55, _T("仿宋"));
	setbkmode(TRANSPARENT);
	outtextxy(25, 520, _T("0"));
	outtextxy(135, 540, _T("^"));
	outtextxy(245, 520, _T("S"));
	outtextxy(340, 520, _T("("));
	outtextxy(475, 520, _T(")"));

	outtextxy(25, 420, _T("1"));
	outtextxy(135, 420, _T("2"));
	outtextxy(245, 420, _T("3"));

	outtextxy(25, 320, _T("4"));
	outtextxy(135, 320, _T("5"));
	outtextxy(245, 320, _T("6"));

	outtextxy(25, 220, _T("7"));
	outtextxy(135, 220, _T("8"));
	outtextxy(245, 220, _T("9"));*/

	int* top = (int*)malloc(sizeof(int));
	*top = -1;
	char* change = creat(top);
	char list[100];
	char  link[100];
	int j = 0;
	scanf("%s", &list);
	int len = strlen(list);
	for (int t = 0; t < len; t++)
	{
		if (list[t] == 's')/*s为平方根号*/
		{
			int a=0;
			int temp = 0;
			if ((list[t + 1] >='0' && list[t + 1] <='9'&& (list[t + 2] < '0' || list[t + 2] > '9'))||list[2]=='\0')
			{
				a = int(list[t + 1] - '0');
				 temp = sqrt(a);
			}
			else if ((list[t + 1] >= '0' && list[t + 1] <='9'&& list[t + 2] >= '0' && list[t + 2] <= '9'&&(list[t + 3] < '0' || list[t + 3] > '9')) || list[3] == '\0')
			{
				a = int(list[t + 1] - '0');
				a=a*10+ int(list[t + 2] - '0');
				 temp = sqrt(a);
			}
			else if (list[t + 1] >= '0' && list[t + 1] <= '9' && list[t + 2] >= '0' && list[t + 2] <= '9' && list[t + 3] >= '0' && list[t + 3] <= '9')
			{
				a = int(list[t + 1] - '0');
				a = a * 10 + int(list[t + 2] - '0');
				a = a * 10 + int(list[t + 3] - '0');
				temp = sqrt(a);
			}
			if (temp >= 0 && temp <= 9 && a>=0&&a<=9)
			{
				list[t] = char(temp + '0');
				if (list[t + 2] == '\0')
				{
					list[t + 1] = '\0';
					break;
				}
				else if (list[t + 3] == '\0')
				{
					list[t + 1] = ')';
					list[t + 2] = '\0';
					break;
				}
				else
				{
					for (int j = t + 1; j < len; j++)
					{
						list[j] = list[j + 1];
					}
					break;
				}
			}
			else if (temp >= 0 && temp <= 9 && a >=10 && a <= 99)
			{
				list[t] = char(temp + '0');
				if (list[t + 3] == '\0')
				{
					list[t + 1] = '\0';
					break;
				}
				else if (list[t + 4] == '\0')
				{
					list[t + 1] = ')';
					list[t + 2] = '\0';
					break;
				}
				else
				{
					for (int j = t + 1; j < len; j++)
					{
						list[j] = list[j + 1];
					}
					break;
				}
			}
			else if (temp >= 10 && temp <= 99 && a >= 100 && a <= 999)
			{
				list[t] = char(temp/10 + '0');
				list[t+1] = char(temp%10 + '0');
				if (list[t + 4] == '\0')
				{
					list[t + 2] = '\0';
					break;
				}
				else if (list[t + 5] == '\0')
				{
					list[t + 2] = ')';
					list[t + 3] = '\0';
					break;
				}
				else
				{
					for (int j = t + 3; j < len; j++)
					{
						list[j] = list[j + 1];
					}
					for (int j = t + 2; j < len; j++)
					{
						list[j] = list[j + 1];
					}
					break;
				}
			}
		}

	}
	for (int t = 0; t < len; t++)
	{
		if (list[t + 1] == '^')/*s为幂号*/
		{
			int a = int(list[t + 2] - '0');
			int temp = pow((list[t] - '0'), a);
			list[t] = char(temp + '0');
		 if (list[t + 3] == '\0')
		 {
			list[t + 1] = '\0';
			break;
		 }
			else if (list[t + 4] == '\0')
			{
				list[t + 2] = '\0';
				list[t + 1] = ')';
				break;
			}
			else
			{
				for (int j = t + 2; j < len; j++)
				{
					list[j] = list[j + 1];
				}
				for (int j = t + 1; j < len ; j++)
				{
					list[j] = list[j + 1];
				}
				break;
			}
			len = len - 2;
		}
	}
	/*puts(list);*/
	len = strlen(list);
	for (int i = 0; i < len; i++)
	{
		if (list[i] >= '0' && list[i] <= '9')
		{
			link[j] = list[i];
			j++;
			if (list[i+1] < '0' || list[i+1] > '9')
			{
				link[j] = '$';
				j++;
			}
		}
		else if (list[i] == '*' || list[i] == '/' || list[i] == '%')
		{
			if (GetTop(change, top) == '*' || GetTop(change, top) == '/' || GetTop(change, top) == '%')
			{
				link[j] = GetTop(change, top);
				Pop(change, top);
				j++;
			}
			Push(change, top, list[i]);

		}
		else if (list[i] == '+' || list[i] == '-')
		{
			if (*top == -1)
				Push(change, top, list[i]);
			else
			{
				while (1)
				{
				    if (GetTop(change, top) == '(' || *top == -1)
					{
						Push(change, top, list[i]);
						break;
					}
					else if (GetTop(change, top) == '(')
					{
						Pop(change, top);
						while (1)
						{
							if (  *top == -1)
							{
								Push(change, top, list[i]);
								break;
							}
							else if (GetTop(change, top) == '(')
							{
								Pop(change, top);
								while (1)
								{
									if ( *top == -1)
									{
										Push(change, top, list[i]);
										break;
									}
									else if (GetTop(change, top) == '*' || GetTop(change, top) == '/' || GetTop(change, top) == '%')
									{
										link[j] = Pop(change, top);
										j++;
									}
									else if (GetTop(change, top) == '+' || GetTop(change, top) == '-')
									{
										link[j] = Pop(change, top);
										j++;
									}
								}
							}
							else if (GetTop(change, top) == '*' || GetTop(change, top) == '/' || GetTop(change, top) == '%')
							{
								link[j] = Pop(change, top);
								j++;
							}
							else if (GetTop(change, top) == '+' || GetTop(change, top) == '-')
							{
								link[j] = Pop(change, top);
								j++;
							}
						}
					}
					else if (GetTop(change, top) == '*' || GetTop(change, top) == '/' || GetTop(change, top) == '%')
					{
						link[j] = Pop(change, top);
						j++;
					}
					else if (GetTop(change, top) == '+' || GetTop(change, top) == '-')
					{
						link[j] = Pop(change, top);
						j++;
					}
				}
			}
			if (*top == -1)
				Push(change, top, list[i]);
		}
		else if (list[i] == '(')
		{
			Push(change, top, list[i]);
		}
		else if (list[i] == ')')
		{
			while (1)
			{
				if (GetTop(change, top) == '(')
				{
					Pop(change, top);
					break;
				}
				link[j] = Pop(change, top);
				j = j + 1;
			}
		}
	}
	if (*top == -1)
	{
	}
	else
	{
		while (1)
		{
			link[j] = Pop(change, top);
			j++;
			if (*top == -1)
				break;
		}
	}
	/*205行以前为中缀变后缀*/
	link[j] = '\0';
	len = strlen(link);
	/*puts(link);//*/
	for (int i = 0; i < len; i++)
	{
		if (link[i] >= '0' && link[i] <= '9')
		{
			Push(change, top, link[i]);
		}
		else if (link[i] == '$')
		{
				Push(change, top, link[i]);
		}
		else if (link[i] == '*' || link[i] == '/' || link[i] == '%' || link[i] == '+' || link[i] == '-')
		{
			if(GetTop(change, top)=='$')
				Pop(change, top);
			int y = GetTop(change, top) - '0';
			Pop(change, top);
			int cnt = 10;
			while (1)
			{
				if (*top == -1)
					break;
				if (GetTop(change, top) != '$')
				{
					y = y  + (GetTop(change, top) - '0')*cnt;
					Pop(change, top);
					cnt = cnt * 10;
				}
				if (GetTop(change, top) == '$')
				{
					break;
				}
				if (*top == -1)
					break;
			}
			Pop(change, top);
			int x = GetTop(change, top) - '0';
			Pop(change, top);
			cnt = 10;
			while (1)
			{
				if (*top == -1)
					break;
				if (GetTop(change, top) != '$')
				{
					x = x + (GetTop(change, top) - '0') * cnt;
					Pop(change, top);
					cnt = cnt * 10;
				}
				if (GetTop(change, top) == '$')
				{
					break;
				}
				if (*top == -1)
					break;
			}
			if (link[i] == '*')
			{
				int result = x * y ;
				if (result < 10)
				{
					result = result + '0';
					Push(change, top, result);
					Push(change, top, '$');
				}
				else if (result < 100 && result>9)
				{
					char shi = result / 10+'0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
				else if (result < 1000 && result>99)
				{
					char bai = result / 100 + '0';
					Push(change, top, bai);
					char shi = (result / 10 )%10+ '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
				else if (result < 10000 && result>999)
				{
					char qian= result / 1000 + '0';
					Push(change, top, qian);
					result = result % 1000;
					char bai = result / 100 + '0';
					Push(change, top, bai);
					char shi = (result / 10) % 10 + '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
			}
			else if (link[i] == '/')
			{
				int result = x / y;
				if (result < 10)
				{
					result = result + '0';
					Push(change, top, result);
					Push(change, top, '$');
				}
				else if (result < 100 && result>9)
				{
					char shi = result / 10 + '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
				else if (result < 1000 && result>99)
				{
					char bai = result / 100 + '0';
					Push(change, top, bai);
					char shi = (result / 10) % 10 + '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
				else if (result < 10000 && result>999)
				{
					char qian = result / 1000 + '0';
					Push(change, top, qian);
					result = result % 1000;
					char bai = result / 100 + '0';
					Push(change, top, bai);
					char shi = (result / 10) % 10 + '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
			}
			else if (link[i] == '%')
			{
				int result = x % y;
				if (result < 10)
				{
					result = result + '0';
					Push(change, top, result);
					Push(change, top, '$');
				}
				else if (result < 100 && result>9)
				{
					char shi = result / 10 + '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
				else if (result < 1000 && result>99)
				{
					char bai = result / 100 + '0';
					Push(change, top, bai);
					char shi = (result / 10) % 10 + '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
				else if (result < 10000 && result>999)
				{
					char qian = result / 1000 + '0';
					Push(change, top, qian);
					result = result % 1000;
					char bai = result / 100 + '0';
					Push(change, top, bai);
					char shi = (result / 10) % 10 + '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
			}
			else if (link[i] == '+')
			{
				int result = x + y;
				if (result < 10)
				{
					result = result + '0';
					Push(change, top, result);
					Push(change, top, '$');
				}
				else if (result < 100 && result>9)
				{
					char shi = result / 10 + '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
				else if (result < 1000 && result>99)
				{
					char bai = result / 100 + '0';
					Push(change, top, bai);
					char shi = (result / 10) % 10 + '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
				else if (result < 10000 && result>999)
				{
					char qian = result / 1000 + '0';
					Push(change, top, qian);
					result = result % 1000;
					char bai = result / 100 + '0';
					Push(change, top, bai);
					char shi = (result / 10) % 10 + '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
			}
			else if (link[i] == '-')
			{
				int result = x - y;
				if (result < 10)
				{
					result = result + '0';
					Push(change, top, result);
					Push(change, top, '$');
				}
				else if (result < 100 && result>9)
				{
					char shi = result / 10 + '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
				else if (result < 1000 && result>99)
				{
					char bai = result / 100 + '0';
					Push(change, top, bai);
					char shi = (result / 10) % 10 + '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
				else if (result < 10000 && result>999)
				{
					char qian = result / 1000 + '0';
					Push(change, top, qian);
					result = result % 1000;
					char bai = result / 100 + '0';
					Push(change, top, bai);
					char shi = (result / 10) % 10 + '0';
					Push(change, top, shi);
					char ge = result % 10 + '0';
					Push(change, top, ge);
					Push(change, top, '$');
				}
			}
		}
	}
	Pop(change, top);
	int pr = GetTop(change, top) - '0';
	Pop(change, top);
	int cnt = 10;
	while (1)
	{
		if (*top == -1)
			break;
		else if (GetTop(change, top) >= '0' && GetTop(change, top) <= '9')
		{
			pr = pr + cnt*(GetTop(change, top) - '0');
			Pop(change, top);
			cnt = cnt * 10;
		}
	}
	printf("\n"); printf("\n"); printf("\n");

	printf("答案为：%d", pr);
	printf("\n"); printf("\n"); printf("\n"); printf("\n");
}
char* creat(int* top) {
	char* stack = (char*)malloc(100*sizeof(char));
	return stack;
}
void Push(char* stact, int *top,char temp)
{
	if (*top == 100)
		printf("栈满");
	else {
		(*top)++;
		stact[*top] = temp;
	}
}
char Pop(char* stact, int *top)
{
	if (*top == -1)
		printf("栈空");
	else
	{
		(*top)--;
		return stact[(*top)+1];
	}
}
char GetTop(char* stact ,int *top){
	  if (*top == -1)
			return false;
	  else
	  {
		  return  stact[*top];
	  }
}
