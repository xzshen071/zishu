#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<ctype.h>
#define maxn 5
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//谜题  
	int t = 0;
	char a[maxn][maxn];//字符型也可以是二维的
	//读入 
    while(1){
        //读入
        if(t) getchar();
        fgets(a[0],10,stdin);//可以这么读，最多读10个，但是以\n结尾（若每行均以\n结束）
		//cout << a[0] << endl;
		 
        int ok=1;
        if(a[0][0] == 'Z') break;//判断的是第一个字母
        if(t) cout << endl;
        int m = 0, n = 0;
        for(int i = 0; i <= 4; ++i) {
            if(i) {//不是第一行
                fgets(a[i],10,stdin);
                //cout << a[i] << endl;
            }
            for(int j = 0; j <= 4; ++j) {
                if(a[i][j]  == ' ' || a[i][j] == 0) {//注意 前四个位置是否有空，或第五个位置（字符串尾）为空不显示！且若||前面的成立不读后面的！
                    a[i][j] = ' ';
                    m = i; n = j;//将空的位置记下来
                }
            }
        }
        //cout << m << " " << n << endl;
        //移动 
        char c;
    	while(c = getchar()) {
    		//cout << c << endl;
    		if((isalpha(c) || isdigit(c)) && c != '0'){
    			switch(c){
    				case 'A':
    					if(m-1<0){
    						ok=0;
    						//cout << c << " " << "1" << endl;
						}else{
							a[m][n]=a[m-1][n];
							m--;
						}
						break;
					case 'B':
						if(m+1>=maxn){
    						ok=0;
    						//cout << c << " " << "2" << endl;
						}else{
							a[m][n]=a[m+1][n];	
							m++;
						}

						break;
					case 'R':
    					if(n+1>=maxn){
    						ok=0;
    						//cout << c << " " << "3" << endl;
						}else{
							a[m][n]=a[m][n+1]; 
							n++;
						}
    					break;
    				case 'L':
    					if(n-1<0){
    						ok=0;
    						//cout << c << " " << "4" << endl;
						}else{
							a[m][n]=a[m][n-1];
							n--;	
						}
    					break;
    				default:
    					//cout << c << " " << "5" << endl;
						ok=0;
						break; 
				}
    			a[m][n]=' ';
    			
			}else if(c == '0') {
				//cout << "0" << endl;
				break; 
			}
    			
		}
		
		//输出 
		printf("Puzzle #%d:\n",++t);
		if(ok){
			for(int i=0;i<5;i++){
				for(int j=0;j<5;j++){
					if(j)
						printf(" ");
					printf("%c",a[i][j]);
				}
				printf("\n");
			}
		}else
			printf("This puzzle has no final configuration.\n");
		
	}   	
	
	return 0;
}
