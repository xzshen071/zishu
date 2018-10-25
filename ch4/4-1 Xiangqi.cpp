#include<stdio.h>
#define maxn 10
struct QNode{
	char type;//棋子的类型
	int x,y;//棋子的位置 
	
}qi[maxn]; 
int n,pos_black_x,pos_black_y;
int move_balck();
char readchar();
int is_over(int x,int y);
int check_lie(int x,int y,int bottom);
int check_hang(int x,int y,int bottom);
int is_bie(int xm,int ym,int dx,int dy);
int main(){
	//输入红色棋的个数与黑棋将的位置
	while(scanf("%d%d%d",&n,&pos_black_x,&pos_black_y)==3 && n!=0){
		for(int i=0;i<n;i++){
			char c=readchar();
			qi[i].type=c;
			scanf("%d%d",&qi[i].x,&qi[i].y);	
		
		}
		/*
		for(int i=0;i<n;i++){
			printf("%c %d %d\n",&qi[i].type,&qi[i].x,&qi[i].y);	
		
		}
		*/
	if(move_balck())
		printf("YES\n");
	else
		printf("NO\n");
			
		 
	} 

	return 0;
} 
char readchar(){
	while(1){
		char ch=getchar();
		if(ch!='\n' && ch!='\r')
			return ch;			
	}
	
} 
int move_balck(){

	int dx,dy;
	for(int i=0;i<4;i++){
		switch(i){
			case 0: //向左
				dx=pos_black_x-1; 
				dy=pos_black_y; 
				break;
			case 1: //向右
				dx=pos_black_x+1;  
				dy=pos_black_y; 
				break;
			case 2: //向后
				dx=pos_black_x; 
				dy=pos_black_y-1;
				break;
			case 3: //向前
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
	for(int i=0;i<n;i++){
		switch(qi[i].type){
			//遇到将的时候 
			case 'G':
				//在一列上且没有棋子挡着 
				if(qi[i].y==y &&  qi[i].x!=x && (check_lie(qi[i].x,qi[i].y,x)==0)){
                    flag=1;

                }
                break;
            //遇到车的时候 
            case 'R':
                if(qi[i].y==y && qi[i].x!=x && (check_lie(qi[i].x,qi[i].y,x)==0)){
                    flag=1;
                }else if(qi[i].x==x && qi[i].y!=y && check_hang(qi[i].x,qi[i].y,y)==0){
                    flag=1;
                }
                break;	
			//遇到炮的时候
			case 'C':
                if(qi[i].y==y  && qi[i].x!=x && (check_lie(qi[i].x,qi[i].y,x)==1)){
                    flag=1;
                }else if(qi[i].x==x && qi[i].y!=y && (check_hang(qi[i].x,qi[i].y,y)==1)){
                    flag=1;
                }
                break;							
			//遇到马的时候，考虑是否蹩
			case 'H':
				//下，正下面有棋不行 
                if(is_bie(qi[i].x,qi[i].y,0,-1)==0){
                    if(qi[i].y-2==y && (qi[i].x-1==x || qi[i].x+1==x)){
                        flag=1;
                    }

                }
                //左，正左面有棋不行  
                if(is_bie(qi[i].x,qi[i].y,-1,0)==0){
                    if(qi[i].x-2==x && (qi[i].y-1==y || qi[i].y+1==y)){
                        flag=1;
                    }
                }
                //上，正上面有棋不行
                if(is_bie(qi[i].x,qi[i].y,0,1)==0){
                    if(qi[i].y+2==y &&(qi[i].x-1==x || qi[i].x+1==x)){
                        flag=1;
                    }
                }
                //右，正右面有棋不行 
                if(is_bie(qi[i].x,qi[i].y,1,0)==0){
                    if((qi[i].y-1==y || qi[i].y+1==y)&& qi[i].x+2==x){
                        flag=1;

                    }
                    break;
                }	 
				
		}
		
	}
	if(flag)
		return 1;
	else 
		return 0; 
	
		
}
//判断前面有几个棋子 
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
//判断前面有几个棋子 
int check_hang(int x,int y,int bottom){
	int count=0; 
	//跨度 
	int min=x<bottom?x:bottom;
	int max=x+bottom-min;
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
