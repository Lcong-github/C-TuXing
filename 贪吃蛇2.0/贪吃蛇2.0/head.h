#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <graphics.h>
#include <easyx.h>//EasyXͼ�ο�ͷ�ļ�
#include <stdio.h>
#include <windows.h>//Sleepͷ�ļ�
#include <conio.h>//kbhit��getchͷ�ļ�
//srand������Ҫ��ͷ�ļ�
#include <stdlib.h>
#include <time.h>

#define NUM 200//Ĭ������200������

//�궨�����������1.0��ͬ���ǣ����汾ʹ�÷�������Ƶ�
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define SIZE 10
//����Ľṹ��
struct Coor
{
	int x;
	int y;
};

//�ߵĽṹ��
struct Snake
{
	//�߽ṹ����
	int len;//����
	int direc;//����
	Coor cr[NUM];//����
	//һ������N�ڣ�ÿ�ڶ����Լ������꣬���Զ���һ����������
};

//ʳ��Ľṹ��
struct Food
{
	//��Ϊʳ������Զֻ��һ�������Բ���Ҫ����
	int x;
	int y;
	int eat;//ȷ���Ƿ񱻳�
};
void Kaishi();
void Init_Game();//��ʼ����������
void Draw_Game(int count);//�����ߺ�������
void Move_Snake();//���ƶ���������
void Change_Move();//�����ߺ�������
void Produce_Food();//����ʳ��ĺ�������
int Eat_Food(int count);//ʳ���Ƿ񱻳Եĺ�������
int GameOver();//�ж��Ƿ�ײǽ���Լ��ĺ�
