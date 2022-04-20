
#include <graphics.h>			// 引用图形库头文件
#include <conio.h>
#include <stdio.h>
//手工修改堆栈的大小

void FloodFILL8(int x, int y, int bodercolor, int newcolor)
{

	int color = getpixel(x, y);
	if (color != bodercolor && color != newcolor)		//判断是否到了边界
	{
		putpixel(x, y, newcolor);
		printf("x=%d,y=%d\n", x, y);
		FloodFILL8(x, y + 1, bodercolor, newcolor);
		FloodFILL8(x + 1, y + 1, bodercolor, newcolor);
		FloodFILL8(x - 1, y + 1, bodercolor, newcolor);
		FloodFILL8(x, y - 1, bodercolor, newcolor);
		FloodFILL8(x + 1, y - 1, bodercolor, newcolor);
		FloodFILL8(x - 1, y, bodercolor, newcolor);
		FloodFILL8(x - 1, y - 1, bodercolor, newcolor);
		FloodFILL8(x + 1, y, bodercolor, newcolor);

	}
}


//定义颜色，参考EasyX帮助手册
COLORREF BoundaryClr = RGB(0, 0, 0);//边界色，黑色
COLORREF SeedClr = RGB(255, 0, 0);//种子色，红色



int main()
{
	initgraph(640, 480, EW_SHOWCONSOLE);
	// 用背景色清空屏幕
	cleardevice();

	// 读取图片至绘图窗口
	IMAGE img;
	loadimage(NULL, _T("D:\\LCONG\\RLCONG\\大三下\\计算机图形\\上机练习2\\cow.bmp"));


	//初始种子坐标
	int init_x = 90;
	int init_y = 90;


	//这里添加你的填充算法即可，可以写成函数调用的形式，如：
	FloodFILL8(init_x, init_y, BLACK, RED);
	_getch();
	closegraph();
	return 0;
}