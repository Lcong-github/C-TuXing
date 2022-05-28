#include"game.h"

COLORREF lineColor = RGB(255, 0, 0);//红色

struct point
{
	double x;
	double y;
	COLORREF c;
};

COLORREF inter(double p0, double p1, double coord, COLORREF c0, COLORREF c1)//颜色线性插值
{
	COLORREF color;

	BYTE r1 = GetRValue(c0);
	BYTE g1 = GetGValue(c0);
	BYTE b1 = GetBValue(c0);

	BYTE r2 = GetRValue(c1);
	BYTE g2 = GetGValue(c1);
	BYTE b2 = GetBValue(c1);

	BYTE r3 = (p1 - coord) / (p1 - p0) * r1 + (coord - p0) / (p1 - p0) * r2;
	BYTE g3 = (p1 - coord) / (p1 - p0) * g1 + (coord - p0) / (p1 - p0) * g2;
	BYTE b3 = (p1 - coord) / (p1 - p0) * b1 + (coord - p0) / (p1 - p0) * b2;

	color = RGB(r3, g3, b3);

	return color;
}

//用于计算扫描线与三角形的交点
double Intersect(double x1, double y1, double x2, double y2, double y)
{
	double k = (y2 - y1) / (x2 - x1);
	double x = (y - y1) / k + x1;
	return x;
}

void Draon(double x1, double y1, double x2, double y2)
{
	struct point p1 = { x1,y1,RGB(250,0,0) };
	struct point p2 = { x2,y2,RGB(0,255,0) };
	struct point p0 = { 0,0,RGB(0,0,255) };

	struct point pa = { 0,0,RGB(0,0,0) };//建立一个无用坐标点，用于三角形坐标排序

	//确定p0.y<p1.y<p2.y
	if (p0.y > p1.y)
	{
		pa = p0;
		p0 = p1;
		p1 = pa;
	}
	if (p0.y > p2.y)
	{
		pa = p0;
		p0 = p2;
		p2 = pa;
	}
	if (p1.y > p2.y)
	{
		pa = p1;
		p1 = p2;
		p2 = pa;
	}

	for (int y = p0.y; y <= p2.y; y++)
	{
		double ax = Intersect(p0.x, p0.y, p2.x, p2.y, y);
		COLORREF c1 = inter(p0.y, p2.y, y, p0.c, p2.c);
		struct point a = { ax,y,c1 };
		//将三角形分成两端绘制，一部分是小于p1.y的部分，一部分是大于p1.y的部分
		if (y < p1.y)
		{
			double bx = Intersect(p0.x, p0.y, p1.x, p1.y, y);
			COLORREF c2 = inter(p0.y, p1.y, y, p0.c, p1.c);
			struct point b = { bx,y,c2 };
			if (a.x > b.x)//判断a.x和b.x的大小
			{
				double t = 0;
				t = a.x;
				a.x = b.x;
				b.x = t;
			}
			for (int x = a.x; x <= b.x; x++)
			{
				COLORREF color = inter(a.x, b.x, x, a.c, b.c);
				//printf("x=%d,y=%d\n", x, y);
				putpixel(x, y, color);
			}
		}
		else
		{
			double bx = Intersect(p2.x, p2.y, p1.x, p1.y, y);
			COLORREF c2 = inter(p2.y, p1.y, y, p2.c, p1.c);
			struct point b = { bx,y,c2 };
			if (a.x > b.x)
			{
				double t = 0;
				t = a.x;
				a.x = b.x;
				b.x = t;
			}
			for (int x = a.x; x <= b.x; x++)
			{
				COLORREF color = inter(a.x, b.x, x, a.c, b.c);
				//printf("x=%d,y=%d\n", x, y);
				putpixel(x, y, color);
			}
		}

	}
}
