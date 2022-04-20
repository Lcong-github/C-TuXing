#define _CRT_SECURE_NO_WARNINGS 1
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
void FloodFILL(int x, int y, int bodercolor, int newcolor)
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

//forѭ��ʵ��
//void Draw(int x1, int y1, int x2, int y2)
//{
//	struct point p1 = { x1,y1,1 };//ԭͼ������
//	struct point p2 = { x2,y2,1 };
//
//	for (int j = 0, k = 1; j < k; j++, k++)
//	{
//		drawCoord(320, 240);//����������
//		for (int i = 0; i < 4; i++) {
//			setcolor(RED);//ѡ�������ɫ
//			line(0, 0, p1.x, p1.y);
//			line(0, 0, p2.x, p2.y);
//			line(p1.x, p1.y, p2.x, p2.y);
//			Core(p1.x, p1.y, p2.x, p2.y);//�������Ĳ����
//			Rotate(90.0);
//			MultiplyMatrix(&p1);
//			MultiplyMatrix(&p2);
//		}
//		Sleep(100);//ͣ��
//		cleardevice();//�����Ļ
//		Rotate(30.0);	//��ת30
//		MultiplyMatrix(&p1);
//		MultiplyMatrix(&p2);
//	}
//}

//�ݹ�ʵ��
void Draw(int x1, int y1,int x2,int y2)
{
	struct point p1 = { x1,y1,1 };//ԭͼ������
	struct point p2 = { x2,y2,1 };
	drawCoord(320, 240);//����������
	for (int i = 0; i < 4; i++) {
		setcolor(RED);//ѡ�������ɫ
		line(0, 0, p1.x, p1.y);
		line(0, 0, p2.x, p2.y);
		line(p1.x, p1.y, p2.x, p2.y);
		Core(p1.x, p1.y, p2.x, p2.y);//�������Ĳ����
		Rotate(90.0);	//��ת90��
		MultiplyMatrix(&p1);
		MultiplyMatrix(&p2);
	}
	Sleep(10);//ͣ��
	cleardevice();//�����Ļ
	Rotate(30.0);	//������ת30��
	MultiplyMatrix(&p1);
	MultiplyMatrix(&p2);
	Draw(p1.x, p1.y, p2.x, p2.y);

}



int main()
{
	// ��ʼ����ͼ����
	initgraph(640, 480, EW_SHOWCONSOLE);
	setbkcolor(WHITE);//��ͼ����ɫ
	cleardevice();// �ñ���ɫ�����Ļ
	setorigin(320, 240);//��������ԭ��
	setaspectratio(1, -1); //��ʹ y ������Ϊ��
	Draw(0,100,100,100);					//ʵ�ֻ��ơ���䡢��ת
	_getch();				// �����������
	closegraph();			// �ر�ͼ�ν���
	return 0;
}