#include"tool.h"
TCHAR b[100];

void Caidanlan()//�˵���
{
	setcolor(WHITE);
	outtextxy(10, 10, L"��");
	outtextxy(10, 30, L"ɫ");
	setfillcolor(WHITE);  //����ʵ����ɫΪ��
	solidrectangle(40, 10, 80, 40);//��һ��ʵ�ĵĺ�ɫ����
	setfillcolor(BLUE);  //����ʵ����ɫΪ��
	solidrectangle(100, 10, 140, 40);//��һ��ʵ�ĵĺ�ɫ����
	setfillcolor(YELLOW);  //����ʵ����ɫΪ��
	solidrectangle(160, 10, 200, 40);//��һ��ʵ�ĵĺ�ɫ����
	setfillcolor(RED);  //����ʵ����ɫΪ��
	solidrectangle(220, 10, 260, 40);//��һ��ʵ�ĵĺ�ɫ����
	outtextxy(300, 10, L"��");
	outtextxy(300, 30, L"��");
	rectangle(330, 10, 390, 40);    //��һ�����α߿�
	outtextxy(344, 17, L"����");   //��������д�����滭�ľ��α߿���
	rectangle(410, 10, 470, 40);    //��һ�����α߿�
	outtextxy(424, 17, L"ֱ��");   //��������д�����滭�ľ��α߿���
	rectangle(490, 10, 550, 40);    //��һ�����α߿�
	outtextxy(504, 17, L"����");   //��������д�����滭�ľ��α߿���
	rectangle(570, 10, 630, 40);    //��һ�����α߿�
	outtextxy(584, 17, L"��Բ");   //��������д�����滭�ľ��α߿���
	rectangle(650, 10, 710, 40);    //��һ�����α߿�
	outtextxy(664, 17, L"���");   //��������д�����滭�ľ��α߿���
	rectangle(730, 10, 790, 40);    //��һ�����α߿�
	outtextxy(744, 17, L"����");   //��������д�����滭�ľ��α߿���
	rectangle(810, 10, 870, 40);    //��һ�����α߿�
	outtextxy(824, 17, L"�˳�");   //��������д�����滭�ľ��α߿���
	setcolor(WHITE);
	line(0, 50, 880, 50);//�˵����ֽ���
}



int Izhi(int i)//iֵ
{
	switch (i)//�ж�iֵ��������Ӧ��Ӧ
	{
	case 1:
		setfillcolor(GREEN);  //����仯��ɫ
		solidrectangle(40, 10, 80, 40);//��һ��ʵ�ĵ���ɫ����
		Sleep(100);
		setfillcolor(WHITE);  //����仯��ɫ
		solidrectangle(40, 10, 80, 40);//��һ��ʵ�ĵİ�ɫ����
		setcolor(WHITE);
		return 0;
	case 2:
		setfillcolor(GREEN);  //����仯��ɫ
		solidrectangle(100, 10, 140, 40);//��һ��ʵ�ĵ���ɫ����
		Sleep(100);
		setfillcolor(BLUE);  //����仯��ɫ
		solidrectangle(100, 10, 140, 40);//��һ��ʵ�ĵİ�ɫ����
		setcolor(BLUE);
		return 0;
	case 3:
		setfillcolor(GREEN);  //����仯��ɫ
		solidrectangle(160, 10, 200, 40);//��һ��ʵ�ĵ���ɫ����
		Sleep(100);
		setfillcolor(YELLOW);  //����仯��ɫ
		solidrectangle(160, 10, 200, 40);//��һ��ʵ�ĵĻ�ɫ����
		setcolor(YELLOW);
		return 0;
	case 4:
		setfillcolor(GREEN);  //����仯��ɫ
		solidrectangle(220, 10, 260, 40);//��һ��ʵ�ĵ���ɫ����
		Sleep(100);
		setfillcolor(RED);  //����仯��ɫ
		solidrectangle(220, 10, 260, 40);//��һ��ʵ�ĵĺ�ɫ����
		setcolor(RED);
		return 0;
	default:
		return 0;
	}
}


void Huabi(int i)//ʵ�ֻ��ʹ���
{
	MOUSEMSG m;
	int x = 0;
	int y = 0;
	int flag = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	flag = 0;
	while (1)
	{
		m = GetMouseMsg();
		x = m.x, y = m.y;
		setfillcolor(BLACK);
		solidrectangle(0, 570, 100, 600);
		_stprintf_s(b, _T("[%d,%d]"), x, y);
		//setcolor(WHITE);
		outtextxy(0, 580, b);
		i = Izhi(i);//�ж�iֵ���ĸ���ɫ�����ڲ���˸һ����ɫ��ִ����Ӧ���ܲ�����iֵΪ0

		if (m.y >= 0 && m.y < 50)//�ж�����Ƿ��ڿɻ�������
		{
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN)//�ж�����Ƿ���
		{
			if (flag == 0)
			{
				x1 = m.x;
				y1 = m.y;
				flag = 1;
			}
		}
		else if (m.uMsg == WM_MOUSEMOVE && flag == 1)//�ж�����Ƿ���������
		{
			x2 = m.x;
			y2 = m.y;
			line(x1, y1, x2, y2);
			x1 = x2;
			y1 = y2;
		}
		if (m.uMsg == WM_LBUTTONUP)//�ж�����Ƿ���
			flag = 0;
	}
}


void ZhixianYuan(int i,int j)//ʵ��ֱ�߹��ߺͻ�Բ
{
	MOUSEMSG m;
	int x = 0;
	int y = 0;
	int flag = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	flag = 0;
	while (1)
	{
		m = GetMouseMsg();
		x = m.x, y = m.y;
		setfillcolor(BLACK);
		solidrectangle(0, 570, 100, 600);
		_stprintf_s(b, _T("[%d,%d]"), x, y);
		//setcolor(WHITE);
		outtextxy(0, 580, b);
		i = Izhi(i);//�ж�iֵ���ĸ���ɫ�����ڲ���˸һ����ɫ��ִ����Ӧ���ܲ�����iֵΪ0

		if (m.y >= 0 && m.y < 50)//�ж�����Ƿ��ڿɻ�������
		{
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN)//�ж�����Ƿ���
		{
			if (flag == 0)
			{
				x1 = m.x;
				y1 = m.y;
				flag = 1;
			}
		}
		else if (m.uMsg == WM_LBUTTONUP && flag == 1)//�ж�����Ƿ���
		{
			x2 = m.x;
			y2 = m.y;
			if (j == 2)
			{
				line(x1, y1, x2, y2);//�е㻭���㷨
			}
			if (j == 4)
			{
				Yuan(x1, y1, x2, y2);//�е㻭Բ�㷨
			}
			flag = 0;
		}
			
	}
}

void Quxian(int i)//ʵ�����߹���
{
	MOUSEMSG m;
	int x = 0;
	int y = 0;
	int flag = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
	flag = 0;
	while (1)
	{
		m = GetMouseMsg();
		x = m.x, y = m.y;
		setfillcolor(BLACK);
		solidrectangle(0, 570, 100, 600);
		_stprintf_s(b, _T("[%d,%d]"), x, y);
		//setcolor(WHITE);
		outtextxy(0, 580, b);
		i = Izhi(i);//�ж�iֵ���ĸ���ɫ�����ڲ���˸һ����ɫ��ִ����Ӧ���ܲ�����iֵΪ0

		if (m.y >= 0 && m.y < 50)//�ж�����Ƿ��ڿɻ�������
		{
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN && flag == 0)//�ж�����Ƿ���
		{
			
				x1 = m.x;
				y1 = m.y;
				flag = 1;
			
		}
		else if (m.uMsg == WM_LBUTTONUP && flag == 1)//�ж�����Ƿ���
		{
			x2 = m.x;
			y2 = m.y;
			line(x1, y1, x2, y2);
			flag = 2;
		}
		else if (m.uMsg == WM_LBUTTONDOWN && flag == 2)//�ж�����Ƿ��ٴΰ���
		{
			x3 = m.x;
			y3 = m.y;
			
			
			BezierQuxian(x1, y1, x2, y2, x3, y3);//Bezier����
			setcolor(BLACK);
			line(x1, y1, x2, y2);//�ñ���ɫ����֮ǰ��ֱ��
			setcolor(WHITE);//�ָ�Ĭ�ϰ�ɫ�������޷���ʾ����
			flag = 0;
		}

	}
}


void Tianchong()//ʵ����乤��
{
	MOUSEMSG m;
	int x = 0;
	int y = 0;
	int flag = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	flag = 0;
	int newcolor;
	while (1)
	{
		m = GetMouseMsg();
		x = m.x, y = m.y;
		setfillcolor(BLACK);
		solidrectangle(0, 570, 100, 600);
		_stprintf_s(b, _T("[%d,%d]"), x, y);
		outtextxy(0, 580, b);

		if (m.x >= 330 && m.x <= 800 && m.y >= 0 && m.y < 50)//�ж�����Ƿ��ڿɻ�������
		{
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN && flag == 0)//�ж�����Ƿ���
		{
			
				x = m.x, y = m.y;
				if (x >= 40 && x <= 80 && y >= 10 && y <= 40)//��
				{
					newcolor = WHITE;
					flag = 1;
				}
				else if (x >= 100 && x <= 140 && y >= 10 && y <= 40)//��
				{
					newcolor = BLUE;
					flag = 1;
				}
				
				else if (x >= 160 && x <= 200 && y >= 10 && y <= 40)//��
				{
					newcolor = YELLOW;
					flag = 1;
				}
				else if (x >= 200 && x <= 260 && y >= 10 && y <= 40)//��
				{
					newcolor = RED;
					flag = 1;
				}
			
		}
		else if (m.uMsg == WM_LBUTTONUP && flag == 1)//�ж�����Ƿ���
		{
			
			flag = 2;
		}
		else if (m.uMsg == WM_LBUTTONDOWN && flag == 2)//�ж�����Ƿ��ٴΰ���
		{
			x2 = m.x;
			y2 = m.y;
			FloodFILL(x2, y2, BLACK, newcolor);//����ͨ������㷨
			flag = 0;
		}

	}
}