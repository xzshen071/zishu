#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std; 
#define maxn 20 
struct QNode{
	char type;//棋子的类型
	int x,y;//棋子的位置 
	
}qi[maxn]; 

int pos_red_x,pos_red_y;
int n,pos_black_x,pos_black_y;

int move_balck();
//char readchar();
int is_over(int x,int y);
int check_lie(int x,int y,int bottom);
int check_hang(int x,int y,int bottom);
int is_bie(int xm,int ym,int dx,int dy);
int dead_R();
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//输入红色棋的个数与黑棋将的位置
	while(cin >> n >> pos_black_x >> pos_black_y){
		if(n==0) break;
		for(int i=0;i<n;i++){
			cin >> qi[i].type >> qi[i].x >> qi[i].y; 				//读入尽量用cin，cin不会读空格和空行 
			//scanf("%d%d",&qi[i].x,&qi[i].y);
			//cout << qi[i].type << " " << qi[i].x << " " << qi[i].y << endl;
			if(qi[i].type=='G'){
				pos_red_x = qi[i].x;
				pos_red_y = qi[i].y;
				//cout <<  pos_red_x << " " << pos_red_y << endl;
			}
		}
		/*
		for(int i=0;i<n;i++){
			printf("%c %d %d\n",&qi[i].type,&qi[i].x,&qi[i].y);	
		
		}
		*/
		//cout << pos_red_x << " " << pos_red_y << endl;
		//cout << pos_black_x << " " << pos_black_y << endl;
		//判断初始棋盘黑方将死红方（黑将和红将站一起）和移动黑将判断是否被将死 
		//cout << dead_R() << endl;
		if(!dead_R() && move_balck()){
			cout << "YES\n"; 
		}else{
			cout << "NO\n";
		}
					 
	} 
	
	return 0;
} 
/*
//不会读到空行但是可能读到空格 
char readchar(){
	while(1){
		char ch=getchar();
		if(ch!='\n' && ch!='\r')
			return ch;			
	}
} 
*/
int move_balck(){
	
	int dx,dy;
	//黑将棋移动看是否将死 
	for(int i=0;i<4;i++){
		switch(i){
			case 0: //向上 
				dx=pos_black_x-1; 
				dy=pos_black_y; 
				break;
			case 1: //向下 
				dx=pos_black_x+1;  
				dy=pos_black_y; 
				break;
			case 2: //向左 
				dx=pos_black_x; 
				dy=pos_black_y-1;
				break;
			case 3: //向右 
				dx=pos_black_x; 
				dy=pos_black_y+1; 
				break;
		}
		//将移动的位置受限制
		if(dx>=1 && dx<=3 && dy>=4 && dy<=6){
			//printf("%d %d %d\n",dx,dy,is_over(dx,dy));
			if(is_over(dx,dy)==0)
				return 0;
		} 
	}

	return 1;	
}	

int is_over(int x,int y){
	int flag=0;
	//cout << x << " " << y << endl; 
	for(int i=0;i<n;i++){
		//cout << qi[i].type << endl;
		switch(qi[i].type){
			//遇到将的时候 
			case 'G':
				//在一列上且没有棋子挡着 
				if(qi[i].y==y &&  qi[i].x!=x && (check_lie(qi[i].x,qi[i].y,x)==0)){			//只能同列 
                    flag=1;
                    //cout << "1" << endl;
                }
                break;
            //遇到车的时候 
            case 'R':
                if(qi[i].y==y && qi[i].x!=x && (check_lie(qi[i].x,qi[i].y,x)==0)){			//同列 
                    flag=1;
                    //cout << "2" << endl;
                }
				if(qi[i].x==x && qi[i].y!=y && (check_hang(qi[i].x,qi[i].y,y)==0)){			//同行 
                    flag=1;
                    //cout << "3" << endl;
                }
                break;	
			//遇到炮的时候
			case 'C':
                if(qi[i].y==y  && qi[i].x!=x && (check_lie(qi[i].x,qi[i].y,x)==1)){			//同列 
                    flag=1;
                    //cout << "4" << endl;
                }
				if(qi[i].x==x && qi[i].y!=y && (check_hang(qi[i].x,qi[i].y,y)==1)){			//同行 
                    flag=1;
                    //cout << "5" << endl;
                }
                break;							
			//遇到马的时候，考虑是否蹩
			case 'H':
				//左，正左面有棋不行 
                if(is_bie(qi[i].x,qi[i].y,0,-1)==0){
                	//cout << "in1"<< endl;
                    if((qi[i].y-2)==y && ((qi[i].x-1)==x || (qi[i].x+1)==x)){
                        flag=1;
                        //cout << "6" << endl;
                    }
                }
                //上，正上面有棋不行  
                if(is_bie(qi[i].x,qi[i].y,-1,0)==0){
                	//cout << "in2" << endl;
                    if((qi[i].x-2)==x && ((qi[i].y-1)==y || (qi[i].y+1)==y)){
                        flag=1;
                        //cout << "7" << endl;
                    }
                }
                //右，正右面有棋不行
                if(is_bie(qi[i].x,qi[i].y,0,1)==0){
                	//cout << "in3" << endl;
                    if((qi[i].y+2)==y && ((qi[i].x-1)==x || (qi[i].x+1)==x)){
                        flag=1;
                        //cout << "8" << endl;
                    }
                }
                //下，正下面有棋不行 
                if(is_bie(qi[i].x,qi[i].y,1,0)==0){
                	//cout << "in4" << endl;
                    if((qi[i].x+2)==x && ((qi[i].y-1)==y || (qi[i].y+1)==y)){
                        flag=1;
                        //cout << "9" << endl;
                    }
                }
				break;	 	
		}
		//cout << i << endl;
	}
	if(flag)
		return 1;
	else 
		return 0; 	
}
//判断两棋子同列之间有几个棋子 
int check_lie(int x,int y,int bottom){
	int count=0; 
	//跨度 
	int min=x<bottom?x:bottom;
	int max=x+bottom-min;
	for(int i=0;i<n;i++){
        if(qi[i].y==y && qi[i].x<max && qi[i].x>min)
            count++;
    }
    //printf("%d\n",count);
    return count;
	
}
//判断两棋子同行之间有几个棋子 
int check_hang(int x,int y,int bottom){
	int count=0; 
	//跨度 
	int min=y<bottom?y:bottom;
	int max=y+bottom-min;
	for(int i=0;i<n;i++){
        if(qi[i].x==x && qi[i].y<max && qi[i].y>min)
            count++;
    }
    //printf("%d\n",count);
    return count;
}
//是否蹩马 
int is_bie(int xm,int ym,int dx,int dy){
    int x=xm+dx;
    int y=ym+dy;
    for(int i=0;i<n;i++){
        if(qi[i].x==x && qi[i].y==y)
            return 1;
    }
    return 0;
}
//判断红棋是否输 
int dead_R(){
	//判断黑将是否和红将在一列 
	if(pos_black_y == pos_red_y){
		//判断此列是否还存在其他棋子，要在黑将和红将之间 
		for(int i=0;i<n;i++){
			if(qi[i].type != 'G' && qi[i].y == pos_black_y && qi[i].x > pos_black_x && qi[i].x < pos_red_x){
				//cout << qi[i].type << " " << qi[i].x << " " << qi[i].y << endl; 
				return 0;
			}
		} 
	}else
		return 0;
	
	return 1;
}
