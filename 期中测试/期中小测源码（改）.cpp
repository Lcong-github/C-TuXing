#define _CRT_SECURE_NO_WARNINGS 1
#include <graphics.h>			// 引用图形库头文件
#include <conio.h>
#include <math.h>
#include <stdio.h>

#define PI 3.1415926//圆周率
double M[3][3];//变换矩阵

//绘制坐标
void drawCoord(int cx, int cy)
{
	setcolor(GREEN);
	line(-cx, 0, cx, 0);
	line(0, cy, 0, -cy);

}
//像素点结构体定义，包含x,y坐标
struct point
{
	double x;
	double y;
	double w;
};
void showPoint(struct point p)
{
	printf("x=%lf,y=%lf\n", p.x, p.y);
}

//单位矩阵
void Identity(void)
{
	M[0][0] = 1.0, M[0][1] = 0.0, M[0][2] = 0.0;
	M[1][0] = 0.0, M[1][1] = 1.0, M[1][2] = 0.0;
	M[2][0] = 0.0, M[2][1] = 0.0, M[2][2] = 1.0;

}
//矩阵相乘
void MultiplyMatrix(struct point* p)
{
	struct point ptemp;
	ptemp.x = M[0][0] * p->x + M[0][1] * p->y + M[0][2] * p->w;
	ptemp.y = M[1][0] * p->x + M[1][1] * p->y + M[1][2] * p->w;
	ptemp.w = M[2][0] * p->x + M[2][1] * p->y + M[2][2] * p->w;
	p->x = ptemp.x;
	p->y = ptemp.y;
	p->w = ptemp.w;

}
//平移变换矩阵
void Translate(double tx, double ty)
{
	Identity();
	M[0][2] = tx;
	M[1][2] = ty;
}
//旋转变换矩阵
void Rotate(double theta)
{
	Identity();
	M[0][0] = cos(theta * PI / 180), M[0][1] = -sin(theta * PI / 180);
	M[1][0] = sin(theta * PI / 180), M[1][1] = cos(theta * PI / 180);
}

//填充颜色
void FloodFILL(int x, int y, int bodercolor, int newcolor)
{
	int color = getpixel(x, y);
	if (color != bodercolor && color != newcolor)		//判断是否到了边界
	{
		putpixel(x, y, newcolor);
		FloodFILL(x, y + 1, bodercolor, newcolor);
		FloodFILL(x, y - 1, bodercolor, newcolor);
		FloodFILL(x - 1, y, bodercolor, newcolor);
		FloodFILL(x + 1, y, bodercolor, newcolor);
	}
}

//计算重心
void Core(double x1, double y1, double x2, double y2)
{
	int d = int((x1 + x2) / 3);
	int t = int((y1 + y2) / 3);
	FloodFILL(d, t, RED, RED);
}

//for循环实现
//void Draw(int x1, int y1, int x2, int y2)
//{
//	struct point p1 = { x1,y1,1 };//原图形坐标
//	struct point p2 = { x2,y2,1 };
//
//	for (int j = 0, k = 1; j < k; j++, k++)
//	{
//		drawCoord(320, 240);//绘制坐标轴
//		for (int i = 0; i < 4; i++) {
//			setcolor(RED);//选择绘制颜色
//			line(0, 0, p1.x, p1.y);
//			line(0, 0, p2.x, p2.y);
//			line(p1.x, p1.y, p2.x, p2.y);
//			Core(p1.x, p1.y, p2.x, p2.y);//计算重心并填充
//			Rotate(90.0);
//			MultiplyMatrix(&p1);
//			MultiplyMatrix(&p2);
//		}
//		Sleep(100);//停留
//		cleardevice();//清空屏幕
//		Rotate(30.0);	//旋转30
//		MultiplyMatrix(&p1);
//		MultiplyMatrix(&p2);
//	}
//}

//递归实现
void Draw(int x1, int y1,int x2,int y2)
{
	struct point p1 = { x1,y1,1 };//原图形坐标
	struct point p2 = { x2,y2,1 };
	drawCoord(320, 240);//绘制坐标轴
	for (int i = 0; i < 4; i++) {
		setcolor(RED);//选择绘制颜色
		line(0, 0, p1.x, p1.y);
		line(0, 0, p2.x, p2.y);
		line(p1.x, p1.y, p2.x, p2.y);
		Core(p1.x, p1.y, p2.x, p2.y);//计算重心并填充
		Rotate(90.0);	//旋转90°
		MultiplyMatrix(&p1);
		MultiplyMatrix(&p2);
	}
	Sleep(10);//停留
	cleardevice();//清空屏幕
	Rotate(30.0);	//整体旋转30°
	MultiplyMatrix(&p1);
	MultiplyMatrix(&p2);
	Draw(p1.x, p1.y, p2.x, p2.y);

}



int main()
{
	// 初始化绘图窗口
	initgraph(640, 480, EW_SHOWCONSOLE);
	setbkcolor(WHITE);//绘图背景色
	cleardevice();// 用背景色清空屏幕
	setorigin(320, 240);//设置坐标原点
	setaspectratio(1, -1); //可使 y 轴向上为正
	Draw(0,100,100,100);					//实现绘制、填充、旋转
	_getch();				// 按任意键继续
	closegraph();			// 关闭图形界面
	return 0;
}