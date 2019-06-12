
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
//将map拷贝到tmp_map
void copy_map(int map[][maxl], int tmp_map[][maxl])
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tmp_map[i][j] = map[i][j];
}
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
			default: map[i][j] = DATH; break;
			}
		}

	general++;
	print_general();
}
