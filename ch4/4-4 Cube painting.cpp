//先通过旋转将每个面的骰子都放在顶端一次，选好顶端后底端也确定了，通过旋转4次判断是否有和另外一个骰子出现相同的情况
#include<iostream>
#include<cstring>
using namespace std;

//初始骰子是0~5(因为是以0~5的位置存的，所以表示为初始位置)，则通过旋转换顶端（也可以是其他，只要保证是旋转而来的就行，因为确定了顶端还是要进行4次旋转）有以下情况
int dir[6][6] = { {0,1,2,3,4,5}, {1,5,2,3,0,4}, {2,1,5,0,4,3}, {3,1,0,5,4,2}, {4,0,2,3,5,1}, {5,4,2,3,1,0} }; 	//二维数组赋值 
char s[20], s1[10], s2[10];	//s1存骰子1，s2存骰子2
char tmp[10];				//tmp用来存变换的结果 

//判断是否存在相同情况 
int is_some();
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
		
	while(cin >> s) {
		//cout << s << endl;
		//读2个骰子信息，再将信息分开存 
		for(int i = 0; i < 6; i++) s1[i] = s[i];
		for(int i = 6; i < 12; i++) s2[i - 6] = s[i];
		//cout << s1 << " " << s2 << endl; 
		
		if(is_some()) cout << "TRUE" << endl;
		else cout << "FALSE" << endl;	
	}
	return 0;
} 
int is_some() {
	//对6种顶端情况进行分析 
	for(int i = 0; i < 6; i++) { 
		//dir[i]表示6种顶端情况 
		for(int j = 0; j < 6; j++) 
			tmp[j] = s2[dir[i][j]];
		//顶端和底端不变，旋转4次 
		for(int j = 0; j < 4; j++) {
			char tmp_c;
			tmp_c = tmp[1];		//记录好第二个位置的数据
			//开始旋转
			tmp[1] = tmp[2];
			tmp[2] = tmp[4];
			tmp[4] = tmp[3];
			tmp[3] = tmp_c;
			//旋转后判断是否与s1相等 
			if(strcmp(tmp, s1) == 0) return 1;
		} 	
	}
	return 0;
	
}
