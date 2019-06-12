#ifndef _RULE1_H
#define _RULE1_H
int map[maxr][maxl], newmap[maxr][maxl];
int m, n, general = 0;

//初始化，生成随机数（无法避免随机数的浪费）
void rule1()
{
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = rand() % 2;        //假设约n/2
}
#endif

