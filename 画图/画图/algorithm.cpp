#include"tool.h"

void Yuan(float x1, float y1, float x2, float y2)//中点画圆算法
{
	float r = 0;
	float x0 = (x1 + x2) / 2, y0 = (y1 + y2) / 2;
	r = (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))) / 2;

	float x, y, d;
	x = 0;
	y = r;		//（x,y）用于确定第一个点
	d = 1 - r;		//取得初始d

	float H;		//用于判断x或y循环的次数
	H = 1.414 * r / 2;
	for (int i = 1; i <= H+1; i++) {
		line(x + x0, y + y0, x + x0, y + y0);
		line(y + x0, x + y0, y + x0, x + y0);
		line(-x + x0, y + y0, -x + x0, y + y0);
		line(-y + x0, x + y0, -y + x0, x + y0);
		line(x + x0, -y + y0, x + x0, -y + y0);
		line(y + x0, -x + y0, y + x0, -x + y0);
		line(-x + x0, -y + y0, -x + x0, -y + y0);
		line(-y + x0, -x + y0, -y + x0, -x + y0);

		if (d < 0) {
			x = x + 1;
			d = d + 2 * x + 3;
		}
		else {
			x = x + 1;
			y = y - 1;
			d = d + 2 * (x - y) + 5;
		}
	}
}


void FloodFILL(int x, int y, int bodercolor, int newcolor)//四连通泛填充算法
{

	int color = getpixel(x, y);
	if (color == bodercolor )		//判断是否到了边界
	{
		putpixel(x, y, newcolor);
		FloodFILL(x, y + 1, bodercolor, newcolor);
		FloodFILL(x, y - 1, bodercolor, newcolor);
		FloodFILL(x - 1, y, bodercolor, newcolor);
		FloodFILL(x + 1, y, bodercolor, newcolor);
	}
}


void BezierQuxian(int x1,int y1,int x2,int y2,int x3,int y3)//Bezier曲线
{
	float t = 0;

	for (t = 0.001; t < 1; t = t + 0.00001)
	{
		float px01 = (1 - t) * x1 + t * x3;
		float px11 = (1 - t) * x3 + t * x2;
		float py01 = (1 - t) * y1 + t * y3;
		float py11 = (1 - t) * y3 + t * y2;

		float px02 = (1 - t) * px01 + t * px11;
		float py02 = (1 - t) * py01 + t * py11;
		line(px02, py02, px02, py02);

	}

}
