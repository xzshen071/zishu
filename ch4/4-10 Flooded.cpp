#include<stdio.h>
#define maxn 900
int ge[maxn];
void Sort_Int(int a[],int n); 
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout); 
	int n,m,kase=0;
	//���������ģ 
	while(scanf("%d%d",&n,&m)==2 && n!=0){
		//��ÿ������ĺ��θ߶�
		for(int i=0;i<n*m;i++)
			scanf("%d",&ge[i]);		
		//����������ˮ�������
		int V;
		scanf("%d",&V);
		//��������д�С��������
		Sort_Int(ge,n*m);
		/*
		for(int i=0;i<n*m;i++){
			printf("%d ",ge[i]);
		}
		printf("\n");
		*/
		//�������ˮλ�ĺ��θ߶ȼ��ж��ٰٷֱȵ�������ˮ
		double percent,h;
		int num=0;//����סլ�ĸ��� 
		for(int i=0;i<n*m;i++){
			num++;
			//�����
			V+=ge[i]*100;
			//ƽ�����θ߶�
			h=(double)V/(100*(i+1)); 
			if(h<=ge[i+1])
				break;
			
		} 
		printf("Region %d\n",++kase);
		printf("Water level is %.2f meters.\n",h);
		printf("%.2f percent of the region is under water.\n\n",(double)num/(n*m)*100);
		
	}
	
	
	return 0;
} 
void Sort_Int(int a[],int n){
    int i,j;
    for(i=1;i<n;i++)
    {
        int temp=a[i];
        for(j=i;j>0&&a[j-1]>temp;--j)
            a[j]=a[j-1];
        a[j]=temp;
    }
    
}
