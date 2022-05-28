#include"game.h"

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


//for循环实现
void Draw(int x1, int y1, int x2, int y2, int n,int s)
{
	struct point p1 = { x1,y1,1 };//原图形坐标
	struct point p2 = { x2,y2,1 };
	float angle = 360 / n;
	for (int j = 0, k = 1; j < k; j++, k++)
	{
		//drawCoord(320, 240);//绘制坐标轴
		for (int i = 0; i < n; i++) {

			Draon(p1.x, p1.y, p2.x, p2.y);//实现三角形的绘制并明暗处理
			Rotate(angle);
			MultiplyMatrix(&p1);
			MultiplyMatrix(&p2);
		}
		Sleep(s);//停留
		cleardevice();//清空屏幕
		Rotate(30.0);	//旋转30
		MultiplyMatrix(&p1);
		MultiplyMatrix(&p2);
	}
}


int main()
{
	int n = 0;
	printf("请问要绘制几叶风车: ");
	scanf("%d", &n);
	float m = 0;
	printf("请问风车半径多大: ");
	scanf("%f", &m);
	while (1)
	{
		int k = 0;
		printf("请问风车旋转速度(如 1、2、3、4、5): ");
		scanf("%d", &k);
		if (0 < k <= 5)
		{
			int j = 0;//计算旋转速度
			j = 510 - k * 100;
			// 初始化绘图窗口
			initgraph(640, 480, EW_SHOWCONSOLE);
			//setbkcolor(WHITE);//绘图背景色
			cleardevice();// 用背景色清空屏幕
			setorigin(320, 240);//设置坐标原点
			setaspectratio(1, -1); //可使 y 轴向上为正
			Draw(0, m, m, m, n, j);				//实现绘制、填充、旋转
		}
		else
		{
			printf("--------------------------------------\n");
			printf("输入错误...\n");
		}
	}
	_getch();				// 按任意键继续
	closegraph();			// 关闭图形界面
	return 0;
}