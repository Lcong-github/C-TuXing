
#include <graphics.h>			// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <stdio.h>
//�ֹ��޸Ķ�ջ�Ĵ�С

void FloodFILL8(int x, int y, int bodercolor, int newcolor)
{

	int color = getpixel(x, y);
	if (color != bodercolor && color != newcolor)		//�ж��Ƿ��˱߽�
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


//������ɫ���ο�EasyX�����ֲ�
COLORREF BoundaryClr = RGB(0, 0, 0);//�߽�ɫ����ɫ
COLORREF SeedClr = RGB(255, 0, 0);//����ɫ����ɫ



int main()
{
	initgraph(640, 480, EW_SHOWCONSOLE);
	// �ñ���ɫ�����Ļ
	cleardevice();

	// ��ȡͼƬ����ͼ����
	IMAGE img;
	loadimage(NULL, _T("D:\\LCONG\\RLCONG\\������\\�����ͼ��\\�ϻ���ϰ2\\cow.bmp"));


	//��ʼ��������
	int init_x = 90;
	int init_y = 90;


	//��������������㷨���ɣ�����д�ɺ������õ���ʽ���磺
	FloodFILL8(init_x, init_y, BLACK, RED);
	_getch();
	closegraph();
	return 0;
}