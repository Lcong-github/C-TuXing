#include "head.h"
int main()
{
	int map[SIZE][SIZE] = { 0 };//�����ά����
	int len = 0;//���峤��
	int state = 0;//������Ϸ״̬
	int direc = 0;//���巽��
	Init_map(map, &len, &direc);//��ʼ����ͼ
	while (1)
	{
		direc = get_direc(direc);//���̶��뷽��
		state = move(map, direc, &len);//�ߵ��ƶ����ں����ڲ��ж���ͷ״̬������ֵ
		if (state == 0)//����0����Ϸ����
			break;
		else//������Ϸ
			print(map);//��ӡ
		Sleep(100);
	}
	return 0;
}