
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
//��map������tmp_map
void copy_map(int map[][maxl], int tmp_map[][maxl])
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tmp_map[i][j] = map[i][j];
}
void iteration()
{
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
			default: map[i][j] = DATH; break;
			}
		}

	general++;
	print_general();
}
