#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	//盒子 
	//输入三组数据和高
	int a[100],h,len=0,wide=0;
	int n,count=0,flag=1;
	for(n=0;scanf("%d%d",&a[n],&a[n+1])==2;n+=2);
	//for(int i=0;i<n;i++){
		//printf("%d\n",a[i]);
	//} 
	scanf("%d",&h);
	//printf("%d\n",h);
	//三组数据其实只有3种数，长宽高。判定条件，一组数的值不相等，数中和高是否有相等，不相等则这组数表示长宽 
	for(int i=0;i<n;i+=2){
		if(a[i]!=a[i+1]){//这组数不相等 
			if(len==0 || wide==0){//初始化len和wide的值 
				if(a[i]==h){
					len=a[i+1];
					count+=2;
					
				} 
				else if(a[i+1]==h){
					len=a[i];
					count+=2;
			
				}
				else{
					len=a[i];
					wide=a[i+1];
					count+=2; 
				}	
			}else{//不用初始化 
				if(a[i]==h || a[i]==len || a[i]==wide)
					count++;
				if(a[i+1]==h || a[i+1]==len || a[i+1]==wide)
					count++; 
	
			}	
	
		}else if(flag){//只能有一次 
			if(a[i]==h && a[i+1]==h )//高可以是正方形 
				count+=2;
			flag=0;
		} 
		else
			break;//不能构成长方体 
	}
	//判断count，如果count不等于输入的个数：6，则不能构成长方体
	if(count==6)
		printf("Yes");
	else
		printf("No"); 
	
	
	
	return 0;
}
