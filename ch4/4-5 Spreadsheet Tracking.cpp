#include<stdio.h>
#include<string.h>
#define maxn 60
int a[maxn][maxn];
int r,c;
int lie;//����������֤�䲻�� 
char s[5];
void Delete(char c);
void Insert(char c,int num);
void Find(int h,int l);
void Insertion_Sort(int p[],int n);
int main(){
	//���ܵ��ӱ���������������������� 
	int t,kase=0;
	while(scanf("%d%d%d",&r,&c,&t)==3 && r!=0){
		//��ʼ�����ӱ�
		lie=c;
		memset(a,0,sizeof(a));
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				a[i][j]=(i-1)*c+j;

			}
		}
		//printf("%d",t);
		//���в���
		while(t--){
			//������ 
			memset(s,0,sizeof(s));
			scanf("%s",s);
			int n,b;
			switch(s[0]){
				case 'D':
					//if(s[1]=='R')
						//printf("1");
					//else
						//printf("2");
						
					//ɾ���л���  
					Delete(s[1]);
					break;
				case 'I':
					//if(s[1]=='R')
						//printf("3");
					//else
						//printf("4");
						
					//�����л���
					Insert(s[1],1); 				
					break; 
				case 'E':
					//printf("5");
					
					//������Ԫ��
					int r1,c1,r2,c2;
					scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
					int tmp=a[r1][c1];
					a[r1][c1]=a[r2][c2];
					a[r2][c2]=tmp;
					break; 
					
			}
		}
			//����ѯ��
			int t2;
			scanf("%d",&t2);
			printf("Spreadsheet #%d\n",++kase);
			while(t2--) {
				//����Ԫ��
				int r3,c3; 
				scanf("%d%d",&r3,&c3);
				//�ҵ���ʱ��λ��λ�ò���ӡ��� 
				printf("Cell data in (%d,%d) ",r3,c3);
				Find(r3,c3); 
				
			}
			 
	
		
	}	
	return 0;
} 
//ɾ���л����� 
void Delete(char c1){
	//��Ҫ�������л��У��������ǽ��дӴ�С������
	int t,p[maxn];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
		scanf("%d",&p[i]);	
	//����
	Insertion_Sort(p,t);	
	
	for(int k=t-1;k>=0;k--){
		//�� 
		if(c1=='R'){
			for(int j=1;j<=c;j++){
				for(int i=p[k];i<=r;i++){
					a[i][j]=a[i+1][j];
				}
			}
			r--;	
		}else{//�� 
			for(int i=1;i<=r;i++){
				for(int j=p[k];j<=c;j++){
					a[i][j]=a[i][j+1];
				}
			}
			c--;
		}
			
		
	}
	/*
	//���� 
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			printf("%d	",a[i][j]);
		}
		printf("\n");
	}
	*/
	
}
//�����л�����
void Insert(char c1,int num){
	//��Ҫ�������л��У��������ǽ��дӴ�С������
	int t,p[maxn];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
		scanf("%d",&p[i]);	
	//����
	Insertion_Sort(p,t);	
	
	//�� 
	for(int k=t-1;k>=0;k--){
		if(c1=='R'){
			for(int i=r;i>=p[k];i--){
				for(int j=1;j<=c;j++){
					a[i+1][j]=a[i][j];
				}
			}
			
			for(int j=1;j<=c;j++)
				a[p[k]][j]=0;
			r++;
		}else{//�� 
			for(int j=c;j>=p[k];j--){
				for(int i=1;i<=r;i++){
					a[i][j+1]=a[i][j];
				}
			}
			
			for(int i=1;i<=r;i++)
				a[i][p[k]]=0;
			c++;
		}
		
	}
	
	/*
	//���� 
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			printf("%d	",a[i][j]);
		}
		printf("\n");
	}
	*/
	
}
void Find(int h,int l){
	int tmp=(h-1)*lie+l;
	//printf("%d\n",tmp);
	
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(tmp==a[i][j]){
				printf("moved to (%d,%d)\n",i,j);
				return;
			}
		}
	}
	printf("GONE\n");
	return;
	
	
} 
void Insertion_Sort(int p[],int n){
    int i,j;
    for(i=1;i<n;i++)
    {
        int temp=p[i];
        for(j=i;j>0&&p[j-1]>temp;--j)
            p[j]=p[j-1];
        p[j]=temp;
    }
    
}

