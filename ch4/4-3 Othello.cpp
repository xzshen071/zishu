#include<stdio.h>
#include<string.h> 
#define maxn 10
char board[maxn][maxn];
char player;
char readchar();
void Print_operate(); 
int check_line(int x,int y,int dx,int dy,int symbol);
void change_board(int x,int y);
void Print_W_B();
int main(){
	//输入游戏次数
	int t;
	scanf("%d",&t);
	while(t--){
		//printf("%d\n",t);
		//存棋盘
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
			if(s[0]=='Q'){
				for(int i=0;i<8;i++){
					printf("%s\n",board[i]);

				}
				printf("\n");
				break;	
			}
			switch(s[0]){
				case 'L'://打印所有合法的操作，若无则改变当前游戏者 
					Print_operate();
					break;
				case 'M'://放一枚能合法操作的棋子
					//放player的棋子 
					//printf("%d %d\n",s[1]-'0',s[2]-'0');
					board[s[1]-'0'-1][s[2]-'0'-1]=player;
					//棋局变化 
					change_board(s[1]-1-'0',s[2]-1-'0');
					break;	
				
			}
			
			
		} 
		
	} 
	
	
	return 0;
} 
char readchar(){
	while(1){
		char ch=getchar();
		if(ch!='\r' && ch!='\n')
			return ch;
		
	}
}
void Print_operate(){
	char ch;
	if(player=='W')
		ch='B';
	else
		ch='W';
	//printf("%c\n",ch);
	int flag=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(board[i][j]=='-'){
				//在敌方棋子的左上角
				if(board[i+1][j+1]==ch){
					//检查右下斜线上是否有我方棋子
					if(check_line(i,j,1,1,0)){
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
 
				} 
				//在敌方棋子的正上方
				if(board[i+1][j]==ch){
					//检查下直线上是否有我方棋子
					if(check_line(i,j,1,0,0)){
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
					
				}
				//在敌方棋子的右上方
				if(board[i+1][j-1]==ch){
					//检查左下斜线是否有我方棋子
					if(check_line(i,j,1,-1,0)){
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
				
				}
				//在敌方棋子的左方 
				if(board[i][j+1]==ch){
					//检查右直线上是否有我方棋子
					if(check_line(i,j,0,1,0)){
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
					
				}
				//在敌方棋子的右方 
				if(board[i][j-1]==ch){
					//检查左直线上是否有我方棋子
					if(check_line(i,j,0,-1,0)){
						if(flag)
							printf(" ");						
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
					
				}
				//在敌方棋子的左下方 
				if(board[i-1][j+1]==ch){
					//检查右上斜线是否有我方棋子
					if(check_line(i,j,-1,1,0)){
						if(flag)
							printf(" ");						
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
					
				}
			 	//在敌方棋子的下方 
				if(board[i-1][j]==ch){
					//检查上直线上是否有我方棋子
					if(check_line(i,j,-1,0,0)){
						if(flag)
							printf(" ");						
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
					
				}
				//在敌方棋子的右下方 
				if(board[i-1][j-1]==ch){
					//检查上直线上是否有我方棋子
					if(check_line(i,j,-1,-1,0)){
						if(flag)
							printf(" ");						
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
					
				}
			 
		
			} 
			
		}
	}
	if(flag)
		printf("\n"); 
	else{
		printf("No legal move.\n");
		player=ch;	
	}
	
	
}
//dx为x的每次移动的步长，dy为y每次移动的步长，同时移动 
int check_line(int x,int y,int dx,int dy,int symbol){
	//symbol=0是查找，symbol=1是如果存在的话，变棋子 
	int xm=x+dx;
	int ym=y+dy;
	int flag=0;
	while(xm>=0 && xm<8 && ym>=0 && ym<8){
		if(board[xm][ym]==player){
			flag=1;
			break;
		}
		
		xm+=dx;
		ym+=dy;
	} 
	//把沿路的棋子变成player的棋子 
	if(symbol && flag){
		//printf("%d\n",flag);
		do{
			xm-=dx;
			ym-=dy;
			board[xm][ym]=player;
			//printf("%c\n",board[xm][ym]);
	
		}while(xm!=x+dx);
			
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
		flag=check_line(i,j,1,1,1);
		
	}
	//在敌方棋子的正上方 
	if(board[i+1][j]==ch){
		//检查下直线上是否有我方棋子，若有且改变棋子
		//printf("66666\n");
		flag=check_line(i,j,1,0,1);

	}
	//在敌方棋子的右上方
	if(board[i+1][j-1]==ch){
		//检查左下斜线是否有我方棋子，若有且改变棋子
		flag=check_line(i,j,1,-1,1); 

	}
	//在敌方棋子的左方 
	if(board[i][j+1]==ch){
		//检查右直线上是否有我方棋子，若有且改变棋子
		flag=check_line(i,j,0,1,1);
	
	}
	//在敌方棋子的右方 
	if(board[i][j-1]==ch){
		//检查左直线上是否有我方棋子，若有且改变棋子
		flag=check_line(i,j,0,-1,1);
	
	}
	//在敌方棋子的左下方 
	if(board[i-1][j+1]==ch){
		//检查右上斜线是否有我方棋子，若有且改变棋子
		flag=check_line(i,j,-1,1,1);

	}
	//在敌方棋子的下方 
	if(board[i-1][j]==ch){
		//检查上直线上是否有我方棋子，若有且改变棋子
		flag=check_line(i,j,-1,0,1);

	}
	//在敌方棋子的右下方 
	if(board[i-1][j-1]==ch){
		//检查上直线上是否有我方棋子，若有且改变棋子
		flag=check_line(i,j,-1,-1,1);

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
	printf("Black - %d White - %d\n",Num_B,Num_W);	
	
}
