//���������
#include<cstdio>
#include<algorithm> 
//#include<cstring>
using namespace std;
const int maxn=10000;

int main(){
	int n,q,a[maxn],kase=0;
	while(scanf("%d%d",&n,&q)==2 && n!=0){
		printf("CASE# %d:\n",++kase);
		//������
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			
		} 
		/* 
		1������,ʡ����compare������sort���е���Ĭ�ϵĴ�С��������������ż������ĺ�����
		2��ort�������Զ��������������򣬲�һ�����������͡���Ϊ����ģ�麯���� 
		3����������������Ҫ���塰С�ڡ�������������������д���һ����С�ڡ���������sort(v.begin().v.end())���ã���ͨ�����sort(a,a+n)���ã� 
		4��������Ԫ�ؿ��Է��������Ҳ���Է���vector� 
		*/
		sort(a,a+n);
		//ѯ��
		while(q--){
			int x;
			scanf("%d",&x);
			//����������a����x��lower_bound�������ǲ��ҡ����ڻ��ߵ���x�ĵ�һ��λ�á��� 
			int p=lower_bound(a,a+n,x)-a;//ע��Ҫ��ȥa 
			if(a[p]==x)
				printf("%d found at %d\n",x,p+1);//ע��pҪ��1 
			else 
				printf("%d not found\n",x); 
			
		} 
			
		
	}
	
	/*
	//����
	//��char������
	char s[maxn];
	scanf("%s",s);
	int len=strlen(s);
	sort(s,s+len); 
	printf("%s",s);
	*/
	
	return 0;
}
