#include <stdio.h>
int main()
{
	for(int i=1;i<10;i++)
	{
		for(int j=1;j<=i;j++)
		{
			printf("%02d*%02d=%02d  ",j,i,j*i);
		}
		printf("\n");
	}
}
