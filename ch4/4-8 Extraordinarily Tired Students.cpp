#include<stdio.h>
#include<string.h>
#define maxn 15
const int maxt=1000;//������ʱ���򲻴���ȫ�����ѵ���� 
struct student{
	int A,B,C,period;
	int sleep;
}stu[maxn]; 
int main(){
	//��ѧ������
	int n,kase=0;
	while(scanf("%d",&n)==1 && n!=0){
		//����ѧ������
		memset(stu,0,sizeof(stu));
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&stu[i].A,&stu[i].B,&stu[i].C);
			stu[i].period=stu[i].A+stu[i].B;
			stu[i].sleep=(stu[i].C > stu[i].A)?1:0; 
		}
		int t=1;
		int All_awake=0;
		while(t<=maxt){
			//����˯�ź����ŵ�����
			int sleep=0,awake=0;
			for(int i=0;i<n;i++){
				if(stu[i].sleep)
					sleep++;
				else
					awake++;
			}
			//��ȫ����
			if(awake==n){
				All_awake=1;
				break;
			} 
			//�ж�ѧ����״̬ 
			for(int i=0;i<n;i++){
				//˯ǰ���һ���� 
				if(stu[i].C==stu[i].A){
					if(awake>=sleep)	
						stu[i].C=1;
					else{
						stu[i].C++;
						stu[i].sleep=1;
					}
		
				}else if(stu[i].C==stu[i].period){//������
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
