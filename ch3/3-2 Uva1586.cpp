#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	//������
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,flag=1;
	scanf("%d",&t); 
	while(t--){
		double mol,sum=0.0;
		char c;
		int ge=1;
		//getchar���Խ��յ��ո񡢻س���Tab�ȷ���(��һ���ж���Ŀո�) 
		if(flag){
			c=getchar();
			flag=0;
		}	
		//��Ȼ˵��һ�ж���ո�ᵼ��ѭ����ĳ��򲻻����У���������˷�һ��t�Ĵ��������Ϊ0�������º��������û��������	
		while((c=getchar())!='\n'){//��׼�ļ������ʱ���������ʱ�س�+ctrl z,����getchar����ջس�����ִ��һ�Σ������ļ��������������������������У� 
		//�ļ������ʱ�����Ҳ���ѻس�����β��ע���ʽ	
			switch(c){//��ѡ��û�й���������ʱ�������switch��� 
				case 'C'://case�������ִ�ж�����䣬���ຯ���������ã�����if�ȣ����԰�����������ã�����Ҫע���߼� 
					mol=12.01;
					//sum=sum+(ge*mol);
					break;
				case 'H':
					mol=1.008;
					break;
				case 'O':
					mol=16.00;
					break;
				case 'N':
					mol=14.01;
					break;
				default:
					ge=c-'1';
					break;
			}
			///printf("%d\n",ge);
			sum=sum+(ge*mol);
			ge=1;
		}

		printf("%f\n",sum);
	}	
	
	
	
	
	
	
	
	return 0;
}
