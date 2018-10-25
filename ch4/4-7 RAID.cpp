#include<stdio.h>
#include<string.h>
#include<math.h>
int d,s,b;
int num_1[500];//存每列'1'的个数 
char data[10][500]; 
char ch_type;
char table[20]="0123456789ABCDEF"; 
int is_legal();
char readchar();
void Print_data();
int main(){
	//读入d(行数)，s(比特数)，b(列数)
	int kase=0;
	while(scanf("%d",&d)==1 && d!=0){
		scanf("%d%d",&s,&b);
		//读校验种类
		ch_type=readchar(); 
		//printf("%c\n",ch_type);
		//读数据
		for(int i=0;i<d;i++){
			scanf("%s",data[i]);
		}
		/*
		for(int i=0;i<d;i++){
			printf("%s\n",data[i]);
		}
		*/
		//磁盘非法：列方向超过1组xx，列方向校验错误
		if(is_legal()==0){
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
//磁盘非法：列方向超过1组xx，列方向校验错误
int is_legal(){ 
	memset(num_1,0,sizeof(num_1));
	//每比特列，先判断某列方向超过1组xx,存每列‘1’的个数 
	for(int j=0;j<s*b;j++){
		int num_x=0; 
		for(int i=0;i<d;i++){
			//一列方向超过1组xx
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
	printf("\n");
	//改变x的值，然后判断是否列方向校验错误 
	for(int j=0;j<s*b;j++){
		for(int i=0;i<d;i++){
			//改变x的值 
			if(data[i][j]=='x'){
				if(ch_type=='E'){
					if(num_1[j]%2==0)//偶数 
						data[i][j]='0'; 
					else{
						data[i][j]='1'; 
						num_1[j]++; 
					}
				}else{
					if(num_1[j]%2==0){//偶数 
						data[i][j]='1'; 
						num_1[j]++; 
					}else
						data[i][j]='0'; 
				} 
			}
				
		}
		if(ch_type=='E' && num_1[j]%2!=0){//偶：每一列一'1'的个数为偶数 
			//printf("2\n");
			return 0;	
		}else if(ch_type=='O' && num_1[j]%2==0){//奇:每一列一'1'的个数为奇数 
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
//打印数据 
void Print_data(){
	int Judge_x=0,Judge_y=0; 
	//注意校验位
	int flag=4,sum=0;
	for(int j=0;j<b;j++){
		for(int i=0;i<d;i++){
			for(int k=0;k<s;k++){
				//忽视校验位 
				if(i==Judge_x && j==Judge_y){
					//printf("%d %d\n",i,j);
					Judge_x++;
					Judge_y=(Judge_y+1)%d;
					break;
				}
				//有没有4位 
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
	}else
		printf("%c\n",table[sum]);
	
	
}
