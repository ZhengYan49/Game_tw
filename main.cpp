#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<iostream>
#include <Windows.h>
#include <conio.h>
#include<fstream>
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
string s;
void getInput() {
	ifstream in(s);//打开文件
				   //读数据。。
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			in >> map[i][j];
		}
	}
	in.close();//关闭文件
}
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
	s = "data2.txt";
	getInput();
}

void rule_Glider()
{
	s = "data3.txt";
	getInput();
}

void rule_SmallExploder()
{
	s = "data4.txt";
	getInput();
}

void rule_Exploder() {
	s = "data5.txt";
	getInput();
}

void rule_LightWeightSpaceShip() {
	s = "data6.txt";
	getInput();
}

void rule_Tumbler() {
	s = "data7.txt";
	getInput();
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
void FullScreen()
{

	HWND hwnd = GetForegroundWindow();
	int x = GetSystemMetrics(SM_CXSCREEN) + 300;
	int y = GetSystemMetrics(SM_CYSCREEN) + 300;
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 700, 900, NULL);
	MoveWindow(hwnd, 320, 0, 675, 720, 1);
	ShowWindow(hwnd, SW_SHOW);
}
int main()
{
	system("color f0");
	FullScreen();
	int time = 1000;
	char ch;
	while (1)
	{
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
		cin >> number1;
		system("cls");
		switch (number1)
		{
		case 1:
			cout << "                      初始图案                               \n";
			RandomPattern();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " “0”极快 “1”快 “2”普通  “3”慢 “4”极慢   “ESC”结束 \n";
				if (_kbhit()) {
					ch = _getch();
					if (ch == '0') time = 0;
					else if (ch == '1') time = 500;
					else if (ch == '2') time = 1000;
					else if (ch == '3') time = 1000;
					else if (ch == '4') time = 1000;
					else break;
				}
				if (time < 0)
					time = 0;
				else if (time > 5000)
					time = 5000;
				Sleep(time);
			}
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "                      初始图案                               \n";
			rule_10CellRow();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " “0”极快 “1”快 “2”普通  “3”慢 “4”极慢   “ESC”结束 \n";
				if (_kbhit()) {
					ch = _getch();
					if (ch == '0') time = 0;
					else if (ch == '1') time = 500;
					else if (ch == '2') time = 1000;
					else if (ch == '3') time = 1000;
					else if (ch == '4') time = 1000;
					else break;
				}
				if (time < 0)
					time = 0;
				else if (time > 5000)
					time = 5000;
				Sleep(time);
			}
			system("pause"); system("cls");
			break;
		case 3:
			cout << "                      初始图案                               \n";
			rule_Glider();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " “0”极快 “1”快 “2”普通  “3”慢 “4”极慢   “ESC”结束 \n";
				if (_kbhit()) {
					ch = _getch();
					if (ch == '0') time = 0;
					else if (ch == '1') time = 500;
					else if (ch == '2') time = 1000;
					else if (ch == '3') time = 1000;
					else if (ch == '4') time = 1000;
					else break;
				}
				if (time < 0)
					time = 0;
				else if (time > 5000)
					time = 5000;
				Sleep(time);
			}
			system("pause"); system("cls");
			break;
		case 4:
			cout << "                      初始图案                               \n";
			rule_SmallExploder();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " “0”极快 “1”快 “2”普通  “3”慢 “4”极慢   “ESC”结束 \n";
				if (_kbhit()) {
					ch = _getch();
					if (ch == '0') time = 0;
					else if (ch == '1') time = 500;
					else if (ch == '2') time = 1000;
					else if (ch == '3') time = 1000;
					else if (ch == '4') time = 1000;
					else break;
				}
				if (time < 0)
					time = 0;
				else if (time > 5000)
					time = 5000;
				Sleep(time);
			}
			system("pause"); system("cls");
			break;
		case 5:
			cout << "                      初始图案                               \n";
			rule_Exploder();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " “0”极快 “1”快 “2”普通  “3”慢 “4”极慢   “ESC”结束 \n";
				if (_kbhit()) {
					ch = _getch();
					if (ch == '0') time = 0;
					else if (ch == '1') time = 500;
					else if (ch == '2') time = 1000;
					else if (ch == '3') time = 1000;
					else if (ch == '4') time = 1000;
					else break;
				}
				if (time < 0)
					time = 0;
				else if (time > 5000)
					time = 5000;
				Sleep(time);
			}
			system("pause"); system("cls");
			break;
		case 6:
			cout << "                      初始图案                               \n";
			rule_LightWeightSpaceShip();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " “0”极快 “1”快 “2”普通  “3”慢 “4”极慢   “ESC”结束 \n";
				if (_kbhit()) {
					ch = _getch();
					if (ch == '0') time = 0;
					else if (ch == '1') time = 500;
					else if (ch == '2') time = 1000;
					else if (ch == '3') time = 1000;
					else if (ch == '4') time = 1000;
					else break;
				}
				if (time < 0)
					time = 0;
				else if (time > 5000)
					time = 5000;
				Sleep(time);
			}
			system("pause"); system("cls");
			break;
		case 7:
			cout << "                      初始图案                               \n";
			rule_Tumbler();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " “0”极快 “1”快 “2”普通  “3”慢 “4”极慢   “ESC”结束 \n";
				if (_kbhit()) {
					ch = _getch();
					if (ch == '0') time = 0;
					else if (ch == '1') time = 500;
					else if (ch == '2') time = 1000;
					else if (ch == '3') time = 1000;
					else if (ch == '4') time = 1000;
					else break;
				}
				if (time < 0)
					time = 0;
				else if (time > 5000)
					time = 5000;
				Sleep(time);
			}
			system("pause"); system("cls");
			break;
		default:
			exit(0);
			break;
		}
	}
}