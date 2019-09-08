#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int maxm = 100 + 5;
const int maxn = 100 + 5;
char oil[maxm][maxn];
int v[maxm][maxn];
int m, n;

void DFS(int x, int y) {
	if(x < 0 || x >= m || y < 0 || y >= n) return;	//越界 
	if(v[x][y] == 1 || oil[x][y] == '*') return;
	v[x][y] = 1;
	for(int dx = -1; dx <= 1; dx++)
		for(int dy = -1; dy <= 1; dy++)
			if(dx != 0 || dy != 0) DFS(x+dx, y+dy);  
	//cout << x << " " << y << endl;
	
	return;
}
int main() {
	//freopen("input.txt", "r", stdin);
	while(cin >> m >> n) {
		int count = 0;								//存结果 
		memset(v, 0, sizeof(v));
		if(m == 0) break;
		//输入 
		for(int i = 0; i < m; i++) {
			scanf("%s", oil[i]);
		}  
		/*
		for(int i = 0; i < m; i++) 
			cout << oil[i] << endl;
		*/
		//处理 
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(v[i][j] == 1 || oil[i][j] == '*') continue;
				count++;
				//cout << "start:" << i << " " << j << endl; 
				DFS(i, j);
			}
		}
		cout << count << endl;	
	}

	return 0;
}
 
