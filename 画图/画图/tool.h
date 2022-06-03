#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <graphics.h>			// 引用图形库头文件
#include <conio.h>
#include <iostream>
#include<math.h>
using namespace std;
//tool.cpp
void Caidanlan();//菜单栏
int Izhi(int i);//i值
void Huabi(int i);//画笔
void ZhixianYuan(int i,int j);//直线和圆
void Quxian(int i);//曲线
void Tianchong();//填充

//algorithm.cpp
void Yuan(float x1, float y1, float x2, float y2);//圆
void BezierQuxian(int x1,int y1, int x2,int y2,int x3,int y3);//曲线
void FloodFILL(int x, int y, int black, int newcolor);//填充