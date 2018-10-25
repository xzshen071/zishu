#include<stdio.h>
#include<math.h>
double dist(double x1,double y1,double x2,double y2){
	return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}
//子函数中仍可以调用其他函数 
double dist(double x1,double y1,double x2,double y2){
	double dx=(x1-x2);
	double dy=(y1-y2);
	return hypot(dx,dy); 
}
//思考：这个函数是否好用。（x1,y1）可以算是一个整体，（x2,y2）是另一个整体，则可以设计其参数是两个坐标点。所以可以定义结构体
struct point{
	double x,y;
}; //struct point算是一个类型
double dist(struct point a,struct point b){
	return hypot(a.x-b.x,a.y-b.y); 
	
}
//用struct point表示类型有些繁琐，可以用typedef定义类型名称
typedef struct{
	double x,y; 
}point; //这样的格式则可以定义一个新的类型名（自定义类型） 
double dist(point a,point b){
	return hypot(a.x-b.x,a.y-b.y); 
	
}

//main是整个程序的入口，有“其他的程序”来调用这个main函数——如操作系统、IDE、调试器甚至自动评测系统，返回0代表“正常结束”，即返回（告诉）调用者
int main(){
	double x1=2.3,x2=1.3,y1=22.3,y2=10.3;
	double d=dist(x1,y1,x2,y2);
	printf("%f",d);
	
	return 0;
}
 
