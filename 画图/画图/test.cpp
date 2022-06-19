#include"tool.h"
TCHAR a[100];

void Kaishi()
{
	initgraph(520, 360, NULL);
	IMAGE bgp;
	loadimage(&bgp, L"./am.jpg", 520, 360, false);//加载图片
	putimage(0, 0, &bgp);
	setbkmode(TRANSPARENT);   				     //字符透明
	settextcolor(RGB(97, 274, 255));
	settextstyle(40, 30, L"宋体");
	outtextxy(20, 130, L"欢迎使用");
	Sleep(3000);
	closegraph;
}
void Shubiao()
{
	
A:
	IMAGE bgp;
	loadimage(&bgp, L"./am.jpg", 80, 40, false);//加载图片
	putimage(800, 560, &bgp);
	Caidanlan();//菜单栏
	int x = 0, y = 0;//存储鼠标坐标
	int i = 0, j = 0;
	MOUSEMSG m;// 定义消息变量
	while (true)
	{
		B:m = GetMouseMsg();// 获取一条鼠标或按键消息
		setfillcolor(BLACK);
		solidrectangle(0, 570, 100, 600); //用黑色矩形(界面是黑色)覆盖上次的坐标
		//因为鼠标在移动的过程中坐标位置是不断变化的
		_stprintf_s(a, _T("[%d,%d]"), m.x, m.y);//将坐标写到字符串a中
		//setcolor(WHITE);
		outtextxy(0, 580, a);//循环打印当前坐标位置
		if (m.uMsg == WM_LBUTTONDOWN)//判断鼠标点击位置
		{
			x = m.x, y = m.y;
			if (x >= 40 && x <= 80 && y >= 10 && y <= 40)//白
				i = 1;
			else if (x >= 100 && x <= 140 && y >= 10 && y <= 40)//蓝
				i = 2;
			else if (x >= 160 && x <= 200 && y >= 10 && y <= 40)//黄
				i = 3;
			else if (x >= 200 && x <= 260 && y >= 10 && y <= 40)//红
				i = 4;
			else if (x >= 330 && x <= 390 && y >= 10 && y <= 40)//画笔
			{
				j = 1;
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(330, 10, 390, 40);//画一个实心的绿色矩形
				setfillcolor(GREEN);  //设置实心颜色为绿
				solidrectangle(333, 13, 393, 43);//画一个实心的绿色矩形
				setbkmode(TRANSPARENT);   				     //字符透明
				settextcolor(RGB(97, 274, 255));
				outtextxy(333 + 14, 20, L"画笔");
				Sleep(100);
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(330, 10, 393, 43);//画一个实心的绿色矩形
				setcolor(WHITE);
				rectangle(330, 10, 390, 40);    //画一个矩形边框
				outtextxy(330+14, 17, L"画笔");
				
			}
			else if (x >= 410 && x <= 470 && y >= 10 && y <= 40)//直线
			{
				j = 2;
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(410, 10, 470, 40);//画一个实心的绿色矩形
				setfillcolor(GREEN);  //设置实心颜色为绿
				solidrectangle(413, 13, 473, 43);//画一个实心的绿色矩形
				setbkmode(TRANSPARENT);   				     //字符透明
				settextcolor(RGB(97, 274, 255));
				outtextxy(413 + 14, 20, L"直线");
				Sleep(100);
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(410, 10, 473, 43);//画一个实心的绿色矩形
				setcolor(WHITE);
				rectangle(410, 10, 470, 40);    //画一个矩形边框
				outtextxy(410 + 14, 17, L"直线");
			}
			else if (x >= 490 && x <= 550 && y >= 10 && y <= 40)//曲线
			{
				j = 3;
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(490, 10, 550, 40);//画一个实心的绿色矩形
				setfillcolor(GREEN);  //设置实心颜色为绿
				solidrectangle(493, 13, 553, 43);//画一个实心的绿色矩形
				setbkmode(TRANSPARENT);   				     //字符透明
				settextcolor(RGB(97, 274, 255));
				outtextxy(493 + 14, 20, L"曲线");
				Sleep(100);
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(490, 10, 553, 43);//画一个实心的绿色矩形
				setcolor(WHITE);
				rectangle(490, 10, 550, 40);    //画一个矩形边框
				outtextxy(490 + 14, 17, L"曲线");
			}
			else if (x >= 570 && x <= 630 && y >= 10 && y <= 40)//圆
			{
				j = 4;
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(570, 10, 630, 40);//画一个实心的绿色矩形
				setfillcolor(GREEN);  //设置实心颜色为绿
				solidrectangle(573, 13, 633, 43);//画一个实心的绿色矩形
				setbkmode(TRANSPARENT);   				     //字符透明
				settextcolor(RGB(97, 274, 255));
				outtextxy(573 + 14, 20, L"画圆");
				Sleep(100);
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(570, 10, 633, 43);//画一个实心的绿色矩形
				setcolor(WHITE);
				rectangle(570, 10, 630, 40);    //画一个矩形边框
				outtextxy(570 + 14, 17, L"画圆");
			}
			else if (x >= 650 && x <= 710 && y >= 10 && y <= 40)//填充
			{
				j = 5;
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(650, 10, 710, 40);//画一个实心的绿色矩形
				setfillcolor(GREEN);  //设置实心颜色为绿
				solidrectangle(653, 13, 713, 43);//画一个实心的绿色矩形
				setbkmode(TRANSPARENT);   				     //字符透明
				settextcolor(RGB(97, 274, 255));
				outtextxy(653 + 14, 20, L"填充");
				Sleep(100);
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(650, 10, 713, 43);//画一个实心的绿色矩形
				setcolor(WHITE);
				rectangle(650, 10, 710, 40);    //画一个矩形边框
				outtextxy(650 + 14, 17, L"填充");
			}
			else if (x >= 730 && x <= 790 && y >= 10 && y <= 40)//清空
			{
				j = 6;
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(730, 10, 790, 40);//画一个实心的绿色矩形
				setfillcolor(GREEN);  //设置实心颜色为绿
				solidrectangle(733, 13, 793, 43);//画一个实心的绿色矩形
				setbkmode(TRANSPARENT);   				     //字符透明
				settextcolor(RGB(97, 274, 255));
				outtextxy(733 + 14, 20, L"重启");
				Sleep(100);
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(730, 10, 793, 43);//画一个实心的绿色矩形
				setcolor(WHITE);
				rectangle(730, 10, 790, 40);    //画一个矩形边框
				outtextxy(730 + 14, 17, L"重启");
			}
			else if (x >= 810 && x <= 870 && y >= 10 && y <= 40)//退出
			{
				j = 7;
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(810, 10, 870, 40);//画一个实心的绿色矩形
				setfillcolor(GREEN);  //设置实心颜色为绿
				solidrectangle(813, 13, 873, 43);//画一个实心的绿色矩形
				setbkmode(TRANSPARENT);   				     //字符透明
				settextcolor(RGB(97, 274, 255));
				outtextxy(813 + 14, 20, L"退出");
				Sleep(100);
				setfillcolor(BLACK);  //设置实心颜色为绿
				solidrectangle(810, 10, 873, 43);//画一个实心的绿色矩形
				setcolor(WHITE);
				rectangle(810, 10, 870, 40);    //画一个矩形边框
				outtextxy(810 + 14, 17, L"退出");
			}
		}
		i = Izhi(i);//判断i值在哪个颜色区域内并闪烁一次绿色，执行相应功能并重置i值为0
		if (j == 1 && m.y >= 50)
		{
			
			Huabi(i);//画笔工具
		}
		if (j == 2 && m.y >= 50)
		{
			ZhixianYuan(i,j);//直线工具
		}
		if (j == 3 && m.y >= 50)
		{
			Quxian(i);//曲线工具
		}
		if (j == 4 && m.y >= 50)
		{
			ZhixianYuan(i,j);//画圆工具
		}
		if (j == 5)
		{
			Tianchong();//填充工具
		}
		if (j == 6 )
		{
			cleardevice();//用背景色清空屏幕
			goto A;
		}
		if (j == 7)//退出
		{
			setfillcolor(WHITE);  //设置实心颜色为白
			solidrectangle(310, 210, 570, 340);//画一个实心的红色矩形
			while (1)
			{
				setbkmode(TRANSPARENT);   				     //字符透明
				settextcolor(BLACK);
				outtextxy(320, 220, L"是否确认退出？");
				setcolor(BLACK);
				rectangle(330, 300, 390, 330);    //画一个矩形边框
				outtextxy(344, 307, L"确认");   //将这两字写在上面画的矩形边框里
				rectangle(410, 300, 470, 330);    //画一个矩形边框
				outtextxy(424, 307, L"重启");   //将这两字写在上面画的矩形边框里
				rectangle(490, 300, 550, 330);    //画一个矩形边框
				outtextxy(504, 307, L"取消");   //将这两字写在上面画的矩形边框里
				MOUSEMSG k;// 定义消息变量
				k = GetMouseMsg();// 获取一条鼠标或按键消息
				if (k.uMsg == WM_LBUTTONDOWN)//判断鼠标点击位置
				{
					if (k.x >= 330 && k.x <= 390 && k.y >= 300 && k.y <= 330)
					{
						closegraph();			// 关闭图形界面
					}
					if (k.x >= 410 && k.x <= 470 && k.y >= 300 && k.y <= 330)
					{
						cleardevice();//用背景色清空屏幕
						goto A;
					}
					if (k.x >= 490 && k.x <= 550 && k.y >= 300 && k.y <= 330)
					{
						setfillcolor(BLACK);  //设置实心颜色为白
						solidrectangle(310, 210, 570, 340);//画一个实心的红色矩形
						goto A;
					}
				}
			}
		}

	}

}


int main()
{
	Kaishi();//开始
	initgraph(880, 600);

	setbkcolor(BLACK);//设置背景色
	cleardevice();//使用背景色清屏
	Shubiao();//开始判断鼠标坐标
	_getch();				// 按任意键继续
	closegraph();			// 关闭图形界面
	return 0;
}
