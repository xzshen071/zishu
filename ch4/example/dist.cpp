#include<stdio.h>
#include<math.h>
double dist(double x1,double y1,double x2,double y2){
	return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}
//�Ӻ������Կ��Ե����������� 
double dist(double x1,double y1,double x2,double y2){
	double dx=(x1-x2);
	double dy=(y1-y2);
	return hypot(dx,dy); 
}
//˼������������Ƿ���á���x1,y1����������һ�����壬��x2,y2������һ�����壬�����������������������㡣���Կ��Զ���ṹ��
struct point{
	double x,y;
}; //struct point����һ������
double dist(struct point a,struct point b){
	return hypot(a.x-b.x,a.y-b.y); 
	
}
//��struct point��ʾ������Щ������������typedef������������
typedef struct{
	double x,y; 
}point; //�����ĸ�ʽ����Զ���һ���µ����������Զ������ͣ� 
double dist(point a,point b){
	return hypot(a.x-b.x,a.y-b.y); 
	
}

//main�������������ڣ��С������ĳ������������main�������������ϵͳ��IDE�������������Զ�����ϵͳ������0���������������������أ����ߣ�������
int main(){
	double x1=2.3,x2=1.3,y1=22.3,y2=10.3;
	double d=dist(x1,y1,x2,y2);
	printf("%f",d);
	
	return 0;
}
 
