
#include <graphics.h>			// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include<Windows.h>
#include <math.h>
int main()
{
	// ��ʼ����ͼ����
	initgraph(640, 480);

	// ���ñ���ɫΪ��ɫ
	setbkcolor(GREEN);
	// �ñ���ɫ�����Ļ
	cleardevice();

	// ���û�ͼɫΪ��ɫ
	setcolor(RED);
	// DDA����һ����ֱ��

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
	_getch();				// �����������
	closegraph();			// �ر�ͼ�ν���
}