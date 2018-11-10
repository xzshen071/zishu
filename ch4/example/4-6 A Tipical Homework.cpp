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
int Num=0;//��ǰѧ��Ҫ��ŵ�λ�� 
void Add(); 
void QR(int symbol);
int Ranking(int score);
void Statistics();
int main(){
	int t=1;
	//��ӡ�˵�
	while(t){
		printf("Welcome to Student Performance Managment System (SPMS).\n\n");
		printf("1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistcis\n0 - Exit\n\n");
		//������ 
		int n;
		scanf("%d",&n); 
		switch(n){
			case 1:
				//�����Ϣ��ֱ������0�˳� 
				Add();
				break;
			case 2:
				QR(1);
				break;
			case 3:
				//��ѯ���Ƴ����ƣ����滻�Ĳ��� 
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
		//�ж�SID�Ƿ��ظ�,�ظ��򲻴��� 
		for(int i=0;i<Num;i++){
			if(!strcmp(s,student[i].SID)){
				printf("Duplicated SID.\n"); 
				flag2=0;
				break;
			}
		}
		//����ѧ��������Ϣ 
		memcpy(student[Num].SID,s,sizeof(s));
		scanf("%d%s%d%d%d%d",&student[Num].CID,student[Num].Name,&student[Num].Ch,&student[Num].Math,&student[Num].Eng,&student[Num].Pro);
		//printf("%s ",student[Num].SID);
		//printf("%d %s %d %d %d %d\n",student[Num].CID,student[Num].Name,student[Num].Ch,student[Num].Math,student[Num].Eng,student[Num].Pro);
		if(flag2){//���SID�ظ���һ�����븲�Ǵ���Ϣ 
			Num++;
		}else{
			flag2=1;
			//SID��Name��0��������������(��ʵ��������) 
			//memset(student[Num].SID,0,sizeof(student[Num].SID));
			//memset(student[Num].Name,0,sizeof(student[Num].Name));
			//printf("%d %s %d %d %d %d\n",student[Num].CID,student[Num].Name,student[Num].Ch,student[Num].Math,student[Num].Eng,student[Num].Pro);
		} 

	}

	
	return;
}
void QR(int symbol){
	//symbolΪ1��ɾ����Ϊ0�ǲ�ѯ 
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
		//�ж���SID�������֣������е�һ���ַ�Ϊ��С��ĸ��
		if(isalpha(s[0])){//��Name 
			for(int i=0;i<Num;){
				if(!strcmp(s,student[i].Name)){
					//printf("%s %d %s %d %d %d %d\n",student[i].SID,student[i].CID,student[i].Name,student[i].Ch,student[i].Math,student[i].Eng,student[i].Pro);
					if(symbol){
						//��Num-1λ�õ�ѧ����Ϣ����˴�����Ϣ,�����п���Num-1λ�ô�����ϢҲ�������� 
						student[i]=student[--Num];	
						kase++;
						continue;//��λ����ѭ��һ�� 
					}else{
						int score=student[i].Ch+student[i].Math+student[i].Eng+student[i].Pro;
						double averge=score/4.0;
						//�꼶����
						printf("%d ",Ranking(score));
						//ѧ����Ϣ 
						printf("%s %d %s %d %d %d %d ",student[i].SID,student[i].CID,student[i].Name,student[i].Ch,student[i].Math,student[i].Eng,student[i].Pro);	
						//�ֺܷ�ƽ���� 
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
						//��Num-1λ�õ�ѧ����Ϣ����˴�����Ϣ
						student[i]=student[--Num];	
						kase++;
					}else{
						int score=student[i].Ch+student[i].Math+student[i].Eng+student[i].Pro;
						double averge=score/4.0;
						//�꼶����
						printf("%d ",Ranking(score));
						//ѧ����Ϣ 
						printf("%s %d %s %d %d %d %d ",student[i].SID,student[i].CID,student[i].Name,student[i].Ch,student[i].Math,student[i].Eng,student[i].Pro);	
						//�ֺܷ�ƽ���� 
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
	//����༶ID���꼶IDΪ0
	int P[10];//��¼��ǰѧ����ͨ���Ŀ�Ŀ���� 
	memset(P,0,sizeof(P));
	int ID,Chs[5],Maths[5],Engs[5],Pros[5];//Chs���ܷ֣�0����ͨ��������1����δͨ��������2��
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
				//���� 
				Chs[0]+=student[i].Ch;
				if(student[i].Ch>=60){
					Chs[1]++;
					flag++;
				} 
				else 
					Chs[2]++;
				//��ѧ
				Maths[0]+=student[i].Math;
				if(student[i].Math>=60){
					Maths[1]++;
					flag++;
				}
				else 
					Maths[2]++; 
				//Ӣ��
				Engs[0]+=student[i].Eng;
				if(student[i].Eng>=60){
					Engs[1]++;
					flag++;	
				}
				else 
					Engs[2]++; 
				//���
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
			//���� 
			Chs[0]+=student[i].Ch;
			if(student[i].Ch>=60){
				Chs[1]++;
				flag++;
			} 
			else 
				Chs[2]++;
			//��ѧ
			Maths[0]+=student[i].Math;
			if(student[i].Math>=60){
				Maths[1]++;
				flag++;
			}
			else 
				Maths[2]++; 
			//Ӣ��
			Engs[0]+=student[i].Eng;
			if(student[i].Eng>=60){
				Engs[1]++;
				flag++;	
			}
			else 
				Engs[2]++; 
			//���
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
	//��ӡ 
	//���� 
	printf("Chinese\n");
	printf("Average Score: %.2f\n",(double)Chs[0]/(Chs[1]+Chs[2]));
	printf("Number of passed students: %d\n",Chs[1]);
	printf("Number of failed students: %d\n\n",Chs[2]);
	//��ѧ 
	printf("Mathematics\n");
	printf("Average Score: %.2f\n",(double)Maths[0]/(Maths[1]+Maths[2]));
	printf("Number of passed students: %d\n",Maths[1]);
	printf("Number of failed students: %d\n\n",Maths[2]);
	//Ӣ�� 
	printf("English\n");
	printf("Average Score: %.2f\n",(double)Engs[0]/(Engs[1]+Engs[2]));
	printf("Number of passed students: %d\n",Engs[1]);
	printf("Number of failed students: %d\n\n",Engs[2]); 
	//���
 	printf("Programming\n");
	printf("Average Score: %.2f\n",(double)Pros[0]/(Pros[1]+Pros[2]));
	printf("Number of passed students: %d\n",Pros[1]);
	printf("Number of failed students: %d\n\n",Pros[2]); 
	//��
	printf("Overall:\n");
	printf("Number of student who passed all subjects: %d\n",P[4]);
	printf("Number of student who passed 3 or more subjects: %d\n",P[3]+P[4]);
	printf("Number of student who passed 2 or more subjects: %d\n",P[2]+P[3]+P[4]);
	printf("Number of student who passed 1 or more subjects: %d\n",P[1]+P[2]+P[3]+P[4]);
	printf("Number of student who failed all subjects: %d\n\n",P[0]);
	
	
}
