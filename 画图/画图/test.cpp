#include"tool.h"
TCHAR a[100];

void Shubiao()
{
	A:Caidanlan();//�˵���
	int x = 0, y = 0;//�洢�������
	int i = 0, j = 0;
	MOUSEMSG m;// ������Ϣ����
	while (true)
	{
		m = GetMouseMsg();// ��ȡһ�����򰴼���Ϣ
		//setfillcolor(BLACK);
		//solidrectangle(0, 500, 100, 470);  //�ú�ɫ����(�����Ǻ�ɫ)�����ϴε�����
		//��Ϊ������ƶ��Ĺ���������λ���ǲ��ϱ仯��
		_stprintf_s(a, _T("[%d,%d]"), m.x, m.y);//������д���ַ���a��
		//setcolor(WHITE);
		outtextxy(0, 580, a);//ѭ����ӡ��ǰ����λ��

		if (m.uMsg == WM_LBUTTONDOWN)//�ж������λ��
		{
			x = m.x, y = m.y;
			if (x >= 40 && x <= 80 && y >= 10 && y <= 40)//��
				i = 1;
			else if (x >= 100 && x <= 140 && y >= 10 && y <= 40)//��
				i = 2;
			else if (x >= 160 && x <= 200 && y >= 10 && y <= 40)//��
				i = 3;
			else if (x >= 200 && x <= 260 && y >= 10 && y <= 40)//��
				i = 4;
			else if (x >= 300 && x <= 390 && y >= 10 && y <= 40)//����
				j = 1;
			else if (x >= 410 && x <= 470 && y >= 10 && y <= 40)//ֱ��
				j = 2;
			else if (x >= 490 && x <= 550 && y >= 10 && y <= 40)//����
				j = 3;
			else if (x >= 570 && x <= 630 && y >= 10 && y <= 40)//Բ
				j = 4;
			else if (x >= 650 && x <= 710 && y >= 10 && y <= 40)//���
				j = 5;
			else if (x >= 730 && x <= 790 && y >= 10 && y <= 40)//���
				j = 6;
		}
		i = Izhi(i);//�ж�iֵ���ĸ���ɫ�����ڲ���˸һ����ɫ��ִ����Ӧ���ܲ�����iֵΪ0
		//Jzhi(j);//�ж�jֵ��ִ����Ӧ����
		if (j == 1 && m.y >= 50)
		{
			Huabi(i);//���ʹ���
		}
		if (j == 2 && m.y >= 50)
		{
			ZhixianYuan(i,j);//ֱ�߹���
		}
		if (j == 3 && m.y >= 50)
		{
			Quxian(i);//���߹���
		}
		if (j == 4 && m.y >= 50)
		{
			ZhixianYuan(i,j);//��Բ����
		}
		if (j == 5)
		{
			Tianchong();//��乤��
		}
		if (j == 6 )
		{
			cleardevice();//�ñ���ɫ�����Ļ
			goto A;
		}

	}

}


int main()
{
	initgraph(800, 600);
	Shubiao();//��ʼ�ж��������
	_getch();				// �����������
	closegraph();			// �ر�ͼ�ν���
	return 0;
}
