#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn = 100 + 5;
char s[maxn][maxn];
int idl[maxn][maxn], cnt, m, n;

//将连通的点标记连通标记
void dfs(int x, int y, int id) {
	if(x<0 || x>=m || y<0 || y>=n) return;
	if(idl[x][y] > 0 || s[x][y] == '*') return;
	idl[x][y] = id;
	for(int dx = -1; dx <= 1; dx++) 
		for(int dy = -1; dy <= 1; dy++)
			if(dx!=0 || dy!=0) dfs(x+dx, y+dy, id); 
} 
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(scanf("%d%d", &m, &n) == 2 && m && n) {
		for(int i = 0; i < m; i++) scanf("%s", s[i]);
		memset(idl, 0, sizeof(idl));
		cnt = 0;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++) 
				if(idl[i][j] == 0 && s[i][j] == '@') dfs(i, j, ++cnt);
		cout << cnt << endl;	
	}
	return 0;
} 
