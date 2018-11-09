#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std; 
#define maxn 20 
struct QNode{
	char type;//���ӵ�����
	int x,y;//���ӵ�λ�� 
	
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
	//�����ɫ��ĸ�������彫��λ��
	while(cin >> n >> pos_black_x >> pos_black_y){
		if(n==0) break;
		for(int i=0;i<n;i++){
			cin >> qi[i].type >> qi[i].x >> qi[i].y; 				//���뾡����cin��cin������ո�Ϳ��� 
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
		//�жϳ�ʼ���̺ڷ������췽���ڽ��ͺ콫վһ�𣩺��ƶ��ڽ��ж��Ƿ񱻽��� 
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
//����������е��ǿ��ܶ����ո� 
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
	//�ڽ����ƶ����Ƿ��� 
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
			case 2: //���� 
				dx=pos_black_x; 
				dy=pos_black_y-1;
				break;
			case 3: //���� 
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
	//cout << x << " " << y << endl; 
	for(int i=0;i<n;i++){
		//cout << qi[i].type << endl;
		switch(qi[i].type){
			//��������ʱ�� 
			case 'G':
				//��һ������û�����ӵ��� 
				if(qi[i].y==y &&  qi[i].x!=x && (check_lie(qi[i].x,qi[i].y,x)==0)){			//ֻ��ͬ�� 
                    flag=1;
                    //cout << "1" << endl;
                }
                break;
            //��������ʱ�� 
            case 'R':
                if(qi[i].y==y && qi[i].x!=x && (check_lie(qi[i].x,qi[i].y,x)==0)){			//ͬ�� 
                    flag=1;
                    //cout << "2" << endl;
                }
				if(qi[i].x==x && qi[i].y!=y && (check_hang(qi[i].x,qi[i].y,y)==0)){			//ͬ�� 
                    flag=1;
                    //cout << "3" << endl;
                }
                break;	
			//�����ڵ�ʱ��
			case 'C':
                if(qi[i].y==y  && qi[i].x!=x && (check_lie(qi[i].x,qi[i].y,x)==1)){			//ͬ�� 
                    flag=1;
                    //cout << "4" << endl;
                }
				if(qi[i].x==x && qi[i].y!=y && (check_hang(qi[i].x,qi[i].y,y)==1)){			//ͬ�� 
                    flag=1;
                    //cout << "5" << endl;
                }
                break;							
			//�������ʱ�򣬿����Ƿ���
			case 'H':
				//�����������岻�� 
                if(is_bie(qi[i].x,qi[i].y,0,-1)==0){
                	//cout << "in1"<< endl;
                    if((qi[i].y-2)==y && ((qi[i].x-1)==x || (qi[i].x+1)==x)){
                        flag=1;
                        //cout << "6" << endl;
                    }
                }
                //�ϣ����������岻��  
                if(is_bie(qi[i].x,qi[i].y,-1,0)==0){
                	//cout << "in2" << endl;
                    if((qi[i].x-2)==x && ((qi[i].y-1)==y || (qi[i].y+1)==y)){
                        flag=1;
                        //cout << "7" << endl;
                    }
                }
                //�ң����������岻��
                if(is_bie(qi[i].x,qi[i].y,0,1)==0){
                	//cout << "in3" << endl;
                    if((qi[i].y+2)==y && ((qi[i].x-1)==x || (qi[i].x+1)==x)){
                        flag=1;
                        //cout << "8" << endl;
                    }
                }
                //�£����������岻�� 
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
//�ж�������ͬ��֮���м������� 
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
//�ж�������ͬ��֮���м������� 
int check_hang(int x,int y,int bottom){
	int count=0; 
	//��� 
	int min=y<bottom?y:bottom;
	int max=y+bottom-min;
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
//�жϺ����Ƿ��� 
int dead_R(){
	//�жϺڽ��Ƿ�ͺ콫��һ�� 
	if(pos_black_y == pos_red_y){
		//�жϴ����Ƿ񻹴����������ӣ�Ҫ�ںڽ��ͺ콫֮�� 
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
