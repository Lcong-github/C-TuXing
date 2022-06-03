#include"tool.h"
TCHAR a[100];

void Shubiao()
{
	A:Caidanlan();//菜单栏
	int x = 0, y = 0;//存储鼠标坐标
	int i = 0, j = 0;
	MOUSEMSG m;// 定义消息变量
	while (true)
	{
		m = GetMouseMsg();// 获取一条鼠标或按键消息
		//setfillcolor(BLACK);
		//solidrectangle(0, 500, 100, 470);  //用黑色矩形(界面是黑色)覆盖上次的坐标
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
			else if (x >= 300 && x <= 390 && y >= 10 && y <= 40)//画笔
				j = 1;
			else if (x >= 410 && x <= 470 && y >= 10 && y <= 40)//直线
				j = 2;
			else if (x >= 490 && x <= 550 && y >= 10 && y <= 40)//曲线
				j = 3;
			else if (x >= 570 && x <= 630 && y >= 10 && y <= 40)//圆
				j = 4;
			else if (x >= 650 && x <= 710 && y >= 10 && y <= 40)//填充
				j = 5;
			else if (x >= 730 && x <= 790 && y >= 10 && y <= 40)//清空
				j = 6;
		}
		i = Izhi(i);//判断i值在哪个颜色区域内并闪烁一次绿色，执行相应功能并重置i值为0
		//Jzhi(j);//判断j值并执行相应功能
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

	}

}


int main()
{
	initgraph(800, 600);
	Shubiao();//开始判断鼠标坐标
	_getch();				// 按任意键继续
	closegraph();			// 关闭图形界面
	return 0;
}
