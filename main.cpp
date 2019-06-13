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
	ifstream in(s);//���ļ�
				   //�����ݡ���
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			in >> map[i][j];
		}
	}
	in.close();//�ر��ļ�
}
//��ʼ����������������޷�������������˷ѣ�
void RandomPattern()
{
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = rand() % 2;


}
//����ͼ��
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

//����(x,y)��Χ���ϸ���ĸ���
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

//��ӡ��i���Ľ��
void print_general()
{
	//cout <<"��"<<general<<"����" <<endl ;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			if (map[i][j])  cout << "��";
			else cout << "��";
			cout << "\n";
	}
}

//��map���Ƶ�tmp_map
void copy_map(int map[][maxl], int tmp_map[][maxl])
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tmp_map[i][j] = map[i][j];
}

//�õ���һ��
void iteration()
{
	//system("cls");
	//SetConsoleCursorPosition(hOutput, coord);
	int tmp_map[maxr][maxl];
	copy_map(map, tmp_map);        //����֮ǰͼ��ʹ�õ�ǰԪ��״̬�ĸı仹�ǻ���֮ǰ�ĵ�ͼ�������Ǳ��޸��˵�
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
		cout << "��ѡ����Ҫ�����ĳ�ʼͼ��                                         \n";
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
			cout << "                      ��ʼͼ��                               \n";
			RandomPattern();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " ��0������ ��1���� ��2����ͨ  ��3���� ��4������   ��ESC������ \n";
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
			cout << "                      ��ʼͼ��                               \n";
			rule_10CellRow();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " ��0������ ��1���� ��2����ͨ  ��3���� ��4������   ��ESC������ \n";
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
			cout << "                      ��ʼͼ��                               \n";
			rule_Glider();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " ��0������ ��1���� ��2����ͨ  ��3���� ��4������   ��ESC������ \n";
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
			cout << "                      ��ʼͼ��                               \n";
			rule_SmallExploder();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " ��0������ ��1���� ��2����ͨ  ��3���� ��4������   ��ESC������ \n";
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
			cout << "                      ��ʼͼ��                               \n";
			rule_Exploder();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " ��0������ ��1���� ��2����ͨ  ��3���� ��4������   ��ESC������ \n";
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
			cout << "                      ��ʼͼ��                               \n";
			rule_LightWeightSpaceShip();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " ��0������ ��1���� ��2����ͨ  ��3���� ��4������   ��ESC������ \n";
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
			cout << "                      ��ʼͼ��                               \n";
			rule_Tumbler();
			print_general();
			system("pause");
			system("cls");
			while (1)
			{
				SetConsoleCursorPosition(hOutput, coord);
				iteration();
				cout << " ��0������ ��1���� ��2����ͨ  ��3���� ��4������   ��ESC������ \n";
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