#include<stdio.h>
#include<string.h>
#include <ctype.h>
#define maxn 110
#define maxc 15
struct SNode{
	char SID[maxc];
	int  CID;
	char Name[maxc];
	int Ch,Math,Eng,Pro;
	
}student[maxn];
int Num=0;//当前学生要存放的位置 
void Add(); 
void QR(int symbol);
int Ranking(int score);
void Statistics();
int main(){
	int t=1;
	//打印菜单
	while(t){
		printf("Welcome to Student Performance Managment System (SPMS).\n\n");
		printf("1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistcis\n0 - Exit\n\n");
		//读操作 
		int n;
		scanf("%d",&n); 
		switch(n){
			case 1:
				//添加信息，直到输入0退出 
				Add();
				break;
			case 2:
				QR(1);
				break;
			case 3:
				//查询与移除类似，少替换的步骤 
				QR(0);
				break;
			case 4:
				//Ranking();
				printf("Showing the ranklist hurts students\'self-esteem. Don\'t do that.\n");
				break;
			case 5:
				Statistics();
				break;
			case 0:
				t=0;
				break;
		}
		//break;
		
	}
	return 0;
} 
void Add(){
	char s[maxc],flag1=0,flag2=1;
	printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
	while(1){
		if(flag1)
			printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
		else 
			flag1=1;
		memset(s,0,sizeof(s));
		scanf("%s",s);
		if(s[0]=='0' && strlen(s)==1)
			break;
		//判断SID是否重复,重复则不存入 
		for(int i=0;i<Num;i++){
			if(!strcmp(s,student[i].SID)){
				printf("Duplicated SID.\n"); 
				flag2=0;
				break;
			}
		}
		//存入学生个人信息 
		memcpy(student[Num].SID,s,sizeof(s));
		scanf("%d%s%d%d%d%d",&student[Num].CID,student[Num].Name,&student[Num].Ch,&student[Num].Math,&student[Num].Eng,&student[Num].Pro);
		//printf("%s ",student[Num].SID);
		//printf("%d %s %d %d %d %d\n",student[Num].CID,student[Num].Name,student[Num].Ch,student[Num].Math,student[Num].Eng,student[Num].Pro);
		if(flag2){//如果SID重复下一次输入覆盖此信息 
			Num++;
		}else{
			flag2=1;
			//SID与Name清0，即搜索不到它(其实不用清零) 
			//memset(student[Num].SID,0,sizeof(student[Num].SID));
			//memset(student[Num].Name,0,sizeof(student[Num].Name));
			//printf("%d %s %d %d %d %d\n",student[Num].CID,student[Num].Name,student[Num].Ch,student[Num].Math,student[Num].Eng,student[Num].Pro);
		} 

	}

	
	return;
}
void QR(int symbol){
	//symbol为1是删除，为0是查询 
	char s[maxc],flag=0;
	printf("Please enter SID or name. Enter 0 to finish.\n");	
	while(1){
		int kase=0; 
		if(flag)
			printf("Please enter SID or name. Enter 0 to finish.\n");
		else 
			flag=1;
		memset(s,0,sizeof(s));
		scanf("%s",s);
		if(s[0]=='0' && strlen(s)==1)
			break;
		//判断是SID还是名字（名字中第一个字符为大小字母）
		if(isalpha(s[0])){//是Name 
			for(int i=0;i<Num;){
				if(!strcmp(s,student[i].Name)){
					//printf("%s %d %s %d %d %d %d\n",student[i].SID,student[i].CID,student[i].Name,student[i].Ch,student[i].Math,student[i].Eng,student[i].Pro);
					if(symbol){
						//将Num-1位置的学生信息替代此处的信息,但是有可能Num-1位置处的信息也满足条件 
						student[i]=student[--Num];	
						kase++;
						continue;//此位置再循环一次 
					}else{
						int score=student[i].Ch+student[i].Math+student[i].Eng+student[i].Pro;
						double averge=score/4.0;
						//年级排名
						printf("%d ",Ranking(score));
						//学生信息 
						printf("%s %d %s %d %d %d %d ",student[i].SID,student[i].CID,student[i].Name,student[i].Ch,student[i].Math,student[i].Eng,student[i].Pro);	
						//总分和平均分 
						printf("%d %.2f\n",score,averge);
					}
					//printf("%s %d %s %d %d %d %d\n",student[i].SID,student[i].CID,student[i].Name,student[i].Ch,student[i].Math,student[i].Eng,student[i].Pro);
				}
				i++;
			} 
			if(symbol)
				printf("%d student(s) removed.\n",kase);
		}else{//SID
			for(int i=0;i<Num;i++){
				if(!strcmp(s,student[i].SID)){
					//printf("%s %d %s %d %d %d %d\n",student[i].SID,student[i].CID,student[i].Name,student[i].Ch,student[i].Math,student[i].Eng,student[i].Pro);
					if(symbol){
						//将Num-1位置的学生信息替代此处的信息
						student[i]=student[--Num];	
						kase++;
					}else{
						int score=student[i].Ch+student[i].Math+student[i].Eng+student[i].Pro;
						double averge=score/4.0;
						//年级排名
						printf("%d ",Ranking(score));
						//学生信息 
						printf("%s %d %s %d %d %d %d ",student[i].SID,student[i].CID,student[i].Name,student[i].Ch,student[i].Math,student[i].Eng,student[i].Pro);	
						//总分和平均分 
						printf("%d %.2f\n",score,averge);
					}
					//printf("%s %d %s %d %d %d %d\n",student[i].SID,student[i].CID,student[i].Name,student[i].Ch,student[i].Math,student[i].Eng,student[i].Pro);
					break;
				}
			} 				 
			if(symbol)
				printf("%d student(s) removed.\n",kase);
		}
 
		
	}
	
	
}
int Ranking(int score){
	int Rank=1;
	for(int i=0;i<Num;i++){
		int fen=student[i].Ch+student[i].Math+student[i].Eng+student[i].Pro;
		if(score<fen){
			Rank++;
		}
	}
	return Rank;
}
void Statistics(){
	printf("Please enter class ID, 0 for the whole statistics.\n");
	//读入班级ID，年级ID为0
	int P[10];//记录当前学生的通过的科目次数 
	memset(P,0,sizeof(P));
	int ID,Chs[5],Maths[5],Engs[5],Pros[5];//Chs存总分（0）、通过人数（1）、未通过人数（2）
	memset(Chs,0,sizeof(Chs));
	memset(Maths,0,sizeof(Maths));
	memset(Engs,0,sizeof(Engs));
	memset(Pros,0,sizeof(Pros));
	scanf("%d",&ID); 
	//printf("%d\n",ID);
	if(ID){
		for(int i=0;i<Num;i++){
			if(ID==student[i].CID){ 
				int flag=0;
				//语文 
				Chs[0]+=student[i].Ch;
				if(student[i].Ch>=60){
					Chs[1]++;
					flag++;
				} 
				else 
					Chs[2]++;
				//数学
				Maths[0]+=student[i].Math;
				if(student[i].Math>=60){
					Maths[1]++;
					flag++;
				}
				else 
					Maths[2]++; 
				//英语
				Engs[0]+=student[i].Eng;
				if(student[i].Eng>=60){
					Engs[1]++;
					flag++;	
				}
				else 
					Engs[2]++; 
				//编程
				Pros[0]+=student[i].Pro;
				if(student[i].Pro>=60){
					Pros[1]++;
					flag++;
				}
				else 
					Pros[2]++; 
				
				switch(flag){
					case 0:
						P[0]++;
						break;
					case 1:
						P[1]++;
						break;
					case 2:
						P[2]++;
						break;
					case 3:
						P[3]++;
						break;
					case 4:
						P[4]++;
						break;
					
				}
				
			}
		}
	}else{
		for(int i=0;i<Num;i++){ 
			int flag=0;
			//语文 
			Chs[0]+=student[i].Ch;
			if(student[i].Ch>=60){
				Chs[1]++;
				flag++;
			} 
			else 
				Chs[2]++;
			//数学
			Maths[0]+=student[i].Math;
			if(student[i].Math>=60){
				Maths[1]++;
				flag++;
			}
			else 
				Maths[2]++; 
			//英语
			Engs[0]+=student[i].Eng;
			if(student[i].Eng>=60){
				Engs[1]++;
				flag++;	
			}
			else 
				Engs[2]++; 
			//编程
			Pros[0]+=student[i].Pro;
			if(student[i].Pro>=60){
				Pros[1]++;
				flag++;
			}
			else 
				Pros[2]++; 
			
			switch(flag){
				case 0:
					P[0]++;
					break;
				case 1:
					P[1]++;
					break;
				case 2:
					P[2]++;
					break;
				case 3:
					P[3]++;
					break;
				case 4:
					P[4]++;
					break;
				
			}
			
		}
			
	
	}
	//打印 
	//语文 
	printf("Chinese\n");
	printf("Average Score: %.2f\n",(double)Chs[0]/(Chs[1]+Chs[2]));
	printf("Number of passed students: %d\n",Chs[1]);
	printf("Number of failed students: %d\n\n",Chs[2]);
	//数学 
	printf("Mathematics\n");
	printf("Average Score: %.2f\n",(double)Maths[0]/(Maths[1]+Maths[2]));
	printf("Number of passed students: %d\n",Maths[1]);
	printf("Number of failed students: %d\n\n",Maths[2]);
	//英语 
	printf("English\n");
	printf("Average Score: %.2f\n",(double)Engs[0]/(Engs[1]+Engs[2]));
	printf("Number of passed students: %d\n",Engs[1]);
	printf("Number of failed students: %d\n\n",Engs[2]); 
	//编程
 	printf("Programming\n");
	printf("Average Score: %.2f\n",(double)Pros[0]/(Pros[1]+Pros[2]));
	printf("Number of passed students: %d\n",Pros[1]);
	printf("Number of failed students: %d\n\n",Pros[2]); 
	//总
	printf("Overall:\n");
	printf("Number of student who passed all subjects: %d\n",P[4]);
	printf("Number of student who passed 3 or more subjects: %d\n",P[3]+P[4]);
	printf("Number of student who passed 2 or more subjects: %d\n",P[2]+P[3]+P[4]);
	printf("Number of student who passed 1 or more subjects: %d\n",P[1]+P[2]+P[3]+P[4]);
	printf("Number of student who failed all subjects: %d\n\n",P[0]);
	
	
}
