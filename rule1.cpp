#ifndef _RULE1_H
#define _RULE1_H
int map[maxr][maxl], newmap[maxr][maxl];
int m, n, general = 0;

//��ʼ����������������޷�������������˷ѣ�
void rule1()
{
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = rand() % 2;        //����Լn/2
}
#endif

