#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <graphics.h>			// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <iostream>
#include<math.h>
using namespace std;
//tool.cpp
void Caidanlan();//�˵���
int Izhi(int i);//iֵ
void Huabi(int i);//����
void ZhixianYuan(int i,int j);//ֱ�ߺ�Բ
void Quxian(int i);//����
void Tianchong();//���

//algorithm.cpp
void Yuan(float x1, float y1, float x2, float y2);//Բ
void BezierQuxian(int x1,int y1, int x2,int y2,int x3,int y3);//����
void FloodFILL(int x, int y, int black, int newcolor);//���