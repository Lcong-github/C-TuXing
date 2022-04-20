
#include <graphics.h>			// 引用图形库头文件
#include <conio.h>
#include<Windows.h>
#include <math.h>
int main()
{
	// 初始化绘图窗口
	initgraph(640, 480);

	// 设置背景色为蓝色
	setbkcolor(GREEN);
	// 用背景色清空屏幕
	cleardevice();

	// 设置绘图色为红色
	setcolor(RED);
	// DDA画第一象限直线

	int x1 = 200, y1 = 250, x2 = 500, y2 = 300, c;
	float k, p;
	putpixel(x1, y1, RED);
	k = (float)(y2 - y1) / (x2 - x1);
	p = k + 0.5;
	for (int i = 1; i < 301; i++) {
		c = floor(y1 + p);
		putpixel(x1 + i, c, RED);
		p = p + k;
	}
	_getch();				// 按任意键继续
	closegraph();			// 关闭图形界面
}