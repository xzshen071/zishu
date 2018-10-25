#include<stdio.h>
#define maxn 10
struct QNode{
	char type;//���ӵ�����
	int x,y;//���ӵ�λ�� 
	
}qi[maxn]; 
int n,pos_black_x,pos_black_y;
int move_balck();
char readchar();
int is_over(int x,int y);
int check_lie(int x,int y,int bottom);
int check_hang(int x,int y,int bottom);
int is_bie(int xm,int ym,int dx,int dy);
int main(){
	//�����ɫ��ĸ�������彫��λ��
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
			case 0: //����
				dx=pos_black_x-1; 
				dy=pos_black_y; 
				break;
			case 1: //����
				dx=pos_black_x+1;  
				dy=pos_black_y; 
				break;
			case 2: //���
				dx=pos_black_x; 
				dy=pos_black_y-1;
				break;
			case 3: //��ǰ
				dx=pos_black_x; 
				dy=pos_black_y+1; 
				break;
		}
		//���ƶ���λ��������
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
			//��������ʱ�� 
			case 'G':
				//��һ������û�����ӵ��� 
				if(qi[i].y==y &&  qi[i].x!=x && (check_lie(qi[i].x,qi[i].y,x)==0)){
                    flag=1;

                }
                break;
            //��������ʱ�� 
            case 'R':
                if(qi[i].y==y && qi[i].x!=x && (check_lie(qi[i].x,qi[i].y,x)==0)){
                    flag=1;
                }else if(qi[i].x==x && qi[i].y!=y && check_hang(qi[i].x,qi[i].y,y)==0){
                    flag=1;
                }
                break;	
			//�����ڵ�ʱ��
			case 'C':
                if(qi[i].y==y  && qi[i].x!=x && (check_lie(qi[i].x,qi[i].y,x)==1)){
                    flag=1;
                }else if(qi[i].x==x && qi[i].y!=y && (check_hang(qi[i].x,qi[i].y,y)==1)){
                    flag=1;
                }
                break;							
			//�������ʱ�򣬿����Ƿ���
			case 'H':
				//�£����������岻�� 
                if(is_bie(qi[i].x,qi[i].y,0,-1)==0){
                    if(qi[i].y-2==y && (qi[i].x-1==x || qi[i].x+1==x)){
                        flag=1;
                    }

                }
                //�����������岻��  
                if(is_bie(qi[i].x,qi[i].y,-1,0)==0){
                    if(qi[i].x-2==x && (qi[i].y-1==y || qi[i].y+1==y)){
                        flag=1;
                    }
                }
                //�ϣ����������岻��
                if(is_bie(qi[i].x,qi[i].y,0,1)==0){
                    if(qi[i].y+2==y &&(qi[i].x-1==x || qi[i].x+1==x)){
                        flag=1;
                    }
                }
                //�ң����������岻�� 
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
//�ж�ǰ���м������� 
int check_lie(int x,int y,int bottom){
	int count=0; 
	//��� 
	int min=x<bottom?x:bottom;
	int max=x+bottom-min;
	for(int i=0;i<n;i++){
        if(qi[i].y==y && qi[i].x<max && qi[i].x>min)
            count++;
    }
    //printf("%d\n",count);
    return count;
	
}
//�ж�ǰ���м������� 
int check_hang(int x,int y,int bottom){
	int count=0; 
	//��� 
	int min=x<bottom?x:bottom;
	int max=x+bottom-min;
	for(int i=0;i<n;i++){
        if(qi[i].x==x && qi[i].y<max && qi[i].y>min)
            count++;
    }
    //printf("%d\n",count);
    return count;
	
}
//�Ƿ����� 
int is_bie(int xm,int ym,int dx,int dy){
    int x=xm+dx;
    int y=ym+dy;
    for(int i=0;i<n;i++){
        if(qi[i].x==x && qi[i].y==y)
            return 1;
    }
    return 0;
}
