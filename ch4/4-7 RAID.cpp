#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
using namespace std;
int d,s,b;
int num_1[7000];//��ÿ��'1'�ĸ��� 
char data[10][7000]; 
char ch_type;
char table[20]="0123456789ABCDEF"; 
int is_legal();
char readchar();
void Print_data();
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	//����d(����)��s(������)��b(����)
	int kase=0;
	while(scanf("%d",&d)==1 && d!=0){
		scanf("%d%d",&s,&b);
		//��У������
		ch_type=readchar(); 
		//printf("%c\n",ch_type);
		//������
		for(int i=0;i<d;i++){
			scanf("%s",data[i]);
		}
		/*
		for(int i=0;i<d;i++){
			printf("%s\n",data[i]);
		}
		*/
		//���̷Ƿ����з��򳬹�1��xx���з���У�����
		if(is_legal()==0){
			//cout << "1" << endl;
			printf("Disk set %d is invalid.\n",++kase);
		}else{
			printf("Disk set %d is valid, contents are: ",++kase);
			Print_data();
		}
		
	} 
	return 0;
}
char readchar(){
	while(1){
		char ch=getchar();
		if(ch!='\r' && ch!='\n')
			return ch;
	}
}
//���̷Ƿ����з��򳬹�1��xx���з���У�����
int is_legal(){ 
	memset(num_1,0,sizeof(num_1));
	//ÿ�����У����ж�ĳ�з��򳬹�1��xx,��ÿ�С�1���ĸ��� 
	for(int j=0;j<s*b;j++){
		int num_x=0; 
		for(int i=0;i<d;i++){
			//һ�з��򳬹�1��xx
			if(data[i][j]=='x'){
				num_x++;
				if(num_x>1){
					//printf("1\n");
					return 0;
				}
			}else if(data[i][j]=='1'){
				num_1[j]++;
			} 
		}
	}
	/*
	for(int j=0;j<s*b;j++){
		printf("%d",num_1[j]);
	}
	*/
	//printf("\n");
	//�ı�x��ֵ��Ȼ���ж��Ƿ��з���У����� 
	for(int j=0;j<s*b;j++){
		for(int i=0;i<d;i++){
			//�ı�x��ֵ 
			if(data[i][j]=='x'){		//żУ�� 
				if(ch_type=='E'){
					if(num_1[j]%2==0)//ż�� 
						data[i][j]='0'; 
					else{
						data[i][j]='1'; 
						num_1[j]++; 
					}
				}else{					//��У�� 
					if(num_1[j]%2==0){//ż�� 
						data[i][j]='1'; 
						num_1[j]++; 
					}else
						data[i][j]='0'; 
				} 
			}	
		}
		if(ch_type=='E' && num_1[j]%2!=0){//ż��ÿһ��һ'1'�ĸ���Ϊż�� 
			//printf("2\n");
			return 0;	
		}else if(ch_type=='O' && num_1[j]%2==0){//��:ÿһ��һ'1'�ĸ���Ϊ���� 
			//printf("3\n");
			return 0;	
		} 		
	
	}
	/*
	for(int i=0;i<d;i++){
		printf("%s\n",data[i]);
	}
	*/
	return 1;
}
//��ӡ���� 
void Print_data(){
	int Judge_x=0,Judge_y=0; 
	//ע��У��λ
	int flag=4,sum=0;
	for(int j=0;j<b;j++){			//���ݿ��� 
		for(int i=0;i<d;i++){		//���� 
			for(int k=0;k<s;k++){	//ÿ�����ݿ������ 
				//����У��λ��ÿd�����ݿ����һ��У��λ 
				if(i==Judge_x && j==Judge_y){
					//printf("%d %d\n",i,j);
					if(Judge_x == (d-1)) Judge_x = 0;
					else Judge_x++;
					Judge_y++;
					break;
				}
				//��û��4λ 
				flag--;
				sum+=(data[i][j*s+k]-'0')*pow(2,flag);
				//printf("%d",data[i][j*s+k]-'0');
				//printf("\n%d %d\n",flag,sum);
				if(flag==0){
					//printf("\n%d\n",sum);
					printf("%c",table[sum]);
					flag=4;
					sum=0;
				}
			}
		}
	}
	if(flag==4 ){
		printf("\n");
	}else{
		printf("%c\n",table[sum]);
	}
}
