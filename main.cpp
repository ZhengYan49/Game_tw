#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

const int DEATH = 0;
const int ALIVE = 1;
const int maxr = 200, maxl = 200;
const int dx[] = { -1,-1,-1,0,1,1,1,0 }, dy[] = { -1,0,1,1,1,0,-1,-1 };

HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord = { 0,0 };

int map[maxr][maxl], newmap[maxr][maxl];
const int m = 40, n = 40;
int general = 0;
//初始化，生成随机数（无法避免随机数的浪费）
void RandomPattern()
{
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = rand() % 2;


}
//长条图案
void rule_10CellRow()
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = 0;        //假设约n/2
	for (int i = 5; i < 15; i++)
		map[5][i] = 1;
}

void rule_Glider()
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = 0;        //假设约n/2
	map[0][2] = 1;
	map[1][0] = 1;
	map[1][2] = 1;
	map[2][1] = map[2][2] = 1;
}

void rule_SmallExploder()
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = 0;        //假设约n/2
	map[24][25] = 1;
	map[25][24] = map[25][25] = map[25][26] = 1;
	map[26][24] = map[26][26] = 1;
	map[27][25] = 1;
}

void rule_Exploder() {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = 0;        //假设约n/2
	map[23][23] = map[23][25] = map[23][27] = 1;
	map[24][23] = map[24][27] = 1;
	map[25][23] = map[25][27] = 1;
	map[26][23] = map[26][27] = 1;
	map[27][23] = map[27][25] = map[27][27] = 1;
}

void rule_LightWeightSpaceShip() {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = 0;        //假设约n/2
	map[20][21] = map[20][22] = map[20][23] = map[20][24] = 1;
	map[21][20] = map[21][24] = 1;
	map[22][24] = 1;
	map[23][20] = map[23][23] = 1;
}

void rule_Tumbler() {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = 0;
	map[20][21] = map[20][22] = map[20][24] = map[20][25] = 1;
	map[21][21] = map[21][22] = map[21][24] = map[21][25] = 1;
	map[22][22] = map[22][24] = 1;
	map[23][20] = map[23][22] = map[23][24] = map[23][26] = 1;
	map[24][20] = map[24][22] = map[24][24] = map[24][26] = 1;
	map[25][20] = map[25][21] = map[25][25] = map[25][26] = 1;
}

//计算(x,y)周围存活细胞的个数
int neighbor_num(int x, int y, int map[][maxl])
{
	int cnt = 0;
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[nx][ny])  cnt++;
	}
	return cnt;
}

//打印第i代的结果
void print_general()
{
	//cout <<"第"<<general<<"代：" <<endl ;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			if (map[i][j])  cout << "■";
			else cout << "□";
		cout << "\n";
	}
}

//将map复制到tmp_map
void copy_map(int map[][maxl], int tmp_map[][maxl])
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tmp_map[i][j] = map[i][j];
}

//得到下一代
void iteration()
{
	//system("cls");
	//SetConsoleCursorPosition(hOutput, coord);
	int tmp_map[maxr][maxl];
	copy_map(map, tmp_map);        //保存之前图像，使得当前元素状态的改变还是基于之前的地图，而不是被修改了的
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			int cnt = neighbor_num(i, j, tmp_map);
			switch (cnt)
			{
			case 2: continue;
			case 3: map[i][j] = ALIVE; break;
			default: map[i][j] = DEATH; break;
			}
		}

	general++;
	print_general();
}

int main()
{	
	 unsigned int time = 1000;
	char ch;
	//rule_Tumbler();
	//print_general();
	//while (1)
		//iteration();

	//return 0;
	int end = 1;
	int end1 = 1;
	while (end)
	{
		int number;
		int number1;
		cout << "请选择您要操作的初始图案                                         \n";
		cout << "                               1.RandomPattern                   \n";
		cout << "                               2.10CellRow                       \n";
		cout << "                               3.Glider                          \n";
		cout << "                               4.SmallExploder                   \n";
		cout << "                               5.Exploder                        \n";
		cout << "                               6.LightWeightSpaceShip            \n";
		cout << "                               7.Tumbler                         \n";
		cout << "                               8.exit                            \n";
		end1 = 1;
		cin >> number1;
		system("cls");
		switch (number1)
		{
		case 1:
			RandomPattern();
			print_general();
			//cout << "请选择您要迭代的次数：\n";
			//cin >> number;
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				if (time > 30000)
					time = 0;
				else if (time > 5000)
					time = 5000;
				Sleep(time);
				//ch = _getch();
				if (_kbhit()) {
					ch = _getch(); 
					if (ch == 's') time -= 500;
					else if(ch == 'w') time += 500;
					else break;
				}
				//else if ((ch == 115)) time -= 1000;
			}
			/*
			for (int i = 0; i < number; i++)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				Sleep(100);
			}*/
			system("pause"); 
			system("cls");
			break;
		case 2:
			rule_10CellRow();
			print_general();
			cout << "请选择您要迭代的次数：\n";
			cin >> number;
			system("cls");
			for (int i = 0; i < number; i++)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
			}
			system("pause"); system("cls");
			break;
		case 3:
			rule_Glider();
			print_general();
			cout << "请选择您要迭代的次数：\n";
			cin >> number;
			system("cls");
			for (int i = 0; i < number; i++)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
			}
			system("pause"); system("cls");
			break;
		case 4:
			rule_SmallExploder();
			print_general();
			cout << "请选择您要迭代的次数：\n";
			cin >> number;
			system("cls");
			for (int i = 0; i < number; i++)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
			}
			system("pause"); system("cls");
			break;
		case 5:
			rule_Exploder();
			print_general();
			cout << "请选择您要迭代的次数：\n";
			cin >> number;
			system("cls");
			for (int i = 0; i < number; i++)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
			}
			system("pause"); system("cls");
			break;
		case 6:
			rule_LightWeightSpaceShip();
			print_general();
			cout << "请选择您要迭代的次数：\n";
			cin >> number;
			system("cls");
			for (int i = 0; i < number; i++)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
			}
			system("pause"); system("cls");
			break;
		case 7:
			rule_Tumbler();
			print_general();
			cout << "请选择您要迭代的次数：\n";
			cin >> number;
			system("cls");
			for (int i = 0; i < number; i++)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
			}
			system("pause"); system("cls");
			break;
		default:
			exit(0);
			break;
		}
	}
}