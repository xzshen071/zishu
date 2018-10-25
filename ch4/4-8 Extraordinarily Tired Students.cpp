#include<stdio.h>
#include<string.h>
#define maxn 15
const int maxt=1000;//超过此时间则不存在全部清醒的情况 
struct student{
	int A,B,C,period;
	int sleep;
}stu[maxn]; 
int main(){
	//读学生人数
	int n,kase=0;
	while(scanf("%d",&n)==1 && n!=0){
		//读入学生参数
		memset(stu,0,sizeof(stu));
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&stu[i].A,&stu[i].B,&stu[i].C);
			stu[i].period=stu[i].A+stu[i].B;
			stu[i].sleep=(stu[i].C > stu[i].A)?1:0; 
		}
		int t=1;
		int All_awake=0;
		while(t<=maxt){
			//计算睡着和醒着的人数
			int sleep=0,awake=0;
			for(int i=0;i<n;i++){
				if(stu[i].sleep)
					sleep++;
				else
					awake++;
			}
			//若全醒着
			if(awake==n){
				All_awake=1;
				break;
			} 
			//判断学生的状态 
			for(int i=0;i<n;i++){
				//睡前最后一分钟 
				if(stu[i].C==stu[i].A){
					if(awake>=sleep)	
						stu[i].C=1;
					else{
						stu[i].C++;
						stu[i].sleep=1;
					}
		
				}else if(stu[i].C==stu[i].period){//该醒了
					stu[i].C=1;
					stu[i].sleep=0; 
					
				}else{
					stu[i].C++;
				}
			} 
			t++;
			
		}
		if(All_awake)
			printf("Case %d: %d\n",++kase,t);
		else
			printf("Case %d: -1\n",++kase);	
		
			
	}	
			
		
		
	
	
	
	return 0;
} 
