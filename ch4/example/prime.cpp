#include<stdio.h>
#include<math.h> 
//����ֻ�ܱ�1���Լ�����
/* 
//Ҳ�ɷ���int���ͣ�0��1�ֱ����false��true 
bool Is_prime(int n){
	//Ҫ����n���Ϊ1ʱ���������
	if(n==1)
		return false; 
	for(int i=2;i<n;i++){
		if(n%i==0){
			return false;
					
		}

	}
	return true;

	
} 
*/ 
//���ϵĳ���
/* 
//n̫��ʱ����
//ԭ��n����ӽ�int���͵����ֵ����ôi++��i*i���ܻᳬ��int���͵����ֵ����ɸ��������³������д��� 
int Is_prime(int n){
	if(n=1)
		return 0;
	//Ϊʲô�⿼��ƽ�����������Լ����������� 
	//��Ϊ�����������������ô��һ�����Ա�ʾ��������������1����������ˣ�����������Ȼ��һ��С�ڵ�������ƽ������ֻҪ�ҵ�С�ڻ���ڵ��Ǹ������� 
	for(int i=2;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
} 
*/ 
//�Ľ� 
//�������Ĳ�����long long�͵Ĳ��ܺܿ�ļ�����𰸣�����������ʽ 
int Is_prime(int n){
	if(n=1)
		return 0;
	//��ô������������i*i����
	int m=floor(sqrt(n)+0.5);//sqrt(n)���Ǹ���������������׼ȷ����ͨ������������⸡����� 
	for(int i=2;i<=m;i++)
		if(n%i==0)
			return 0;
	return 1;
} 

int main(){
	if(Is_prime(2147483647))
		printf("Yes\n");
	else 
		printf("No\n");	
	return 0;
} 
