#include<stdio.h>
#include<string.h>
int readint(int c);
int readcodes();
int readchar();
int code[8][1<<8];//��ʽΪcode[len][v]��lenΪ���볤�ȣ�vΪ��Ӧ��ʮ����ֵ����Χ��0~(1<<len)-2�����洢�˱�����ַ� 
int main(){
	//������ͷ,�޷���ȡ����ı���ͷʱ�˳� 
	while(readcodes()){
		while(1){
			//��ǰ3�����������֣���ת��Ϊʮ���� 
			int len=readint(3);
			if(len==0)//Ϊ0���������� 
				break;
			//printf("len=&d\n",len); 
			while(1){//��Ϊ0 
				int v=readint(len);
			//printf("v=%d\n",v);
				if(v==(1<<len)-1)//�����len��1��С�����,len=2ʱ�����������ǵ���3 
					break; 
				putchar(code[len][v]);
				
				
			}
			
		}
		putchar('\n');//һ�α������ 
		
	} 
	
	
	
	return 0;
} 
int readcodes(){
	//��ʼ���������� 
	memset(code,0,sizeof(code));
	//����һ���ǿ��е��ַ�
	code[1][0]=readchar();//�ӷǿ��еĵ�һ���ַ�����
	for(int len=2;len<8;len++){
		for(int i=0;i<(1<<len)-1;i++){
			int ch=getchar();
			if(ch==EOF)
				return 0;//û�б��� 
			if(ch=='\n' || ch=='\r')
				return 1;//����ͷ������� 
			code[len][i]=ch; 
			
		}
	} 
	return 1;
	
} 
int readchar(){
	while(1){
		int ch=getchar();
		if(ch!='\n' && ch!='\r')
			return ch;//һֱ�����ǻ��з�Ϊֹ 
	}
	
}
int readint(int c){
	int v=0;
	while(c--){
		v=v*2+readchar()-'0';//�����Ʊ�ʮ���� 
	}
	return v;
	
	
} 
