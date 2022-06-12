#include "head.h"
int count = 0;
int main()
{
	Kaishi();
	A:initgraph(840, 480);//初始化窗口大小，现在为640*480分辨率
	setbkcolor(WHITE);//设置背景色
	cleardevice();//使用背景色清屏

	Init_Game();//初始化
	srand((unsigned int)time(NULL));
	int n = 0;
	while (1)
	{

		if (_kbhit())//如果键盘被敲击就进入控制方向函数
	
			Change_Move();//控制蛇
		
		else
		{
			Produce_Food();//创建食物
			count=Eat_Food(count);//判断食物是否被吃
			n = GameOver();//判断蛇头是否撞墙或自己
			if (n == 1)//返回1则撞墙或自己
			{
				
				closegraph();//关闭窗口
				TCHAR a[100];
				initgraph(520, 360, NULL);
				IMAGE bgp;
				loadimage(&bgp, "./am.jpg", 520, 360, false);//加载图片
				putimage(0, 0, &bgp);
				setbkmode(TRANSPARENT);   				     //字符透明
				settextcolor(BLUE);
				settextstyle(40, 30, "宋体");
				outtextxy(140, 50, "游戏结束");
				outtextxy(100, 150, "分数：");
				_stprintf_s(a, _T("[%d]"), count * 10);
				outtextxy(280, 150, a);
				rectangle(150, 300, 200, 330);    //画一个矩形边框
				rectangle(320, 300, 370, 330);    //画一个矩形边框
				settextcolor(WHITE);
				settextstyle(17, 12, "宋体");
				outtextxy(152, 305, "继续");
				outtextxy(322, 305, "退出");
				MOUSEMSG m;// 定义消息变量
				while (1)
				{
					m = GetMouseMsg();// 获取一条鼠标或按键消息
					if (m.uMsg == WM_LBUTTONDOWN)//判断鼠标点击位置
					{
						if (m.x >= 150 && m.x <= 200 && m.y >= 300 && m.y <= 330)
						{
							closegraph();//关闭窗口
							goto A;
						}
						else if (m.x >= 320 && m.x <= 370 && m.y >= 300 && m.y <= 330)
						{
							closegraph();//关闭窗口
							
						}
					}
				}
				
			}
			else
			{
				
				Move_Snake();//移动蛇
				Draw_Game(count);//绘制
				Sleep(100);
			}

		}


	}

	//防闪退
	_getch();
	closegraph();
	return 0;
}