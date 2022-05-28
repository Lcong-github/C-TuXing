#include"game.h"

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


//forѭ��ʵ��
void Draw(int x1, int y1, int x2, int y2, int n,int s)
{
	struct point p1 = { x1,y1,1 };//ԭͼ������
	struct point p2 = { x2,y2,1 };
	float angle = 360 / n;
	for (int j = 0, k = 1; j < k; j++, k++)
	{
		//drawCoord(320, 240);//����������
		for (int i = 0; i < n; i++) {

			Draon(p1.x, p1.y, p2.x, p2.y);//ʵ�������εĻ��Ʋ���������
			Rotate(angle);
			MultiplyMatrix(&p1);
			MultiplyMatrix(&p2);
		}
		Sleep(s);//ͣ��
		cleardevice();//�����Ļ
		Rotate(30.0);	//��ת30
		MultiplyMatrix(&p1);
		MultiplyMatrix(&p2);
	}
}


int main()
{
	int n = 0;
	printf("����Ҫ���Ƽ�Ҷ�糵: ");
	scanf("%d", &n);
	float m = 0;
	printf("���ʷ糵�뾶���: ");
	scanf("%f", &m);
	while (1)
	{
		int k = 0;
		printf("���ʷ糵��ת�ٶ�(�� 1��2��3��4��5): ");
		scanf("%d", &k);
		if (0 < k <= 5)
		{
			int j = 0;//������ת�ٶ�
			j = 510 - k * 100;
			// ��ʼ����ͼ����
			initgraph(640, 480, EW_SHOWCONSOLE);
			//setbkcolor(WHITE);//��ͼ����ɫ
			cleardevice();// �ñ���ɫ�����Ļ
			setorigin(320, 240);//��������ԭ��
			setaspectratio(1, -1); //��ʹ y ������Ϊ��
			Draw(0, m, m, m, n, j);				//ʵ�ֻ��ơ���䡢��ת
		}
		else
		{
			printf("--------------------------------------\n");
			printf("�������...\n");
		}
	}
	_getch();				// �����������
	closegraph();			// �ر�ͼ�ν���
	return 0;
}