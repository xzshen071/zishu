#include<stdio.h>
#include<string.h> 
#include<iostream>
using namespace std;

#define maxn 10
char board[maxn][maxn];
char player;

char readchar();
int Print_operate(int f); 									//输入参数1是打印合法参数，输入参数0只是判断有没有合法操作 
int check_line(int x,int y,int dx,int dy,int symbol);
void change_board(int x,int y);
void Print_W_B();
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	
	//输入游戏次数
	int t,flag=1;
	scanf("%d",&t);
	while(t--){
		if(flag) flag=0;
		else printf("\n");
		
		//存棋盘，是从(0,0)开始存的 
		for(int i=0;i<8;i++){
			scanf("%s",board[i]);	
		}
		/* 
		for(int i=0;i<8;i++){
			printf("%s\n",board[i]);
			
		}
		*/ 
		player=readchar();
		//printf("%c\n",player);
		
		//命令
		char s[5];
		memset(s,0,sizeof(s));
		while(1){
			scanf("%s",s);
			//printf("%c\n",s[0]);
			if(s[0]=='Q'){				//命令结束，打印棋盘 
				for(int i=0;i<8;i++){ 
					printf("%s\n",board[i]); 
				}
				break;	
			}
			switch(s[0]){
				case 'L':				//打印所有合法的操作，若无则改变当前游戏者（改变当前游戏者不对） 
					/*
					for(int i=0;i<8;i++)
						printf("%s\n",board[i]);
					*/
					Print_operate(1);
					break;
				case 'M':				//放一枚能合法操作的棋子
					//放player的棋子 
					//printf("%d %d\n",s[1]-'0',s[2]-'0');
					//cout << Print_operate(0) << endl;
					if(Print_operate(0)==0){				//判断是否有合法操作，没有则改变当前游戏者 
						//cout << 1 << endl;
						if(player=='W') player='B';			//注意别把==写成=了 
						else player='W';
					}
					board[s[1]-'0'-1][s[2]-'0'-1]=player;	//放棋子 
					//棋局变化 
					change_board(s[1]-1-'0',s[2]-1-'0');	//应该是这个函数有问题 
					
					/*
					printf("%d %d\n",s[1]-'0'-1,s[2]-'0'-1);
					for(int i=0;i<8;i++)
						printf("%s\n",board[i]);
					*/	
					break;		
			}
		} 
	} 
	
	return 0;
} 
//读第一个不是空行的字符 
char readchar(){
	while(1){
		char ch=getchar();
		if(ch!='\r' && ch!='\n')
			return ch;
	}
}
//打印所有合法的操作，按照从上到下，从左到右的顺序（没有合法操作则输出No legal move） 
int Print_operate(int f){
	//ch代表敌方的棋子 
	char ch;
	if(player=='W')
		ch='B';
	else
		ch='W';
	//printf("%c\n",ch);
	int flag=0;
	//从上到下，从左到右的顺序 
	for(int i=0;i<8;i++){			//行 
		for(int j=0;j<8;j++){		//列 
			if(board[i][j]=='-'){	//可以放置的位置是'-'，可能存在重复打印的情况（只打印一次）
				if(board[i+1][j+1]==ch && check_line(i,j,1,1,0)){			//在敌方棋子的左上角且右下斜线上有我方棋子
					if(f){		//f = 1才打印 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//都加1是因为棋盘是从(0,0)开始存的 
					}
					flag++;
				}else if(board[i+1][j]==ch && check_line(i,j,1,0,0)){		//在敌方棋子的正上方且下直线上有我方棋子
					if(f){		//f = 1才打印 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//都加1是因为棋盘是从(0,0)开始存的 
					}
					flag++;
				}else if(board[i+1][j-1]==ch && check_line(i,j,1,-1,0)){	//在敌方棋子的右上方且左下斜线有我方棋子 
					if(f){		//f = 1才打印 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//都加1是因为棋盘是从(0,0)开始存的 
					}
					flag++;
				}else if(board[i][j+1]==ch && check_line(i,j,0,1,0)){		//在敌方棋子的左方且右直线上有我方棋子
					if(f){		//f = 1才打印 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//都加1是因为棋盘是从(0,0)开始存的 
					}
					flag++;
				}else if(board[i][j-1]==ch && check_line(i,j,0,-1,0)){		//在敌方棋子的右方且左直线上有我方棋子 
					if(f){		//f = 1才打印 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//都加1是因为棋盘是从(0,0)开始存的 
					}
					flag++;
				}else if(board[i-1][j+1]==ch && check_line(i,j,-1,1,0)){	//在敌方棋子的左下方且右上斜线有我方棋子
					if(f){		//f = 1才打印 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//都加1是因为棋盘是从(0,0)开始存的 
					}
					flag++;
				}else if(board[i-1][j]==ch && check_line(i,j,-1,0,0)){		//在敌方棋子的下方且上直线上有我方棋子
					if(f){		//f = 1才打印 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//都加1是因为棋盘是从(0,0)开始存的 
					}
					flag++;
				}else if(board[i-1][j-1]==ch && check_line(i,j,-1,-1,0)){		//在敌方棋子的右下方且左上斜线有我方棋子 
					if(f){		//f = 1才打印 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//都加1是因为棋盘是从(0,0)开始存的 
					}
					flag++;	
				}
			}	
		}
	}
	if(flag){
		if(f) printf("\n"); 
	}
	else{											//如果flag = 0，则说明没有合法操作 
		if(f) printf("No legal move.\n");
		//player=ch;								//好像并没有说要变换游戏者 
	}
	return flag; 
}
//dx为x的每次移动的步长，dy为y每次移动的步长，同时移动，注意路径中不能有'-'，有的话不算合法位置 
int check_line(int x,int y,int dx,int dy,int symbol){
	//symbol=0是查找，symbol=1是如果存在的话，变棋子 
	int xm=x+dx;					
	int ym=y+dy;
	int flag=0;
	while(xm>=0 && xm<8 && ym>=0 && ym<8){
		xm+=dx;
		ym+=dy;
		if(board[xm][ym]=='-') break;			//中途有'-'字符，直接跳出循环不合法 
		if(board[xm][ym]==player){
			flag=1;
			break;
		}
	} 
	//循环跳出的x为player棋子的颜色 
	//把沿路的棋子变成player的棋子 
	if(symbol && flag){
		//printf("%d\n",flag);
		do{
			//cout << xm << " " << ym << endl;
			//cout << x+dx << endl;
			xm-=dx;
			ym-=dy;
			board[xm][ym]=player;
			//printf("%c\n",board[xm][ym]);
	
		}while(!(xm==(x+dx) && ym==(y+dy)));
			
	}
	return flag;//flag为1说明有，flag为0说明没有 
}
void change_board(int x,int y){
	char ch;
	if(player=='W')
		ch='B';
	else
		ch='W';
	//printf("%c\n",ch);
	/*
	for(int i=0;i<8;i++){
		printf("%s\n",board[i]);
			
	}
	*/
	//判断该棋子8个方向是否有敌方棋子
	//在敌方棋子的左上方
	int flag;		
	int i=x,j=y;
	//printf("%d %d\n",i,j);
	if(board[i+1][j+1]==ch){
		//检查右下斜线上是否有我方棋子，若有且改变棋子 
		check_line(i,j,1,1,1);
	}
	//在敌方棋子的正上方 
	if(board[i+1][j]==ch){
		//检查下直线上是否有我方棋子，若有且改变棋子
		//printf("66666\n");
		check_line(i,j,1,0,1);
	}
	//在敌方棋子的右上方
	if(board[i+1][j-1]==ch){
		//检查左下斜线是否有我方棋子，若有且改变棋子
		check_line(i,j,1,-1,1); 
	}
	//在敌方棋子的左方 
	if(board[i][j+1]==ch){
		//检查右直线上是否有我方棋子，若有且改变棋子
		check_line(i,j,0,1,1);
	}
	//在敌方棋子的右方 
	if(board[i][j-1]==ch){
		//printf("66666\n");
		//检查左直线上是否有我方棋子，若有且改变棋子
		check_line(i,j,0,-1,1);
	}
	//在敌方棋子的左下方 
	if(board[i-1][j+1]==ch){
		//检查右上斜线是否有我方棋子，若有且改变棋子
		check_line(i,j,-1,1,1);
	}
	//在敌方棋子的下方 
	if(board[i-1][j]==ch){
		//检查上直线上是否有我方棋子，若有且改变棋子
		check_line(i,j,-1,0,1);
	}
	//在敌方棋子的右下方 
	if(board[i-1][j-1]==ch){
		//检查上直线上是否有我方棋子，若有且改变棋子
		check_line(i,j,-1,-1,1);
	} 
	/*
	for(int i=0;i<8;i++){
		printf("%s\n",board[i]);
			
	}
	*/
	//打印黑白棋的个数
	Print_W_B();
	
	//改变当前游戏者 
	player=ch;
	
}
void Print_W_B(){
	int Num_W,Num_B;
	Num_W=Num_B=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(board[i][j]=='W'){
				Num_W++;
			}
			if(board[i][j]=='B'){
				Num_B++;
			}
		}
	}
	printf("Black - %2d White - %2d\n",Num_B,Num_W);
}
