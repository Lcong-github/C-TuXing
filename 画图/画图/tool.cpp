#include"tool.h"
TCHAR b[100];

void Caidanlan()//菜单栏
{
	setcolor(WHITE);
	outtextxy(10, 10, L"颜");
	outtextxy(10, 30, L"色");
	setfillcolor(WHITE);  //设置实心颜色为白
	solidrectangle(40, 10, 80, 40);//画一个实心的红色矩形
	setfillcolor(BLUE);  //设置实心颜色为蓝
	solidrectangle(100, 10, 140, 40);//画一个实心的红色矩形
	setfillcolor(YELLOW);  //设置实心颜色为黄
	solidrectangle(160, 10, 200, 40);//画一个实心的红色矩形
	setfillcolor(RED);  //设置实心颜色为红
	solidrectangle(220, 10, 260, 40);//画一个实心的红色矩形
	outtextxy(300, 10, L"工");
	outtextxy(300, 30, L"具");
	rectangle(330, 10, 390, 40);    //画一个矩形边框
	outtextxy(344, 17, L"画笔");   //将这两字写在上面画的矩形边框里
	rectangle(410, 10, 470, 40);    //画一个矩形边框
	outtextxy(424, 17, L"直线");   //将这两字写在上面画的矩形边框里
	rectangle(490, 10, 550, 40);    //画一个矩形边框
	outtextxy(504, 17, L"曲线");   //将这两字写在上面画的矩形边框里
	rectangle(570, 10, 630, 40);    //画一个矩形边框
	outtextxy(584, 17, L"画圆");   //将这两字写在上面画的矩形边框里
	rectangle(650, 10, 710, 40);    //画一个矩形边框
	outtextxy(664, 17, L"填充");   //将这两字写在上面画的矩形边框里
	rectangle(730, 10, 790, 40);    //画一个矩形边框
	outtextxy(744, 17, L"重启");   //将这两字写在上面画的矩形边框里
	rectangle(810, 10, 870, 40);    //画一个矩形边框
	outtextxy(824, 17, L"退出");   //将这两字写在上面画的矩形边框里
	setcolor(WHITE);
	line(0, 50, 880, 50);//菜单栏分界线
}



int Izhi(int i)//i值
{
	switch (i)//判断i值并给出相应回应
	{
	case 1:
		setfillcolor(GREEN);  //点击变化颜色
		solidrectangle(40, 10, 80, 40);//画一个实心的绿色矩形
		Sleep(100);
		setfillcolor(WHITE);  //点击变化颜色
		solidrectangle(40, 10, 80, 40);//画一个实心的白色矩形
		setcolor(WHITE);
		return 0;
	case 2:
		setfillcolor(GREEN);  //点击变化颜色
		solidrectangle(100, 10, 140, 40);//画一个实心的绿色矩形
		Sleep(100);
		setfillcolor(BLUE);  //点击变化颜色
		solidrectangle(100, 10, 140, 40);//画一个实心的白色矩形
		setcolor(BLUE);
		return 0;
	case 3:
		setfillcolor(GREEN);  //点击变化颜色
		solidrectangle(160, 10, 200, 40);//画一个实心的绿色矩形
		Sleep(100);
		setfillcolor(YELLOW);  //点击变化颜色
		solidrectangle(160, 10, 200, 40);//画一个实心的黄色矩形
		setcolor(YELLOW);
		return 0;
	case 4:
		setfillcolor(GREEN);  //点击变化颜色
		solidrectangle(220, 10, 260, 40);//画一个实心的绿色矩形
		Sleep(100);
		setfillcolor(RED);  //点击变化颜色
		solidrectangle(220, 10, 260, 40);//画一个实心的红色矩形
		setcolor(RED);
		return 0;
	default:
		return 0;
	}
}


void Huabi(int i)//实现画笔工具
{
	MOUSEMSG m;
	int x = 0;
	int y = 0;
	int flag = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	flag = 0;
	while (1)
	{
		m = GetMouseMsg();
		x = m.x, y = m.y;
		setfillcolor(BLACK);
		solidrectangle(0, 570, 100, 600);
		_stprintf_s(b, _T("[%d,%d]"), x, y);
		//setcolor(WHITE);
		outtextxy(0, 580, b);
		i = Izhi(i);//判断i值在哪个颜色区域内并闪烁一次绿色，执行相应功能并重置i值为0

		if (m.y >= 0 && m.y < 50)//判断鼠标是否在可画区域内
		{
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN)//判断鼠标是否按下
		{
			if (flag == 0)
			{
				x1 = m.x;
				y1 = m.y;
				flag = 1;
			}
		}
		else if (m.uMsg == WM_MOUSEMOVE && flag == 1)//判断鼠标是否连续滑动
		{
			x2 = m.x;
			y2 = m.y;
			line(x1, y1, x2, y2);
			x1 = x2;
			y1 = y2;
		}
		if (m.uMsg == WM_LBUTTONUP)//判断鼠标是否弹起
			flag = 0;
	}
}


void ZhixianYuan(int i,int j)//实现直线工具和画圆
{
	MOUSEMSG m;
	int x = 0;
	int y = 0;
	int flag = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	flag = 0;
	while (1)
	{
		m = GetMouseMsg();
		x = m.x, y = m.y;
		setfillcolor(BLACK);
		solidrectangle(0, 570, 100, 600);
		_stprintf_s(b, _T("[%d,%d]"), x, y);
		//setcolor(WHITE);
		outtextxy(0, 580, b);
		i = Izhi(i);//判断i值在哪个颜色区域内并闪烁一次绿色，执行相应功能并重置i值为0

		if (m.y >= 0 && m.y < 50)//判断鼠标是否在可画区域内
		{
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN)//判断鼠标是否按下
		{
			if (flag == 0)
			{
				x1 = m.x;
				y1 = m.y;
				flag = 1;
			}
		}
		else if (m.uMsg == WM_LBUTTONUP && flag == 1)//判断鼠标是否弹起
		{
			x2 = m.x;
			y2 = m.y;
			if (j == 2)
			{
				line(x1, y1, x2, y2);//中点画线算法
			}
			if (j == 4)
			{
				Yuan(x1, y1, x2, y2);//中点画圆算法
			}
			flag = 0;
		}
			
	}
}

void Quxian(int i)//实现曲线工具
{
	MOUSEMSG m;
	int x = 0;
	int y = 0;
	int flag = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
	flag = 0;
	while (1)
	{
		m = GetMouseMsg();
		x = m.x, y = m.y;
		setfillcolor(BLACK);
		solidrectangle(0, 570, 100, 600);
		_stprintf_s(b, _T("[%d,%d]"), x, y);
		//setcolor(WHITE);
		outtextxy(0, 580, b);
		i = Izhi(i);//判断i值在哪个颜色区域内并闪烁一次绿色，执行相应功能并重置i值为0

		if (m.y >= 0 && m.y < 50)//判断鼠标是否在可画区域内
		{
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN && flag == 0)//判断鼠标是否按下
		{
			
				x1 = m.x;
				y1 = m.y;
				flag = 1;
			
		}
		else if (m.uMsg == WM_LBUTTONUP && flag == 1)//判断鼠标是否弹起
		{
			x2 = m.x;
			y2 = m.y;
			line(x1, y1, x2, y2);
			flag = 2;
		}
		else if (m.uMsg == WM_LBUTTONDOWN && flag == 2)//判断鼠标是否再次按下
		{
			x3 = m.x;
			y3 = m.y;
			
			
			BezierQuxian(x1, y1, x2, y2, x3, y3);//Bezier曲线
			setcolor(BLACK);
			line(x1, y1, x2, y2);//用背景色覆盖之前的直线
			setcolor(WHITE);//恢复默认白色，避免无法显示坐标
			flag = 0;
		}

	}
}


void Tianchong()//实现填充工具
{
	MOUSEMSG m;
	int x = 0;
	int y = 0;
	int flag = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	flag = 0;
	int newcolor;
	while (1)
	{
		m = GetMouseMsg();
		x = m.x, y = m.y;
		setfillcolor(BLACK);
		solidrectangle(0, 570, 100, 600);
		_stprintf_s(b, _T("[%d,%d]"), x, y);
		outtextxy(0, 580, b);

		if (m.x >= 330 && m.x <= 800 && m.y >= 0 && m.y < 50)//判断鼠标是否在可画区域内
		{
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN && flag == 0)//判断鼠标是否按下
		{
			
				x = m.x, y = m.y;
				if (x >= 40 && x <= 80 && y >= 10 && y <= 40)//白
				{
					newcolor = WHITE;
					flag = 1;
				}
				else if (x >= 100 && x <= 140 && y >= 10 && y <= 40)//蓝
				{
					newcolor = BLUE;
					flag = 1;
				}
				
				else if (x >= 160 && x <= 200 && y >= 10 && y <= 40)//黄
				{
					newcolor = YELLOW;
					flag = 1;
				}
				else if (x >= 200 && x <= 260 && y >= 10 && y <= 40)//红
				{
					newcolor = RED;
					flag = 1;
				}
			
		}
		else if (m.uMsg == WM_LBUTTONUP && flag == 1)//判断鼠标是否弹起
		{
			
			flag = 2;
		}
		else if (m.uMsg == WM_LBUTTONDOWN && flag == 2)//判断鼠标是否再次按下
		{
			x2 = m.x;
			y2 = m.y;
			FloodFILL(x2, y2, BLACK, newcolor);//四连通泛填充算法
			flag = 0;
		}

	}
}