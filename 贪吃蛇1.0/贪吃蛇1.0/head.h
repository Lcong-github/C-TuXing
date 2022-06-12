#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

#define SIZE 19

void Init_map(int map[SIZE][SIZE], int* len, int* direc);
int get_direc(int direc);
int move(int map[SIZE][SIZE], int direc, int* len);
void print(int map[SIZE][SIZE]);