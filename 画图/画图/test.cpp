#include"tool.h"
TCHAR a[100];

void Kaishi()
{
	initgraph(520, 360, NULL);
	IMAGE bgp;
	loadimage(&bgp, L"./am.jpg", 520, 360, false);//����ͼƬ
	putimage(0, 0, &bgp);
	setbkmode(TRANSPARENT);   				     //�ַ�͸��
	settextcolor(RGB(97, 274, 255));
	settextstyle(40, 30, L"����");
	outtextxy(20, 130, L"��ӭʹ��");
	Sleep(3000);
	closegraph;
}
void Shubiao()
{
	
A:
	IMAGE bgp;
	loadimage(&bgp, L"./am.jpg", 80, 40, false);//����ͼƬ
	putimage(800, 560, &bgp);
	Caidanlan();//�˵���
	int x = 0, y = 0;//�洢�������
	int i = 0, j = 0;
	MOUSEMSG m;// ������Ϣ����
	while (true)
	{
		B:m = GetMouseMsg();// ��ȡһ�����򰴼���Ϣ
		setfillcolor(BLACK);
		solidrectangle(0, 570, 100, 600); //�ú�ɫ����(�����Ǻ�ɫ)�����ϴε�����
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
			else if (x >= 330 && x <= 390 && y >= 10 && y <= 40)//����
			{
				j = 1;
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(330, 10, 390, 40);//��һ��ʵ�ĵ���ɫ����
				setfillcolor(GREEN);  //����ʵ����ɫΪ��
				solidrectangle(333, 13, 393, 43);//��һ��ʵ�ĵ���ɫ����
				setbkmode(TRANSPARENT);   				     //�ַ�͸��
				settextcolor(RGB(97, 274, 255));
				outtextxy(333 + 14, 20, L"����");
				Sleep(100);
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(330, 10, 393, 43);//��һ��ʵ�ĵ���ɫ����
				setcolor(WHITE);
				rectangle(330, 10, 390, 40);    //��һ�����α߿�
				outtextxy(330+14, 17, L"����");
				
			}
			else if (x >= 410 && x <= 470 && y >= 10 && y <= 40)//ֱ��
			{
				j = 2;
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(410, 10, 470, 40);//��һ��ʵ�ĵ���ɫ����
				setfillcolor(GREEN);  //����ʵ����ɫΪ��
				solidrectangle(413, 13, 473, 43);//��һ��ʵ�ĵ���ɫ����
				setbkmode(TRANSPARENT);   				     //�ַ�͸��
				settextcolor(RGB(97, 274, 255));
				outtextxy(413 + 14, 20, L"ֱ��");
				Sleep(100);
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(410, 10, 473, 43);//��һ��ʵ�ĵ���ɫ����
				setcolor(WHITE);
				rectangle(410, 10, 470, 40);    //��һ�����α߿�
				outtextxy(410 + 14, 17, L"ֱ��");
			}
			else if (x >= 490 && x <= 550 && y >= 10 && y <= 40)//����
			{
				j = 3;
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(490, 10, 550, 40);//��һ��ʵ�ĵ���ɫ����
				setfillcolor(GREEN);  //����ʵ����ɫΪ��
				solidrectangle(493, 13, 553, 43);//��һ��ʵ�ĵ���ɫ����
				setbkmode(TRANSPARENT);   				     //�ַ�͸��
				settextcolor(RGB(97, 274, 255));
				outtextxy(493 + 14, 20, L"����");
				Sleep(100);
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(490, 10, 553, 43);//��һ��ʵ�ĵ���ɫ����
				setcolor(WHITE);
				rectangle(490, 10, 550, 40);    //��һ�����α߿�
				outtextxy(490 + 14, 17, L"����");
			}
			else if (x >= 570 && x <= 630 && y >= 10 && y <= 40)//Բ
			{
				j = 4;
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(570, 10, 630, 40);//��һ��ʵ�ĵ���ɫ����
				setfillcolor(GREEN);  //����ʵ����ɫΪ��
				solidrectangle(573, 13, 633, 43);//��һ��ʵ�ĵ���ɫ����
				setbkmode(TRANSPARENT);   				     //�ַ�͸��
				settextcolor(RGB(97, 274, 255));
				outtextxy(573 + 14, 20, L"��Բ");
				Sleep(100);
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(570, 10, 633, 43);//��һ��ʵ�ĵ���ɫ����
				setcolor(WHITE);
				rectangle(570, 10, 630, 40);    //��һ�����α߿�
				outtextxy(570 + 14, 17, L"��Բ");
			}
			else if (x >= 650 && x <= 710 && y >= 10 && y <= 40)//���
			{
				j = 5;
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(650, 10, 710, 40);//��һ��ʵ�ĵ���ɫ����
				setfillcolor(GREEN);  //����ʵ����ɫΪ��
				solidrectangle(653, 13, 713, 43);//��һ��ʵ�ĵ���ɫ����
				setbkmode(TRANSPARENT);   				     //�ַ�͸��
				settextcolor(RGB(97, 274, 255));
				outtextxy(653 + 14, 20, L"���");
				Sleep(100);
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(650, 10, 713, 43);//��һ��ʵ�ĵ���ɫ����
				setcolor(WHITE);
				rectangle(650, 10, 710, 40);    //��һ�����α߿�
				outtextxy(650 + 14, 17, L"���");
			}
			else if (x >= 730 && x <= 790 && y >= 10 && y <= 40)//���
			{
				j = 6;
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(730, 10, 790, 40);//��һ��ʵ�ĵ���ɫ����
				setfillcolor(GREEN);  //����ʵ����ɫΪ��
				solidrectangle(733, 13, 793, 43);//��һ��ʵ�ĵ���ɫ����
				setbkmode(TRANSPARENT);   				     //�ַ�͸��
				settextcolor(RGB(97, 274, 255));
				outtextxy(733 + 14, 20, L"����");
				Sleep(100);
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(730, 10, 793, 43);//��һ��ʵ�ĵ���ɫ����
				setcolor(WHITE);
				rectangle(730, 10, 790, 40);    //��һ�����α߿�
				outtextxy(730 + 14, 17, L"����");
			}
			else if (x >= 810 && x <= 870 && y >= 10 && y <= 40)//�˳�
			{
				j = 7;
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(810, 10, 870, 40);//��һ��ʵ�ĵ���ɫ����
				setfillcolor(GREEN);  //����ʵ����ɫΪ��
				solidrectangle(813, 13, 873, 43);//��һ��ʵ�ĵ���ɫ����
				setbkmode(TRANSPARENT);   				     //�ַ�͸��
				settextcolor(RGB(97, 274, 255));
				outtextxy(813 + 14, 20, L"�˳�");
				Sleep(100);
				setfillcolor(BLACK);  //����ʵ����ɫΪ��
				solidrectangle(810, 10, 873, 43);//��һ��ʵ�ĵ���ɫ����
				setcolor(WHITE);
				rectangle(810, 10, 870, 40);    //��һ�����α߿�
				outtextxy(810 + 14, 17, L"�˳�");
			}
		}
		i = Izhi(i);//�ж�iֵ���ĸ���ɫ�����ڲ���˸һ����ɫ��ִ����Ӧ���ܲ�����iֵΪ0
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
		if (j == 7)//�˳�
		{
			setfillcolor(WHITE);  //����ʵ����ɫΪ��
			solidrectangle(310, 210, 570, 340);//��һ��ʵ�ĵĺ�ɫ����
			while (1)
			{
				setbkmode(TRANSPARENT);   				     //�ַ�͸��
				settextcolor(BLACK);
				outtextxy(320, 220, L"�Ƿ�ȷ���˳���");
				setcolor(BLACK);
				rectangle(330, 300, 390, 330);    //��һ�����α߿�
				outtextxy(344, 307, L"ȷ��");   //��������д�����滭�ľ��α߿���
				rectangle(410, 300, 470, 330);    //��һ�����α߿�
				outtextxy(424, 307, L"����");   //��������д�����滭�ľ��α߿���
				rectangle(490, 300, 550, 330);    //��һ�����α߿�
				outtextxy(504, 307, L"ȡ��");   //��������д�����滭�ľ��α߿���
				MOUSEMSG k;// ������Ϣ����
				k = GetMouseMsg();// ��ȡһ�����򰴼���Ϣ
				if (k.uMsg == WM_LBUTTONDOWN)//�ж������λ��
				{
					if (k.x >= 330 && k.x <= 390 && k.y >= 300 && k.y <= 330)
					{
						closegraph();			// �ر�ͼ�ν���
					}
					if (k.x >= 410 && k.x <= 470 && k.y >= 300 && k.y <= 330)
					{
						cleardevice();//�ñ���ɫ�����Ļ
						goto A;
					}
					if (k.x >= 490 && k.x <= 550 && k.y >= 300 && k.y <= 330)
					{
						setfillcolor(BLACK);  //����ʵ����ɫΪ��
						solidrectangle(310, 210, 570, 340);//��һ��ʵ�ĵĺ�ɫ����
						goto A;
					}
				}
			}
		}

	}

}


int main()
{
	Kaishi();//��ʼ
	initgraph(880, 600);

	setbkcolor(BLACK);//���ñ���ɫ
	cleardevice();//ʹ�ñ���ɫ����
	Shubiao();//��ʼ�ж��������
	_getch();				// �����������
	closegraph();			// �ر�ͼ�ν���
	return 0;
}
