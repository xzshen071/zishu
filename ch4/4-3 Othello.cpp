#include<stdio.h>
#include<string.h> 
#include<iostream>
using namespace std;

#define maxn 10
char board[maxn][maxn];
char player;

char readchar();
int Print_operate(int f); 									//�������1�Ǵ�ӡ�Ϸ��������������0ֻ���ж���û�кϷ����� 
int check_line(int x,int y,int dx,int dy,int symbol);
void change_board(int x,int y);
void Print_W_B();
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	
	//������Ϸ����
	int t,flag=1;
	scanf("%d",&t);
	while(t--){
		if(flag) flag=0;
		else printf("\n");
		
		//�����̣��Ǵ�(0,0)��ʼ��� 
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
			if(s[0]=='Q'){				//�����������ӡ���� 
				for(int i=0;i<8;i++){ 
					printf("%s\n",board[i]); 
				}
				break;	
			}
			switch(s[0]){
				case 'L':				//��ӡ���кϷ��Ĳ�����������ı䵱ǰ��Ϸ�ߣ��ı䵱ǰ��Ϸ�߲��ԣ� 
					/*
					for(int i=0;i<8;i++)
						printf("%s\n",board[i]);
					*/
					Print_operate(1);
					break;
				case 'M':				//��һö�ܺϷ�����������
					//��player������ 
					//printf("%d %d\n",s[1]-'0',s[2]-'0');
					//cout << Print_operate(0) << endl;
					if(Print_operate(0)==0){				//�ж��Ƿ��кϷ�������û����ı䵱ǰ��Ϸ�� 
						//cout << 1 << endl;
						if(player=='W') player='B';			//ע����==д��=�� 
						else player='W';
					}
					board[s[1]-'0'-1][s[2]-'0'-1]=player;	//������ 
					//��ֱ仯 
					change_board(s[1]-1-'0',s[2]-1-'0');	//Ӧ����������������� 
					
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
//����һ�����ǿ��е��ַ� 
char readchar(){
	while(1){
		char ch=getchar();
		if(ch!='\r' && ch!='\n')
			return ch;
	}
}
//��ӡ���кϷ��Ĳ��������մ��ϵ��£������ҵ�˳��û�кϷ����������No legal move�� 
int Print_operate(int f){
	//ch����з������� 
	char ch;
	if(player=='W')
		ch='B';
	else
		ch='W';
	//printf("%c\n",ch);
	int flag=0;
	//���ϵ��£������ҵ�˳�� 
	for(int i=0;i<8;i++){			//�� 
		for(int j=0;j<8;j++){		//�� 
			if(board[i][j]=='-'){	//���Է��õ�λ����'-'�����ܴ����ظ���ӡ�������ֻ��ӡһ�Σ�
				if(board[i+1][j+1]==ch && check_line(i,j,1,1,0)){			//�ڵз����ӵ����Ͻ�������б�������ҷ�����
					if(f){		//f = 1�Ŵ�ӡ 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//����1����Ϊ�����Ǵ�(0,0)��ʼ��� 
					}
					flag++;
				}else if(board[i+1][j]==ch && check_line(i,j,1,0,0)){		//�ڵз����ӵ����Ϸ�����ֱ�������ҷ�����
					if(f){		//f = 1�Ŵ�ӡ 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//����1����Ϊ�����Ǵ�(0,0)��ʼ��� 
					}
					flag++;
				}else if(board[i+1][j-1]==ch && check_line(i,j,1,-1,0)){	//�ڵз����ӵ����Ϸ�������б�����ҷ����� 
					if(f){		//f = 1�Ŵ�ӡ 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//����1����Ϊ�����Ǵ�(0,0)��ʼ��� 
					}
					flag++;
				}else if(board[i][j+1]==ch && check_line(i,j,0,1,0)){		//�ڵз����ӵ�������ֱ�������ҷ�����
					if(f){		//f = 1�Ŵ�ӡ 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//����1����Ϊ�����Ǵ�(0,0)��ʼ��� 
					}
					flag++;
				}else if(board[i][j-1]==ch && check_line(i,j,0,-1,0)){		//�ڵз����ӵ��ҷ�����ֱ�������ҷ����� 
					if(f){		//f = 1�Ŵ�ӡ 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//����1����Ϊ�����Ǵ�(0,0)��ʼ��� 
					}
					flag++;
				}else if(board[i-1][j+1]==ch && check_line(i,j,-1,1,0)){	//�ڵз����ӵ����·�������б�����ҷ�����
					if(f){		//f = 1�Ŵ�ӡ 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//����1����Ϊ�����Ǵ�(0,0)��ʼ��� 
					}
					flag++;
				}else if(board[i-1][j]==ch && check_line(i,j,-1,0,0)){		//�ڵз����ӵ��·�����ֱ�������ҷ�����
					if(f){		//f = 1�Ŵ�ӡ 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//����1����Ϊ�����Ǵ�(0,0)��ʼ��� 
					}
					flag++;
				}else if(board[i-1][j-1]==ch && check_line(i,j,-1,-1,0)){		//�ڵз����ӵ����·�������б�����ҷ����� 
					if(f){		//f = 1�Ŵ�ӡ 
						if(flag)
							printf(" ");
						printf("(%d,%d)",i+1,j+1);	//����1����Ϊ�����Ǵ�(0,0)��ʼ��� 
					}
					flag++;	
				}
			}	
		}
	}
	if(flag){
		if(f) printf("\n"); 
	}
	else{											//���flag = 0����˵��û�кϷ����� 
		if(f) printf("No legal move.\n");
		//player=ch;								//����û��˵Ҫ�任��Ϸ�� 
	}
	return flag; 
}
//dxΪx��ÿ���ƶ��Ĳ�����dyΪyÿ���ƶ��Ĳ�����ͬʱ�ƶ���ע��·���в�����'-'���еĻ�����Ϸ�λ�� 
int check_line(int x,int y,int dx,int dy,int symbol){
	//symbol=0�ǲ��ң�symbol=1��������ڵĻ��������� 
	int xm=x+dx;					
	int ym=y+dy;
	int flag=0;
	while(xm>=0 && xm<8 && ym>=0 && ym<8){
		xm+=dx;
		ym+=dy;
		if(board[xm][ym]=='-') break;			//��;��'-'�ַ���ֱ������ѭ�����Ϸ� 
		if(board[xm][ym]==player){
			flag=1;
			break;
		}
	} 
	//ѭ��������xΪplayer���ӵ���ɫ 
	//����·�����ӱ��player������ 
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
		check_line(i,j,1,1,1);
	}
	//�ڵз����ӵ����Ϸ� 
	if(board[i+1][j]==ch){
		//�����ֱ�����Ƿ����ҷ����ӣ������Ҹı�����
		//printf("66666\n");
		check_line(i,j,1,0,1);
	}
	//�ڵз����ӵ����Ϸ�
	if(board[i+1][j-1]==ch){
		//�������б���Ƿ����ҷ����ӣ������Ҹı�����
		check_line(i,j,1,-1,1); 
	}
	//�ڵз����ӵ��� 
	if(board[i][j+1]==ch){
		//�����ֱ�����Ƿ����ҷ����ӣ������Ҹı�����
		check_line(i,j,0,1,1);
	}
	//�ڵз����ӵ��ҷ� 
	if(board[i][j-1]==ch){
		//printf("66666\n");
		//�����ֱ�����Ƿ����ҷ����ӣ������Ҹı�����
		check_line(i,j,0,-1,1);
	}
	//�ڵз����ӵ����·� 
	if(board[i-1][j+1]==ch){
		//�������б���Ƿ����ҷ����ӣ������Ҹı�����
		check_line(i,j,-1,1,1);
	}
	//�ڵз����ӵ��·� 
	if(board[i-1][j]==ch){
		//�����ֱ�����Ƿ����ҷ����ӣ������Ҹı�����
		check_line(i,j,-1,0,1);
	}
	//�ڵз����ӵ����·� 
	if(board[i-1][j-1]==ch){
		//�����ֱ�����Ƿ����ҷ����ӣ������Ҹı�����
		check_line(i,j,-1,-1,1);
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
	printf("Black - %2d White - %2d\n",Num_B,Num_W);
}
