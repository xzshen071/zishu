//�ȼý𷢷�
#include<stdio.h>
#include<string.h>
#define maxn 25
int s[maxn],n,k,m;
//p�ǵ�ǰλ�ã�������d��˳ʱ��Ϊ-1����ʱ��Ϊ1����tΪ����������������λ�� 
int leave(int p,int d,int t);
int main(){
	//����
	int k,m;
	scanf("%d%d%d",&n,&k,&m); 
	//��ʼ����� 
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++){
		s[i]=i;
	} 
	//���žȼý�
	//��������
	int left=n;//ʣ������ 
	//��ʼֵ
	int p1=n;
	int p2=1; 
	while(left){
		//��ѡ�뿪����
		//��ʱ�� 
		p1=leave(p1,1,k);//��һ�δӺ�һλ��ʼ�� 
		//˳ʱ��
		p2=leave(p2,-1,m); 
		printf("%3d",p1);
		left--;
		s[p1]=s[p2]=0;
		if(p2!=p1){
			printf("%3d",p2);
			left--;
		}
		if(left)
			printf(",");		
		
		
	} 
	
	return 0;
}
int leave(int p,int d,int t){
	//���Ҵ��� 
	while(t--){
		do{
			//��n��Ϊ�˷�ֹ��ɸ�����(p+d+n-1)%n��ʾ�ķ�Χ��0~n-1�������ڸı�λ��֮ǰҪ-1������λ��n��ʱ��-1���n-1,Ȼ��ӳ��Ϊn 
			p=(p+d+n-1)%n +1;
			printf("%d\n",p); 
		}while(s[p]==0);//�ߵ���һ����0���� 
		
	}
	//�뿪��������λ�õ�����Ϊ0
	//s[p]=0;//���ܷ������Ϊ��Ӱ����һ�ε��õĽ������������˳����ͬ����� 
	return p;
	
	
}
