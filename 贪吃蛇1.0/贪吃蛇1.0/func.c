#include"head.h"
void Init_map(int map[SIZE][SIZE], int* len, int* direc)
{
	*len = 3;//初始化长度
	*direc = 2;//初始化方向

	map[5][5] = -1;//初始化食物

	//初始化蛇身
	map[3][3] = 3;
	map[4][3] = 2;

	map[5][3] = 1;//初始化蛇头
}

int get_direc(int direc)
{
	int tmp = -1;//定义一个用来接收键盘值的变量

	if (_kbhit())//如果键盘被敲击，kbhit()返回一个非0值
	{
		switch (_getch())//从键盘读入
		{
		case 'W':case 'w':tmp = 0; break;
		case 'D':case 'd':tmp = 1; break;
		case 'S':case 's':tmp = 2; break;
		case 'A':case 'a':tmp = 3; break;
		}
		//读入的键盘只能是 w、d、s、a，并且蛇不能掉头
		if (tmp != -1 && abs(direc - tmp) != 2)//abs函数是求绝对值
			direc = tmp;
	}
	return direc;
}

int move(int map[SIZE][SIZE], int direc, int* len)
{
	int i = 0;
	int j = 0;

	//定义蛇头位置
	int head_x = 0;
	int head_y = 0;

	//循环遍历数组
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (map[i][j] == *len)//如果是蛇尾
				map[i][j] = 0;

			if (map[i][j] > 1)//如果是蛇身
				map[i][j] += 1;

			if (map[i][j] == 1)//如果是蛇头
			{
				map[i][j] += 1;

				//此时蛇头+1了，已经没有蛇头了，现在就要找到一个新的蛇头
				// 
				//找到原蛇头的原位置
				head_x = i;
				head_y = j;

				//找到蛇头移动后的位置
				switch (direc)
				{
				case 0:head_x = i - 1; head_y = j; break;
				case 1:head_x = i; head_y = j + 1; break;
				case 2:head_x = i + 1; head_y = j; break;
				case 3:head_x = i; head_y = j - 1; break;
				}
			}
		}
	}

	if (map[head_x][head_y] == -1)//如过蛇头位置是食物
	{
		*len = *len + 1;//吃掉食物，长度+1
		map[head_x][head_y] = 1;//吃掉食物，食物变成蛇头

		//重新生成食物
		while (1)
		{
			i = rand() % SIZE;
			j = rand() % SIZE;
			if (map[i][j] == 0)
			{
				map[i][j] = -1;
				break;
			}
		}
	}
	//如果蛇头碰到自己或墙
	else if (map[head_x][head_y] > 0 || head_x < 0 || head_x == SIZE || head_y < 0 || head_y == SIZE)
		return 0;//返回0
	else
		map[head_x][head_y] = 1;//没碰到食物、墙壁、自己

	return 1;//没碰到食物、墙壁、自己

}

void print(int map[SIZE][SIZE])
{
	//打印边框、食物、蛇用的符号根据自己的喜好来，是自由不受限制的
	system("cls");
	int i = 0;
	int j = 0;

	//打印上边框
	for (i = 0; i <= SIZE; i++)
	{
		if (i == 0)
			printf("┏");
		else if (i == SIZE)
			printf(" ┓");
		else
			printf(" ━");

	}
	printf("\n");

	//打印左、右边框，打印蛇头、蛇身、食物
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (j == 0)
				printf("┃ ");
			else if (map[i][j] == -1)
				printf("★");
			else if (map[i][j] > 0)
				printf("○");
			else if (map[i][j] == 1)
				printf("●");
			else
				printf("  ");
			if (j == SIZE - 1)
				printf("┃");
		}
		printf("\n");
	}

	//打印下边框
	for (i = 0; i <= SIZE; i++)
	{
		if (i == 0)
			printf("┗");
		else if (i == SIZE)
			printf(" ┛");
		else
			printf(" ━");
	}
	printf("\n");
}