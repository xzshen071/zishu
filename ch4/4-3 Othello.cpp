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
	//������Ϸ����
	int t;
	scanf("%d",&t);
	while(t--){
		//printf("%d\n",t);
		//������
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
		//����
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
				case 'L'://��ӡ���кϷ��Ĳ�����������ı䵱ǰ��Ϸ�� 
					Print_operate();
					break;
				case 'M'://��һö�ܺϷ�����������
					//��player������ 
					//printf("%d %d\n",s[1]-'0',s[2]-'0');
					board[s[1]-'0'-1][s[2]-'0'-1]=player;
					//��ֱ仯 
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
				//�ڵз����ӵ����Ͻ�
				if(board[i+1][j+1]==ch){
					//�������б�����Ƿ����ҷ�����
					if(check_line(i,j,1,1,0)){
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
 
				} 
				//�ڵз����ӵ����Ϸ�
				if(board[i+1][j]==ch){
					//�����ֱ�����Ƿ����ҷ�����
					if(check_line(i,j,1,0,0)){
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
					
				}
				//�ڵз����ӵ����Ϸ�
				if(board[i+1][j-1]==ch){
					//�������б���Ƿ����ҷ�����
					if(check_line(i,j,1,-1,0)){
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
				
				}
				//�ڵз����ӵ��� 
				if(board[i][j+1]==ch){
					//�����ֱ�����Ƿ����ҷ�����
					if(check_line(i,j,0,1,0)){
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
					
				}
				//�ڵз����ӵ��ҷ� 
				if(board[i][j-1]==ch){
					//�����ֱ�����Ƿ����ҷ�����
					if(check_line(i,j,0,-1,0)){
						if(flag)
							printf(" ");						
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
					
				}
				//�ڵз����ӵ����·� 
				if(board[i-1][j+1]==ch){
					//�������б���Ƿ����ҷ�����
					if(check_line(i,j,-1,1,0)){
						if(flag)
							printf(" ");						
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
					
				}
			 	//�ڵз����ӵ��·� 
				if(board[i-1][j]==ch){
					//�����ֱ�����Ƿ����ҷ�����
					if(check_line(i,j,-1,0,0)){
						if(flag)
							printf(" ");						
						printf("(%d,%d)",i+1,j+1);
						flag++;
					}
					
				}
				//�ڵз����ӵ����·� 
				if(board[i-1][j-1]==ch){
					//�����ֱ�����Ƿ����ҷ�����
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
//dxΪx��ÿ���ƶ��Ĳ�����dyΪyÿ���ƶ��Ĳ�����ͬʱ�ƶ� 
int check_line(int x,int y,int dx,int dy,int symbol){
	//symbol=0�ǲ��ң�symbol=1��������ڵĻ��������� 
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
	//����·�����ӱ��player������ 
	if(symbol && flag){
		//printf("%d\n",flag);
		do{
			xm-=dx;
			ym-=dy;
			board[xm][ym]=player;
			//printf("%c\n",board[xm][ym]);
	
		}while(xm!=x+dx);
			
	}
	return flag;//flagΪ1˵���У�flagΪ0˵��û�� 
	
	
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
	//�жϸ�����8�������Ƿ��ез�����
	//�ڵз����ӵ����Ϸ�
	int flag;		
	int i=x,j=y;
	//printf("%d %d\n",i,j);
	if(board[i+1][j+1]==ch){
		//�������б�����Ƿ����ҷ����ӣ������Ҹı����� 
		flag=check_line(i,j,1,1,1);
		
	}
	//�ڵз����ӵ����Ϸ� 
	if(board[i+1][j]==ch){
		//�����ֱ�����Ƿ����ҷ����ӣ������Ҹı�����
		//printf("66666\n");
		flag=check_line(i,j,1,0,1);

	}
	//�ڵз����ӵ����Ϸ�
	if(board[i+1][j-1]==ch){
		//�������б���Ƿ����ҷ����ӣ������Ҹı�����
		flag=check_line(i,j,1,-1,1); 

	}
	//�ڵз����ӵ��� 
	if(board[i][j+1]==ch){
		//�����ֱ�����Ƿ����ҷ����ӣ������Ҹı�����
		flag=check_line(i,j,0,1,1);
	
	}
	//�ڵз����ӵ��ҷ� 
	if(board[i][j-1]==ch){
		//�����ֱ�����Ƿ����ҷ����ӣ������Ҹı�����
		flag=check_line(i,j,0,-1,1);
	
	}
	//�ڵз����ӵ����·� 
	if(board[i-1][j+1]==ch){
		//�������б���Ƿ����ҷ����ӣ������Ҹı�����
		flag=check_line(i,j,-1,1,1);

	}
	//�ڵз����ӵ��·� 
	if(board[i-1][j]==ch){
		//�����ֱ�����Ƿ����ҷ����ӣ������Ҹı�����
		flag=check_line(i,j,-1,0,1);

	}
	//�ڵз����ӵ����·� 
	if(board[i-1][j-1]==ch){
		//�����ֱ�����Ƿ����ҷ����ӣ������Ҹı�����
		flag=check_line(i,j,-1,-1,1);

	} 
	/*
	for(int i=0;i<8;i++){
		printf("%s\n",board[i]);
			
	}
	*/
	//��ӡ�ڰ���ĸ���
	Print_W_B();
	
	//�ı䵱ǰ��Ϸ�� 
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
