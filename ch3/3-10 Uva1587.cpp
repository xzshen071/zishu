#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	//���� 
	//�����������ݺ͸�
	int a[100],h,len=0,wide=0;
	int n,count=0,flag=1;
	for(n=0;scanf("%d%d",&a[n],&a[n+1])==2;n+=2);
	//for(int i=0;i<n;i++){
		//printf("%d\n",a[i]);
	//} 
	scanf("%d",&h);
	//printf("%d\n",h);
	//����������ʵֻ��3����������ߡ��ж�������һ������ֵ����ȣ����к͸��Ƿ�����ȣ����������������ʾ���� 
	for(int i=0;i<n;i+=2){
		if(a[i]!=a[i+1]){//����������� 
			if(len==0 || wide==0){//��ʼ��len��wide��ֵ 
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
			}else{//���ó�ʼ�� 
				if(a[i]==h || a[i]==len || a[i]==wide)
					count++;
				if(a[i+1]==h || a[i+1]==len || a[i+1]==wide)
					count++; 
	
			}	
	
		}else if(flag){//ֻ����һ�� 
			if(a[i]==h && a[i+1]==h )//�߿����������� 
				count+=2;
			flag=0;
		} 
		else
			break;//���ܹ��ɳ����� 
	}
	//�ж�count�����count����������ĸ�����6�����ܹ��ɳ�����
	if(count==6)
		printf("Yes");
	else
		printf("No"); 
	
	
	
	return 0;
}
