#include<stdio.h>
#include<stdlib.h>
int m = 0, n = 0, p = 0, q = 0, g = 0, h = 0, z = 0;
int c, x, y, w, x1, y11, i, j, max1, num;
int a[3][3] = { 0 };
int s[3][3];
char tu[4] = { ' ','#',' ','o' };
void fun1()
{
	int sum = 0;
	sum = a[0][1] + a[0][2];
	if (sum == 0)
		s[0][0] = 4;
	else if (sum == 3)
		s[0][0] = 8;
	else if (sum == 1)
		s[0][0] = 10;
	else if (sum == 6)
		s[0][0] = 25;
	else if (sum == 2)
		s[0][0] = 50;
	sum = a[1][0] + a[2][0];
	if (sum == 0)
		s[0][0] += 4;
	else if (sum == 3)
		s[0][0] += 8;
	else if (sum == 1)
		s[0][0] += 10;
	else if (sum == 6)
		s[0][0] += 25;
	else if (sum == 2)
		s[0][0] += 50;
	sum = a[1][1] + a[2][2];
	if (sum == 0)
		s[0][0] += 4;
	else if (sum == 3)
		s[0][0] += 8;
	else if (sum == 1)
		s[0][0] += 10;
	else if (sum == 6)
		s[0][0] += 25;
	else if (sum == 2)
		s[0][0] += 50;

	sum = a[0][0] + a[0][2];
	if (sum == 0)
		s[0][1] = 4;
	else if (sum == 3)
		s[0][1] = 8;
	else if (sum == 1)
		s[0][1] = 10;
	else if (sum == 6)
		s[0][1] = 25;
	else if (sum == 2)
		s[0][1] = 50;
	sum = a[1][1] + a[2][1];
	if (sum == 0)
		s[0][1] += 4;
	else if (sum == 3)
		s[0][1] += 8;
	else if (sum == 1)
		s[0][1] += 10;
	else if (sum == 6)
		s[0][1] += 25;
	else if (sum == 2)
		s[0][1] += 50;

	sum = a[0][0] + a[0][1];
	if (sum == 0)
		s[0][1] = 4;
	else if (sum == 3)
		s[0][2] = 8;
	else if (sum == 1)
		s[0][2] = 10;
	else if (sum == 6)
		s[0][2] = 25;
	else if (sum == 2)
		s[0][2] = 50;
	sum = a[1][1] + a[2][0];
	if (sum == 0)
		s[0][1] += 4;
	else if (sum == 3)
		s[0][2] += 8;
	else if (sum == 1)
		s[0][2] += 10;
	else if (sum == 6)
		s[0][2] += 25;
	else if (sum == 2)
		s[0][2] += 50;
	sum = a[1][2] + a[2][2];
	if (sum == 0)
		s[0][1] += 4;
	else if (sum == 3)
		s[0][2] += 8;
	else if (sum == 1)
		s[0][2] += 10;
	else if (sum == 6)
		s[0][2] += 25;
	else if (sum == 2)
		s[0][2] += 50;

	sum = a[0][0] + a[2][0];
	if (sum == 0)
		s[1][0] = 4;
	else if (sum == 3)
		s[1][0] = 8;
	else if (sum == 1)
		s[1][0] = 10;
	else if (sum == 6)
		s[1][0] = 25;
	else if (sum == 2)
		s[1][0] = 50;
	sum = a[1][2] + a[1][1];
	if (sum == 0)
		s[1][0] += 4;
	else if (sum == 3)
		s[1][0] += 8;
	else if (sum == 1)
		s[1][0] += 10;
	else if (sum == 6)
		s[1][0] += 25;
	else if (sum == 2)
		s[1][0] += 50;

	sum = a[0][0] + a[2][2];
	if (sum == 0)
		s[1][1] = 4;
	else if (sum == 3)
		s[1][1] = 8;
	else if (sum == 1)
		s[1][1] = 10;
	else if (sum == 6)
		s[1][1] = 25;
	else if (sum == 2)
		s[1][1] = 50;
	sum = a[0][1] + a[2][1];
	if (sum == 0)
		s[1][1] += 4;
	else if (sum == 3)
		s[1][1] += 8;
	else if (sum == 1)
		s[1][1] += 10;
	else if (sum == 6)
		s[1][1] += 25;
	else if (sum == 2)
		s[1][1] += 50;
	sum = a[0][2] + a[2][0];
	if (sum == 0)
		s[1][1] += 4;
	else if (sum == 3)
		s[1][1] += 8;
	else if (sum == 1)
		s[1][1] += 10;
	else if (sum == 6)
		s[1][1] += 25;
	else if (sum == 2)
		s[1][1] += 50;
	sum = a[1][0] + a[1][2];
	if (sum == 0)
		s[1][1] += 4;
	else if (sum == 3)
		s[1][1] += 8;
	else if (sum == 1)
		s[1][1] += 10;
	else if (sum == 6)
		s[1][1] += 25;
	else if (sum == 2)
		s[1][1] += 50;

	sum = a[0][2] + a[2][2];
	if (sum == 0)
		s[1][2] = 4;
	else if (sum == 3)
		s[1][2] = 8;
	else if (sum == 1)
		s[1][2] = 10;
	else if (sum == 6)
		s[1][2] = 25;
	else if (sum == 2)
		s[1][2] = 50;
	sum = a[1][0] + a[1][1];
	if (sum == 0)
		s[1][2] += 4;
	else if (sum == 3)
		s[1][2] += 8;
	else if (sum == 1)
		s[1][2] += 10;
	else if (sum == 6)
		s[1][2] += 25;
	else if (sum == 2)
		s[1][2] += 50;

	sum = a[0][0] + a[1][0];
	if (sum == 0)
		s[2][0] = 4;
	else if (sum == 3)
		s[2][0] = 8;
	else if (sum == 1)
		s[2][0] = 10;
	else if (sum == 6)
		s[2][0] = 25;
	else if (sum == 2)
		s[2][0] = 50;
	sum = a[0][2] + a[1][1];
	if (sum == 0)
		s[2][0] += 4;
	else if (sum == 3)
		s[2][0] += 8;
	else if (sum == 1)
		s[2][0] += 10;
	else if (sum == 6)
		s[2][0] += 25;
	else if (sum == 2)
		s[2][0] += 50;
	sum = a[2][1] + a[2][2];
	if (sum == 0)
		s[2][0] += 4;
	else if (sum == 3)
		s[2][0] += 8;
	else if (sum == 1)
		s[2][0] += 10;
	else if (sum == 6)
		s[2][0] += 25;
	else if (sum == 2)
		s[2][0] += 50;

	sum = a[0][1] + a[1][1];
	if (sum == 0)
		s[2][1] = 4;
	else if (sum == 3)
		s[2][1] = 8;
	else if (sum == 1)
		s[2][1] = 10;
	else if (sum == 6)
		s[2][1] = 25;
	else if (sum == 2)
		s[2][1] = 50;
	sum = a[2][0] + a[2][2];
	if (sum == 0)
		s[2][1] += 4;
	else if (sum == 3)
		s[2][1] += 8;
	else if (sum == 1)
		s[2][1] += 10;
	else if (sum == 6)
		s[2][1] += 25;
	else if (sum == 2)
		s[2][1] += 50;

	sum = a[0][2] + a[1][2];
	if (sum == 0)
		s[2][2] = 4;
	else if (sum == 3)
		s[2][2] = 8;
	else if (sum == 1)
		s[2][2] = 10;
	else if (sum == 6)
		s[2][2] = 25;
	else if (sum == 2)
		s[2][2] = 50;
	sum = a[0][0] + a[1][1];
	if (sum == 0)
		s[2][2] += 4;
	else if (sum == 3)
		s[2][2] += 8;
	else if (sum == 1)
		s[2][2] += 10;
	else if (sum == 6)
		s[2][2] += 25;
	else if (sum == 2)
		s[2][2] += 50;
	sum = a[2][0] + a[2][1];
	if (sum == 0)
		s[2][2] += 4;
	else if (sum == 3)
		s[2][2] += 8;
	else if (sum == 1)
		s[2][2] += 10;
	else if (sum == 6)
		s[2][2] += 25;
	else if (sum == 2)
		s[2][2] += 50;
}
void victory(int &win_or_lose)
{
	for (i = 0; i < 3; i++)
	{
		m = 0;
		n = 0;
		for (j = 0; j < 3; j++)
		{
			if (a[i][j] == 1)
				m++;
			else if (a[i][j] == 3)
				n++;
		}
		//  printf("***%d %d %d\n",i,m,n);
		if (m == 3)
		{
			printf("敖丙赢了！\n");
			win_or_lose = 1;
			exit(0);
		}
		else if (n == 3)
		{
			printf("你赢了！\n");
			win_or_lose = 0;
			exit(0);
		}
	}
	for (i = 0; i < 3; i++)
	{
		p = 0;
		q = 0;
		for (j = 0; j < 3; j++)
		{
			if (a[j][i] == 1)
				p++;
			else if (a[j][i] == 3)
				q++;
		}//printf("i%d p%d q%d",i,p,q);
		if (p == 3)
		{
			printf("敖丙赢了！\n");
			win_or_lose = 1;
			exit(0);
		}
		else if (q == 3)
		{
			printf("你赢了！\n");
			win_or_lose = 0;
			exit(0);
		}
	}
	g = 0;
	h = 0;
	for (i = 0; i < 3; i++)
	{
		if (a[i][i] == 1)
			g++;
		else if (a[i][i] == 3)
			h++;
	}//printf("\ng%d h%d",g,h);
	if (g == 3)
	{
		printf("敖丙赢了！\n");
		win_or_lose = 1;
		exit(0);
	}
	else if (h == 3)
	{
		printf("你赢了！\n");
		win_or_lose = 0;
		exit(0);
	}
	if (a[0][2] == 1 && a[1][1] == 1 && a[2][0] == 1)
	{
		printf("敖丙赢了！\n");
		win_or_lose = 1;
		exit(0);
	}
	else if (a[0][2] == 3 && a[1][1] == 3 && a[2][0] == 3)
	{
		printf("你赢了！\n");
		win_or_lose = 0;
		exit(0);
	}
}
void tictactoe(int &win_or_lose)
{//void fun1();void victory(int win_or_lose);
	printf("**********************************************************************\n");
	printf("                           !欢迎体验井字游戏！\n\n");
	printf("-----------------无棋子为 敖丙棋子为#您的棋子为o-----------------\n");
	printf("\n请按键选择谁先下(1.敖丙3.我)\n");
	scanf("%d", &c);
	for (i = 0; i < 3; i++)
	{
		printf("-------\n");
		for (j = 0; j < 3; j++)
		{
			num = a[i][j];
			printf("|%c", tu[num]);
			if (j == 2)
				printf("|\n");
		}
	}
	printf("-------\n");
	if (c == 1)
	{
		for (w = 0; w < 4; w++)
		{
			fun1();
			max1 = 0;
			for (i = 0; i < 3; i++)
				for (j = 0; j < 3; j++)
				{
					if (s[i][j] >= max1 && a[i][j] == 0)
					{
						max1 = s[i][j];
						x = i;
						y = j;
					}
				}
			printf("您的对手敖丙正在下棋\n");
			a[x][y] = 1;
			for (i = 0; i < 3; i++)
			{
				printf("-------\n");
				for (j = 0; j < 3; j++)
				{
					num = a[i][j];
					printf("|%c", tu[num]);
					if (j == 2)
						printf("|\n");
				}
			}
			printf("-------\n");
			victory(win_or_lose);
			printf("请您输入棋子坐标(x1 y1)(0=<x1<=2,0=<y1<=2)\n");
			scanf("%d%d", &x1, &y11);
			if (a[x1][y11] != 1 && a[x1][y11] != 3)
			{
				a[x1][y11] = 3;
			}
			else
			{
				printf("该位置有棋子了\n");
				exit(0);
			}
			for (i = 0; i < 3; i++)
			{
				printf("-------\n");
				for (j = 0; j < 3; j++)
				{
					num = a[i][j];
					printf("|%c", tu[num]);
					if (j == 2)
						printf("|\n");
				}
			}
			printf("-------\n");
			victory(win_or_lose);
		}
		fun1();
		max1 = 0;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				if (s[i][j] >= max1 && a[i][j] == 0)
				{
					max1 = s[i][j];
					x = i;
					y = j;
				}
			}
		printf("您的对手敖丙正在下棋\n");
		a[x][y] = 1;
		for (i = 0; i < 3; i++)
		{
			printf("-------\n");
			for (j = 0; j < 3; j++)
			{
				num = a[i][j];
				printf("|%c", tu[num]);
				if (j == 2)
					printf("|\n");
			}
		}
		printf("-------\n");
		victory(win_or_lose);
		printf("平局！\n");
		win_or_lose = 3;

	}
	else
	{
		for (w = 0; w < 4; w++)
		{
			printf("请您输入棋子坐标(x1 y1)\n");
			scanf("%d%d", &x1, &y11);
			if (a[x1][y11] != 1 && a[x1][y11] != 3)
			{
				a[x1][y11] = 3;
			}
			else
			{
				printf("该位置有棋子了\n");
				exit(0);
			}
			for (i = 0; i < 3; i++)
			{
				printf("-------\n");
				for (j = 0; j < 3; j++)
				{
					num = a[i][j];
					printf("|%c", tu[num]);
					if (j == 2)
						printf("|\n");
				}
			}
			printf("-------\n");
			victory(win_or_lose);
			fun1();
			max1 = 0;
			for (i = 0; i < 3; i++)
				for (j = 0; j < 3; j++)
				{
					if (s[i][j] >= max1 && a[i][j] == 0)
					{
						max1 = s[i][j];
						x = i;
						y = j;
					}
				}
			printf("您的对手敖丙正在下棋\n");
			a[x][y] = 1;
			for (i = 0; i < 3; i++)
			{
				printf("-------\n");
				for (j = 0; j < 3; j++)
				{
					num = a[i][j];
					printf("|%c", tu[num]);
					if (j == 2)
						printf("|\n");
				}
			}
			printf("-------\n");
			victory(win_or_lose);
		}
		printf("请您输入棋子坐标(x1 y1)\n");
		scanf("%d%d", &x1, &y11);
		if (a[x1][y11] != 1 && a[x1][y11] != 3)
		{
			a[x1][y11] = 3;
		}
		else
		{
			printf("该位置有棋子了\n");
			exit(0);
		}
		for (i = 0; i < 3; i++)
		{
			printf("-------\n");
			for (j = 0; j < 3; j++)
			{
				num = a[i][j];
				printf("|%c", tu[num]);
				if (j == 2)
					printf("|\n");
			}
		}
		printf("-------\n");
		victory(win_or_lose);
		printf("平局！\n");
		win_or_lose = 3;
	}
}