#include <graphics.h>			// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <math.h>
#include <stdio.h>

#define PI 3.1415926//Բ����
double M[3][3];//�任����

//��������
void drawCoord(int cx, int cy)
{
	setcolor(GREEN);
	line(-cx, 0, cx, 0);
	line(0, cy, 0, -cy);

}
//���ص�ṹ�嶨�壬����x,y����
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

//��λ����
void Identity(void)
{
	M[0][0] = 1.0, M[0][1] = 0.0, M[0][2] = 0.0;
	M[1][0] = 0.0, M[1][1] = 1.0, M[1][2] = 0.0;
	M[2][0] = 0.0, M[2][1] = 0.0, M[2][2] = 1.0;

}
//�������
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
//ƽ�Ʊ任����
void Translate(double tx, double ty)
{
	Identity();
	M[0][2] = tx;
	M[1][2] = ty;
}
//��ת�任����
void Rotate(double theta)
{
	Identity();
	M[0][0] = cos(theta * PI / 180), M[0][1] = -sin(theta * PI / 180);
	M[1][0] = sin(theta * PI / 180), M[1][1] = cos(theta * PI / 180);
}

//�����ɫ
void FloodFILL(int x,int y, int bodercolor, int newcolor)
{
	
	int color = getpixel(x, y);
	if (color != bodercolor && color != newcolor)		//�ж��Ƿ��˱߽�
	{
		putpixel(x, y, newcolor);
		FloodFILL(x, y + 1, bodercolor, newcolor);
		FloodFILL(x, y - 1, bodercolor, newcolor);
		FloodFILL(x - 1, y, bodercolor, newcolor);
		FloodFILL(x + 1, y, bodercolor, newcolor);
	}
}

//��������
void Core(double x1, double y1, double x2, double y2)
{
	int d = int((x1 + x2) / 3);
	int t = int((y1 + y2) / 3);
	FloodFILL(d, t, RED, RED);
}

void Draw()
{
	struct point p1 = { 0,100,1 };//ԭͼ������
	struct point p2 = { 100,100,1 };
	struct point p3 = { -100,0,1 };
	struct point p4 = { -100,100,1 };
	struct point p5 = { 0,-100,1 };
	struct point p6 = { -100,-100,1 };
	struct point p7 = { 100,0,1 };
	struct point p8 = { 100,-100,1 };
	for (int i = 0, j = 1; i < j; i++, j++) {
		drawCoord(320, 240);//����������
		setcolor(RED);//ѡ�������ɫ
		//���Ƴ�ʼͼ��
		line(0, 0, p1.x, p1.y);
		line(0, 0, p2.x, p2.y);
		line(p1.x, p1.y, p2.x, p2.y);
		Core(p1.x, p1.y, p2.x, p2.y);//�������Ĳ����

		line(0, 0, p3.x, p3.y);
		line(0, 0, p4.x, p4.y);
		line(p3.x, p3.y, p4.x, p4.y);
		Core(p3.x, p3.y, p4.x, p4.y);

		line(0, 0, p5.x, p5.y);
		line(0, 0, p6.x, p6.y);
		line(p5.x, p5.y, p6.x, p6.y);
		Core(p5.x, p5.y, p6.x, p6.y);

		line(0, 0, p7.x, p7.y);
		line(0, 0, p8.x, p8.y);
		line(p7.x, p7.y, p8.x, p8.y);
		Core(p7.x, p7.y, p8.x, p8.y);

		Sleep(10);//ͣ��
		cleardevice();//�����Ļ
		Rotate(30.0);	//��ת30��

		//��ͼ�ζ�Ӧ������б任����
		MultiplyMatrix(&p1);
		MultiplyMatrix(&p2);
		MultiplyMatrix(&p3);
		MultiplyMatrix(&p4);
		MultiplyMatrix(&p5);
		MultiplyMatrix(&p6);
		MultiplyMatrix(&p7);
		MultiplyMatrix(&p8);

		//����������
		drawCoord(320, 240);
		setcolor(RED);
		//���Ʊ任��ͼ��
		setfillcolor(BLUE);
		line(0, 0, p1.x, p1.y);
		line(0, 0, p2.x, p2.y);
		line(p1.x, p1.y, p2.x, p2.y);
		Core(p1.x, p1.y, p2.x, p2.y);

		line(0, 0, p3.x, p3.y);
		line(0, 0, p4.x, p4.y);
		line(p3.x, p3.y, p4.x, p4.y);
		Core(p3.x, p3.y, p4.x, p4.y);

		line(0, 0, p5.x, p5.y);
		line(0, 0, p6.x, p6.y);
		line(p5.x, p5.y, p6.x, p6.y);
		Core(p5.x, p5.y, p6.x, p6.y);

		line(0, 0, p7.x, p7.y);
		line(0, 0, p8.x, p8.y);
		line(p7.x, p7.y, p8.x, p8.y);
		Core(p7.x, p7.y, p8.x, p8.y);

		Sleep(10);//ͣ��
		cleardevice();//�����Ļ
		Rotate(30.0);	//��ת30��

		//��ͼ�ζ�Ӧ������б任����
		MultiplyMatrix(&p1);
		MultiplyMatrix(&p2);
		MultiplyMatrix(&p3);
		MultiplyMatrix(&p4);
		MultiplyMatrix(&p5);
		MultiplyMatrix(&p6);
		MultiplyMatrix(&p7);
		MultiplyMatrix(&p8);
	}
}

int main()
{
	// ��ʼ����ͼ����
	initgraph(640, 480, EW_SHOWCONSOLE);
	setbkcolor(WHITE);//��ͼ����ɫ
	cleardevice();// �ñ���ɫ�����Ļ
	setorigin(320, 240);//��������ԭ��
	setaspectratio(1, -1); //��ʹ y ������Ϊ��
	Draw();					//ʵ�ֻ��ơ���䡢��ת
	_getch();				// �����������
	closegraph();			// �ر�ͼ�ν���
	return 0;
}