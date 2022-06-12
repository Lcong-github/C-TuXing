#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <graphics.h>
#include <easyx.h>//EasyX图形库头文件
#include <stdio.h>
#include <windows.h>//Sleep头文件
#include <conio.h>//kbhit、getch头文件
//srand函数需要的头文件
#include <stdlib.h>
#include <time.h>

#define NUM 200//默认蛇有200个坐标

//宏定义各个方向。与1.0不同的是，本版本使用方向键控制的
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define SIZE 10
//坐标的结构体
struct Coor
{
	int x;
	int y;
};

//蛇的结构体
struct Snake
{
	//蛇结构包括
	int len;//长度
	int direc;//方向
	Coor cr[NUM];//坐标
	//一条蛇有N节，每节都有自己的坐标，所以定义一个坐标数组
};

//食物的结构体
struct Food
{
	//因为食物它永远只有一个，所以不需要数组
	int x;
	int y;
	int eat;//确定是否被吃
};
void Kaishi();
void Init_Game();//初始化函数声明
void Draw_Game(int count);//绘制蛇函数声明
void Move_Snake();//蛇移动函数声明
void Change_Move();//控制蛇函数声明
void Produce_Food();//创建食物的函数声明
int Eat_Food(int count);//食物是否被吃的函数声明
int GameOver();//判断是否撞墙或自己的函
