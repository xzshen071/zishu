#include<stdio.h>
#include<math.h>
#include<string.h>
#define maxn 5

int main(){
	//谜题  
	int t = 0;
	char a[maxn][maxn];//字符型也可以是二维的
	//读入 
    while(1){
        //读入
        if(t){
    		printf("\n");
		}
        fgets(a[0],10,stdin);//可以这么读，最多读10个，但是以\n结尾（若每行均以\n结束） 
        int ok=1;
        if(a[0][0] == 'Z') break;//判断的是第一个字母
        int m = 0, n = 0;
        for(int i = 0; i <= 4; ++i) {
            if (i) {//不是第一行
                fgets(a[i],10,stdin);
            }
            for(int j = 0; j <= 4; ++j) {
                if(a[i][j]  == ' ' || a[i][j] == 0) {//注意 前四个位置是否有空，或第五个位置（字符串尾）为空不显示！且若||前面的成立不读后面的！
                    a[i][j] = ' ';
                    m = i; n = j;//将空的位置记下来
                }
            }
        }
        //移动 
        char c;
    	while((c=getchar())!='\n'){
    		if(c!='0'){
    			switch(c){
    				case 'A':
    					if(m-1<0){
    						ok=0;
						}else{
							a[m][n]=a[m-1][n];
							m--;
						}
						break;
					case 'B':
						if(m+1>maxn){
    						ok=0;
						}else{
							a[m][n]=a[m+1][n];	
							m++;
						}

						break;
					case 'R':
    					if(n+1>maxn){
    						ok=0;
						}else{
							a[m][n]=a[m][n+1]; 
							n++;
						}
    					break;
    				case 'L':
    					if(n-1<0){
    						ok=0;
						}else{
							a[m][n]=a[m][n-1];
							n--;	
						}
    					break;
    				default:
						ok=0;
						break; 
				}
    			a[m][n]=' ';
    			
			}//else
				//brek;//不要这两句，会导致getchar()没接收到'\n'而导致下一次输入发生错误，即接受了还没接收的'\n' 
    			
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
			printf("This puzzle has no final configuration\n");
	
	}   	
	
	
	
	
	
	
	
	return 0;
}
