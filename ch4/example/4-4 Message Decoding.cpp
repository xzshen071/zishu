#include<stdio.h>
#include<string.h>
int readint(int c);
int readcodes();
int readchar();
int code[8][1<<8];//格式为code[len][v]，len为编码长度，v为对应的十进制值（范围：0~(1<<len)-2），存储此编码的字符 
int main(){
	//读编码头,无法读取更多的编码头时退出 
	while(readcodes()){
		while(1){
			//读前3个二进制数字，并转换为十进制 
			int len=readint(3);
			if(len==0)//为0，则编码结束 
				break;
			//printf("len=&d\n",len); 
			while(1){//不为0 
				int v=readint(len);
			//printf("v=%d\n",v);
				if(v==(1<<len)-1)//如果是len个1则小结结束,len=2时，结束条件是等于3 
					break; 
				putchar(code[len][v]);
				
				
			}
			
		}
		putchar('\n');//一次编码结束 
		
	} 
	
	
	
	return 0;
} 
int readcodes(){
	//初始化编码数组 
	memset(code,0,sizeof(code));
	//读第一个非空行的字符
	code[1][0]=readchar();//从非空行的第一个字符读起
	for(int len=2;len<8;len++){
		for(int i=0;i<(1<<len)-1;i++){
			int ch=getchar();
			if(ch==EOF)
				return 0;//没有编码 
			if(ch=='\n' || ch=='\r')
				return 1;//编码头输入结束 
			code[len][i]=ch; 
			
		}
	} 
	return 1;
	
} 
int readchar(){
	while(1){
		int ch=getchar();
		if(ch!='\n' && ch!='\r')
			return ch;//一直读到非换行符为止 
	}
	
}
int readint(int c){
	int v=0;
	while(c--){
		v=v*2+readchar()-'0';//二进制变十进制 
	}
	return v;
	
	
} 
