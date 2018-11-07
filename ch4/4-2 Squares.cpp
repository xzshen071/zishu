#include<stdio.h>
#include<string.h>
#define maxn 15 
int n;
int h[maxn][maxn],v[maxn][maxn];
int Num[maxn];//��߳�Ϊx�������θ��� 
char readchar(); 
void JudgeSquares(int k,int z);
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	
	int symbol=0,f=1;
	//��С�ڵ�Ľ���
	while(scanf("%d",&n)==1){
		if(f) f=0;
		else printf("\n");
		//��ʼ�� 
		memset(h,0,sizeof(h));
		memset(v,0,sizeof(v));
		memset(Num,0,sizeof(Num));
		//������
		int m;
		scanf("%d",&m);
		while(m--){
			char c;
			//�Ӳ��ǻ��з���ʼ�� 
			c=readchar();
			//printf("%c\n",c); 
			int i,j;
			if(c=='H'){//�� 
				scanf("%d%d",&i,&j);
				//printf("%d %d\n",i,j);
				h[i][j]=1; 
			}else{//�� 
				scanf("%d%d",&j,&i);
				//printf("%d %d\n",i,j);
				v[i][j]=1;	
			} 
		} 
		/*
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				printf("%d ",h[i][j]);
			printf("\n");
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				printf("%d ",v[i][j]);
			printf("\n");
		}
		*/
		//�ж��Ƿ��γ�������
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				//�жϴ˵��Ƿ����ұߺ��±� 
				if(h[i][j]==1 && v[i][j]==1){
					//�ж��ɴ˵㹹�ɵ������� 
					JudgeSquares(i,j);
				}
			}
		} 
		//��ӡ
		if(symbol)
			printf("**********************************\n\n");
		int flag=1;
		printf("Problem #%d\n\n",++symbol);
		for(int i=1;i<=n;i++){
			if(Num[i]!=0){
				printf("%d square (s) of size %d\n",Num[i],i);
				flag=0;
			}
		}
		if(flag)
			printf("No completed squares can be found.\n");
	} 
	return 0;
} 
char readchar(){
	while(1){
		char ch=getchar();
		if(ch!='\n' && ch!='\r')
			return ch;			
	}
} 
void JudgeSquares(int hang,int lie){
	//printf("%d %d\n",hang,lie);
	//�ҵ����Һ�����û�бߵ����
	int maxh,maxv;
	maxh=maxv=0;
	//�Ӵ˵��з������������м����ߣ������������� 
	for(int i=hang;i<n;i++){
		if(v[i][lie]==1){
			maxv++;
		}else break; 
	}
	//�Ӵ˵��з������������м����ߣ������������� 
	for(int j=lie;j<n;j++){
		if(h[hang][j]==1){
			maxh++;
		}else break;
	}
	//printf("%d %d\n",maxh,maxv);
	
	//��ñ߳��Ŀ�����
	int maxb;//��������α߳�  
	if(maxh<maxv)
		maxb=maxh;
	else 
		maxb=maxv;
	//�������ܵı߳���ʼ 
	for(int i=maxb;i>0;i--){
		int flag1=1;
		//�����߳�������������� 
		for(int j=lie;j<lie+i;j++){
			//printf("%d %d\n",hang+i,j);
			if(h[hang+i][j]==0){
				flag1=0;
				break;
			}
		}
		if(flag1){				//���˱߳����� 
			//����lie+i 
			//printf("%d\n",i);
			int flag2=1;
			//�����߳�������������� 
			for(int k=hang;k<hang+i;k++){
			//	printf("%d %d\n",k,lie+i);
				if(v[k][lie+i]==0){
					flag2=0;
					break;
				}
				
			}
			if(flag2)
				Num[i]++;		//��˱߳��������θ��� 
		}
	} 
	/*
	for(int i=1;i<=n;i++)
		printf("%d ",Num[i]);
	printf("\n");    
	*/
	
}
