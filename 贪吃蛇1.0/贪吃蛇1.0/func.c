#include"head.h"
void Init_map(int map[SIZE][SIZE], int* len, int* direc)
{
	*len = 3;//��ʼ������
	*direc = 2;//��ʼ������

	map[5][5] = -1;//��ʼ��ʳ��

	//��ʼ������
	map[3][3] = 3;
	map[4][3] = 2;

	map[5][3] = 1;//��ʼ����ͷ
}

int get_direc(int direc)
{
	int tmp = -1;//����һ���������ռ���ֵ�ı���

	if (_kbhit())//������̱��û���kbhit()����һ����0ֵ
	{
		switch (_getch())//�Ӽ��̶���
		{
		case 'W':case 'w':tmp = 0; break;
		case 'D':case 'd':tmp = 1; break;
		case 'S':case 's':tmp = 2; break;
		case 'A':case 'a':tmp = 3; break;
		}
		//����ļ���ֻ���� w��d��s��a�������߲��ܵ�ͷ
		if (tmp != -1 && abs(direc - tmp) != 2)//abs�����������ֵ
			direc = tmp;
	}
	return direc;
}

int move(int map[SIZE][SIZE], int direc, int* len)
{
	int i = 0;
	int j = 0;

	//������ͷλ��
	int head_x = 0;
	int head_y = 0;

	//ѭ����������
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (map[i][j] == *len)//�������β
				map[i][j] = 0;

			if (map[i][j] > 1)//���������
				map[i][j] += 1;

			if (map[i][j] == 1)//�������ͷ
			{
				map[i][j] += 1;

				//��ʱ��ͷ+1�ˣ��Ѿ�û����ͷ�ˣ����ھ�Ҫ�ҵ�һ���µ���ͷ
				// 
				//�ҵ�ԭ��ͷ��ԭλ��
				head_x = i;
				head_y = j;

				//�ҵ���ͷ�ƶ����λ��
				switch (direc)
				{
				case 0:head_x = i - 1; head_y = j; break;
				case 1:head_x = i; head_y = j + 1; break;
				case 2:head_x = i + 1; head_y = j; break;
				case 3:head_x = i; head_y = j - 1; break;
				}
			}
		}
	}

	if (map[head_x][head_y] == -1)//�����ͷλ����ʳ��
	{
		*len = *len + 1;//�Ե�ʳ�����+1
		map[head_x][head_y] = 1;//�Ե�ʳ�ʳ������ͷ

		//��������ʳ��
		while (1)
		{
			i = rand() % SIZE;
			j = rand() % SIZE;
			if (map[i][j] == 0)
			{
				map[i][j] = -1;
				break;
			}
		}
	}
	//�����ͷ�����Լ���ǽ
	else if (map[head_x][head_y] > 0 || head_x < 0 || head_x == SIZE || head_y < 0 || head_y == SIZE)
		return 0;//����0
	else
		map[head_x][head_y] = 1;//û����ʳ�ǽ�ڡ��Լ�

	return 1;//û����ʳ�ǽ�ڡ��Լ�

}

void print(int map[SIZE][SIZE])
{
	//��ӡ�߿�ʳ����õķ��Ÿ����Լ���ϲ�����������ɲ������Ƶ�
	system("cls");
	int i = 0;
	int j = 0;

	//��ӡ�ϱ߿�
	for (i = 0; i <= SIZE; i++)
	{
		if (i == 0)
			printf("��");
		else if (i == SIZE)
			printf(" ��");
		else
			printf(" ��");

	}
	printf("\n");

	//��ӡ���ұ߿򣬴�ӡ��ͷ������ʳ��
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (j == 0)
				printf("�� ");
			else if (map[i][j] == -1)
				printf("��");
			else if (map[i][j] > 0)
				printf("��");
			else if (map[i][j] == 1)
				printf("��");
			else
				printf("  ");
			if (j == SIZE - 1)
				printf("��");
		}
		printf("\n");
	}

	//��ӡ�±߿�
	for (i = 0; i <= SIZE; i++)
	{
		if (i == 0)
			printf("��");
		else if (i == SIZE)
			printf(" ��");
		else
			printf(" ��");
	}
	printf("\n");
}