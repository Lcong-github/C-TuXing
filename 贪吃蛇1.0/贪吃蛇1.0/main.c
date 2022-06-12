#include "head.h"
int main()
{
	int map[SIZE][SIZE] = { 0 };//定义二维数组
	int len = 0;//定义长度
	int state = 0;//定义游戏状态
	int direc = 0;//定义方向
	Init_map(map, &len, &direc);//初始化地图
	while (1)
	{
		direc = get_direc(direc);//键盘读入方向
		state = move(map, direc, &len);//蛇的移动，在函数内部判断蛇头状态并返回值
		if (state == 0)//返回0表游戏结束
			break;
		else//继续游戏
			print(map);//打印
		Sleep(100);
	}
	return 0;
}