#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<iostream>
using namespace std;

const int DEATH = 0;
const int ALIVE = 1;
const int maxr = 200, maxl = 200;
const int dx[] = { -1,-1,-1,0,1,1,1,0 }, dy[] = { -1,0,1,1,1,0,-1,-1 };

int map[maxr][maxl], newmap[maxr][maxl];
const int m = 50, n = 50; 
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
	for(int i = 5 ;i < 15 ;i++ )
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
	printf("第%d代：\n", general);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			if (map[i][j])  printf("■");
			else printf("□");
			printf("\n");
	}
	system("pause");
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
	rule_Tumbler();
	print_general();
	while (1)
		iteration();

	return 0;
}