//此题可以描述成描点，在32*32(1024个点)的正方形上记录黑素点的个数 
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int len = 32; 
int buf[len][len], cnt;

void draw(int x, int y, int w) {
	char c = getchar();
	while(c == '\n') c = getchar();
	if(c == 'p') {
		draw(x, y+w/2, w/2);
		draw(x, y, w/2);
		draw(x+w/2, y, w/2);
		draw(x+w/2, y+w/2, w/2);
	}else if(c == 'f') {
		for(int i = x; i < x+w; i++)
			for(int j = y; j < y+w; j++) 
				if(buf[i][j] == 0) { buf[i][j] = 1; cnt++; }
	}	
	return;	
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		memset(buf, 0, sizeof(buf));
		cnt = 0;
		draw(0, 0, len);
		draw(0, 0, len);
		printf("There are %d black pixels.\n", cnt);
	} 
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 
