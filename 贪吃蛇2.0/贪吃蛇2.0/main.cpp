#include "head.h"
int count = 0;
int main()
{
	Kaishi();
	A:initgraph(840, 480);//��ʼ�����ڴ�С������Ϊ640*480�ֱ���
	setbkcolor(WHITE);//���ñ���ɫ
	cleardevice();//ʹ�ñ���ɫ����

	Init_Game();//��ʼ��
	srand((unsigned int)time(NULL));
	int n = 0;
	while (1)
	{

		if (_kbhit())//������̱��û��ͽ�����Ʒ�����
	
			Change_Move();//������
		
		else
		{
			Produce_Food();//����ʳ��
			count=Eat_Food(count);//�ж�ʳ���Ƿ񱻳�
			n = GameOver();//�ж���ͷ�Ƿ�ײǽ���Լ�
			if (n == 1)//����1��ײǽ���Լ�
			{
				
				closegraph();//�رմ���
				TCHAR a[100];
				initgraph(520, 360, NULL);
				IMAGE bgp;
				loadimage(&bgp, "./am.jpg", 520, 360, false);//����ͼƬ
				putimage(0, 0, &bgp);
				setbkmode(TRANSPARENT);   				     //�ַ�͸��
				settextcolor(BLUE);
				settextstyle(40, 30, "����");
				outtextxy(140, 50, "��Ϸ����");
				outtextxy(100, 150, "������");
				_stprintf_s(a, _T("[%d]"), count * 10);
				outtextxy(280, 150, a);
				rectangle(150, 300, 200, 330);    //��һ�����α߿�
				rectangle(320, 300, 370, 330);    //��һ�����α߿�
				settextcolor(WHITE);
				settextstyle(17, 12, "����");
				outtextxy(152, 305, "����");
				outtextxy(322, 305, "�˳�");
				MOUSEMSG m;// ������Ϣ����
				while (1)
				{
					m = GetMouseMsg();// ��ȡһ�����򰴼���Ϣ
					if (m.uMsg == WM_LBUTTONDOWN)//�ж������λ��
					{
						if (m.x >= 150 && m.x <= 200 && m.y >= 300 && m.y <= 330)
						{
							closegraph();//�رմ���
							goto A;
						}
						else if (m.x >= 320 && m.x <= 370 && m.y >= 300 && m.y <= 330)
						{
							closegraph();//�رմ���
							
						}
					}
				}
				
			}
			else
			{
				
				Move_Snake();//�ƶ���
				Draw_Game(count);//����
				Sleep(100);
			}

		}


	}

	//������
	_getch();
	closegraph();
	return 0;
}