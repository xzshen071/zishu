#include<stdio.h>
//������Ϊ���ز���
/*
int sum(int a[]){//��ʵ��������Ϊ�������ݸ�����ʱ��ʵ����ֻ��������׵�ַ��Ϊָ�봫���˺�����int a[]�൱��int* a; 
	int ans=0;
	printf("%d\n",sizeof(a));//��Ȼsizeof(a)��ֵ���������ִ��ݷ�ʽ��̫��ȷ 
	for(int i=0;i<sizeof(a);i++)
		ans+=a[i];
	return ans; 
	
} 
int main(){
	int a[]={1,2,3,4,5,6,7,3};
	int ans=sum(a);
	printf("%d\n",ans);
		
	return 0;
}
//��ȷ������
int sum(int* a,int n){
	int ans=0;
	for(int i=0;i<n;i++)
		ans+=a[i];//��*(a+i)�ȼ� 
	return ans;
	
} 
int main(){
	int a[]={1,2,3,4,5,6,7,3};
	//��ʵ��ʱ�����ʱ�򣬴��ݸ��β�ʱ������д��&a�����������ᱨ����Ϊ����a���ݵı�������a���׵�ַ��������ָ��ļӼ���������Ԫ�ص��׵�ַ���ݸ������� 
	int ans=sum(a+1,7);//aָ��a[0];a+1ָ��a[1] 
	printf("%d\n",ans);//�����30 
	
	return 0;

*/

//��������ҿ������ڵ�Ԫ�غ�
/* 
//��һ�� 
int sum(int* begin,int* end){
	int ans=0; 
	//for(int i=0;i<end;i++){//i���ܺ�ָ��Ƚ� 
		//ans+=*(begin+i)
	//}
	
	int n=end-begin;//������ֵʱ���Ե�(������Ӽ�)
	for(int i=0;i<n;i++){
		ans+=begin[i];//*(begin+i)������ֱ�ӵ��������� 
	} 
	
	//int n=end;//�������ܰ�ָ���ַ��ֵ��int�� 
	//for(int i=begin;i<n;i++){//���� 
	//	ans+=*begin;
	//} 
	return ans;	
} 
//�ڶ���
int sum(int* begin,int* end){
	int ans=0;
	for(int *p=begin;p!=end;p++)//��ָ���ַ��ѭ������ 
		ans+=*p;
	
	return ans;
} 

int main(){
	int a[]={1,2,3,4,5,6,7,3};
	printf("%d",sum(a+1,a+7)); 
	
	return 0;
}
*/ 
/* 
//���ԣ��޸�����Ԫ�����ֵ
void Change(int* a,int n){
	a[n]=6;
	
	return;
	
} 
int main(){
	int a[]={1,2,3,4,5,6,7};
	Change(a,2);//���Ըı��������� 
	printf("%d\n",sizeof(a));//�����sizeof(a)��ֵ����7����28��˵��a[]={}��ֵ�������е�Ԫ�ظ�����ȷ�� 
	printf("%d\n",a[2]);

}
*/ 
