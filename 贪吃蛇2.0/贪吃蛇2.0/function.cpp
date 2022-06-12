#include "head.h"

Snake snake;//�����ߵĽṹ�����
Food food;//����ʳ��Ľṹ�����
void Kaishi()
{
	initgraph(520, 360, NULL);
	IMAGE bgp;
	loadimage(&bgp, "./an.jpg", 520, 360, false);//����ͼƬ
	putimage(0, 0, &bgp);
	setbkmode(TRANSPARENT);   				     //�ַ�͸��
	settextcolor(RGB(97, 274, 255));
	settextstyle(40, 30, "����");
	outtextxy(20, 130, "��ӭʹ��");
	Sleep(3000);
	closegraph;
}


void Init_Game()
{
	snake.len = 3;//��ʼ������

	snake.direc = RIGHT;//��ʼ������

	//��ʼ����ͷ����
	snake.cr[0].x = 100;
	snake.cr[0].y = 100;

	//��������
	snake.cr[1].x = 90;
	snake.cr[1].y = 100;
	snake.cr[2].x = 80;
	snake.cr[2].y = 100;

	food.eat = 1;//��ʼ��ʳ���Ǳ��Ե�

}

void Draw_Game(int count)
{
	TCHAR a[100];//��ŷ���
	for (int i = 0; i < snake.len; i++)
	{
		if (i == 0)//�������ͷ
		{
			setfillcolor(RED);//�����ɫΪ��ɫ
			//����ʵ�ľ��Σ������ɫΪ��ɫ
			fillrectangle(snake.cr[i].x, snake.cr[i].y, snake.cr[i].x + SIZE, snake.cr[i].y + SIZE);//�����SIZE����ͷ�ļ�head.h�к궨��Ϊ10��
			//�ĸ�����Ϊ��    x����           y����           ��                       ��
		}
		else
			rectangle(snake.cr[i].x, snake.cr[i].y, snake.cr[i].x + SIZE, snake.cr[i].y + SIZE);//���Ʒ�ʵ�ľ���
	}
	//��ʾ����
	setcolor(BLACK);
	line(640, 0, 640, 450);
	line(640, 0, 820, 0);
	line(820, 0, 820, 450);
	line(640, 450, 820, 450);
	settextstyle(20, 15, "����");
	outtextxy(690, 100, "�Ѷȵ�");
	settextstyle(17, 14, "����");
	outtextxy(650, 300, "������");
	_stprintf_s(a, _T("[%d]"), count * 10);//��ʳ�ﱻ�ԵĴ���д�ַ���a��
	outtextxy(720, 300, a);

	//����ʳ��
	setfillcolor(GREEN);//�����ɫΪ��ɫ
	fillroundrect(food.x, food.y, food.x + SIZE, food.y + SIZE, 5, 5);//Բ�Ǿ���
	//6������Ϊ��  x����   y����      ��              ��       ��������Բ�ǵĳ̶�
}

void Move_Snake()
{
	cleardevice();//�Ե�ǰ����ɫ����
	for (int i = snake.len - 1; i > 0; i--)
	{
		snake.cr[i].x = snake.cr[i - 1].x;
		snake.cr[i].y = snake.cr[i - 1].y;
	}//�����±��Ǵ� 0~n-1 �ģ����Դ�i=snake.len-1��ʼ��ΪʲôiҪ>0������>=0
	//����Ϊ��ѭ�����������У���i-1�Ĳ��������һ���ǰ�snake.cr[0]�������snake.cr[1]�����д>=0���ͻ������ snake.cr[-1]�������snake.cr[0]

	//��ͷ������û���ˣ�����Ҫ�����µ���ͷ����
	switch (snake.direc)
	{
	case UP:
		snake.cr[0].y -= SIZE;
		break;
	case DOWN:
		snake.cr[0].y += SIZE;
		break;
	case LEFT:
		snake.cr[0].x -= SIZE;
		break;
	case RIGHT:
		snake.cr[0].x += SIZE;
		break;
	}
}

void Change_Move()
{
	int key = 0;
	key = _getch();//���ռ���ֵ
	switch (key)
	{
	case UP:
		if (snake.direc != DOWN)//������������£��Ͳ��ܸı䷽��
			snake.direc = UP;
		break;
	case DOWN:
		if (snake.direc != UP)//������������ϣ��Ͳ��ܸı䷽��
			snake.direc = DOWN;
		break;
	case LEFT:
		if (snake.direc != RIGHT)//������������ң��Ͳ��ܸı䷽��
			snake.direc = LEFT;
		break;
	case RIGHT:
		if (snake.direc != LEFT)//������������󣬾Ͳ��ܸı����
			snake.direc = RIGHT;
		break;
	}
}

void Produce_Food()
{
	int func = 0;//�����ж�ʳ��������Ƿ����ߵ������غ�
	if (food.eat == 1)
	{
		while (1)
		{
			food.x = rand() % 64 * 10;//rand()%64��������0~63����*10��ʵ��������10Ϊ�����������   0  10  20...
			food.y = rand() % 48 * 10;//rand()%48��������0~46����*10��ʵ��������10Ϊ�����������   0  10  20...
			for (int i = 0; i < snake.len; i++)
			{
				if (food.x == snake.cr[i].x && food.y == snake.cr[i].y)
				{
					func = 1;//��������������غ�,func�ı�Ϊ1�����غ�
					break;//�˳�forѭ��
				}
			}
			if (func == 0)//���û���غ�
			{
				food.eat = 0;//ʳ���Ҫ��Ϊδ���Ե�״̬
				break;
			}
		}
	}
}

int Eat_Food(int count)
{
	if (snake.cr[0].x == food.x && snake.cr[0].y == food.y)//�����ͷ��λ����ʳ��
	{
		food.eat = 1;//ʳ���״̬����Ϊ����
		snake.len += 1;//������+1
		count++;//ͳ�Ʊ��Դ���
		return count;
	}
	return count;
}

int GameOver()
{
	if (snake.cr[0].x < 0 || snake.cr[0].y < 0 || snake.cr[0].x>640 || snake.cr[0].y>480)//���ײǽ
	{
		return 1;//����1
	}
	for (int i = 1; i < snake.len; i++)
	{
		if (snake.cr[0].x == snake.cr[i].x && snake.cr[0].y == snake.cr[i].y)//���ײ�Լ�
			return 1;//����1
	}
	return 0;//���򷵻�0
}