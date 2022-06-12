#include "head.h"

Snake snake;//创建蛇的结构体变量
Food food;//创建食物的结构体变量
void Kaishi()
{
	initgraph(520, 360, NULL);
	IMAGE bgp;
	loadimage(&bgp, "./an.jpg", 520, 360, false);//加载图片
	putimage(0, 0, &bgp);
	setbkmode(TRANSPARENT);   				     //字符透明
	settextcolor(RGB(97, 274, 255));
	settextstyle(40, 30, "宋体");
	outtextxy(20, 130, "欢迎使用");
	Sleep(3000);
	closegraph;
}


void Init_Game()
{
	snake.len = 3;//初始化长度

	snake.direc = RIGHT;//初始化方向

	//初始化蛇头坐标
	snake.cr[0].x = 100;
	snake.cr[0].y = 100;

	//蛇身坐标
	snake.cr[1].x = 90;
	snake.cr[1].y = 100;
	snake.cr[2].x = 80;
	snake.cr[2].y = 100;

	food.eat = 1;//初始化食物是被吃的

}

void Draw_Game(int count)
{
	TCHAR a[100];//存放分数
	for (int i = 0; i < snake.len; i++)
	{
		if (i == 0)//如果是蛇头
		{
			setfillcolor(RED);//填充颜色为红色
			//绘制实心矩形，填充颜色为红色
			fillrectangle(snake.cr[i].x, snake.cr[i].y, snake.cr[i].x + SIZE, snake.cr[i].y + SIZE);//这里的SIZE我在头文件head.h中宏定义为10了
			//四个参数为：    x坐标           y坐标           宽                       高
		}
		else
			rectangle(snake.cr[i].x, snake.cr[i].y, snake.cr[i].x + SIZE, snake.cr[i].y + SIZE);//绘制非实心矩形
	}
	//显示分数
	setcolor(BLACK);
	line(640, 0, 640, 450);
	line(640, 0, 820, 0);
	line(820, 0, 820, 450);
	line(640, 450, 820, 450);
	settextstyle(20, 15, "宋体");
	outtextxy(690, 100, "难度低");
	settextstyle(17, 14, "宋体");
	outtextxy(650, 300, "分数：");
	_stprintf_s(a, _T("[%d]"), count * 10);//将食物被吃的次数写字符串a中
	outtextxy(720, 300, a);

	//绘制食物
	setfillcolor(GREEN);//填充颜色为绿色
	fillroundrect(food.x, food.y, food.x + SIZE, food.y + SIZE, 5, 5);//圆角矩形
	//6个参数为：  x坐标   y坐标      宽              高       这两个是圆角的程度
}

void Move_Snake()
{
	cleardevice();//以当前背景色清屏
	for (int i = snake.len - 1; i > 0; i--)
	{
		snake.cr[i].x = snake.cr[i - 1].x;
		snake.cr[i].y = snake.cr[i - 1].y;
	}//数组下标是从 0~n-1 的，所以从i=snake.len-1开始。为什么i要>0而不是>=0
	//是因为在循环里面的语句中，有i-1的操作。最后一次是把snake.cr[0]的坐标给snake.cr[1]，如果写>=0，就会产生把 snake.cr[-1]的坐标给snake.cr[0]

	//蛇头的坐标没有了，现在要产生新的蛇头坐标
	switch (snake.direc)
	{
	case UP:
		snake.cr[0].y -= SIZE;
		break;
	case DOWN:
		snake.cr[0].y += SIZE;
		break;
	case LEFT:
		snake.cr[0].x -= SIZE;
		break;
	case RIGHT:
		snake.cr[0].x += SIZE;
		break;
	}
}

void Change_Move()
{
	int key = 0;
	key = _getch();//接收键盘值
	switch (key)
	{
	case UP:
		if (snake.direc != DOWN)//如果蛇正在往下，就不能改变方向。
			snake.direc = UP;
		break;
	case DOWN:
		if (snake.direc != UP)//如果蛇正在往上，就不能改变方向。
			snake.direc = DOWN;
		break;
	case LEFT:
		if (snake.direc != RIGHT)//如果蛇正在往右，就不能改变方向
			snake.direc = LEFT;
		break;
	case RIGHT:
		if (snake.direc != LEFT)//如果蛇正在往左，就不能改变防线
			snake.direc = RIGHT;
		break;
	}
}

void Produce_Food()
{
	int func = 0;//用来判断食物的坐标是否与蛇的坐标重合
	if (food.eat == 1)
	{
		while (1)
		{
			food.x = rand() % 64 * 10;//rand()%64的区间在0~63，再*10可实现坐标以10为间隔生成坐标   0  10  20...
			food.y = rand() % 48 * 10;//rand()%48的区间在0~46，再*10可实现坐标以10为间隔生成坐标   0  10  20...
			for (int i = 0; i < snake.len; i++)
			{
				if (food.x == snake.cr[i].x && food.y == snake.cr[i].y)
				{
					func = 1;//如果但凡有坐标重合,func改变为1，表重合
					break;//退出for循环
				}
			}
			if (func == 0)//如果没有重合
			{
				food.eat = 0;//食物就要变为未被吃的状态
				break;
			}
		}
	}
}

int Eat_Food(int count)
{
	if (snake.cr[0].x == food.x && snake.cr[0].y == food.y)//如果蛇头的位置是食物
	{
		food.eat = 1;//食物的状态更新为被吃
		snake.len += 1;//蛇身长度+1
		count++;//统计被吃次数
		return count;
	}
	return count;
}

int GameOver()
{
	if (snake.cr[0].x < 0 || snake.cr[0].y < 0 || snake.cr[0].x>640 || snake.cr[0].y>480)//如果撞墙
	{
		return 1;//返回1
	}
	for (int i = 1; i < snake.len; i++)
	{
		if (snake.cr[0].x == snake.cr[i].x && snake.cr[0].y == snake.cr[i].y)//如果撞自己
			return 1;//返回1
	}
	return 0;//否则返回0
}