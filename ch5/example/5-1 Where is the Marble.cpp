//排序和索引
#include<cstdio>
#include<algorithm> 
//#include<cstring>
using namespace std;
const int maxn=10000;

int main(){
	int n,q,a[maxn],kase=0;
	while(scanf("%d%d",&n,&q)==2 && n!=0){
		printf("CASE# %d:\n",++kase);
		//读数据
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			
		} 
		/* 
		1、排序,省略了compare函数，sort进行的是默认的大小排序，有特殊情况才加入额外的函数；
		2、ort函数可以对任意对象进行排序，不一定是内置类型。因为它是模块函数； 
		3、若如此这个类型需要定义“小于”运算符，或者在排序中传入一个“小于”函数，用sort(v.begin().v.end())调用，普通情况用sort(a,a+n)调用； 
		4、待排序元素可以放在数组里，也可以放在vector里。 
		*/
		sort(a,a+n);
		//询问
		while(q--){
			int x;
			scanf("%d",&x);
			//在已排数组a中找x，lower_bound的作用是查找“大于或者等于x的第一个位置”。 
			int p=lower_bound(a,a+n,x)-a;//注意要减去a 
			if(a[p]==x)
				printf("%d found at %d\n",x,p+1);//注意p要加1 
			else 
				printf("%d not found\n",x); 
			
		} 
			
		
	}
	
	/*
	//测试
	//排char型数据
	char s[maxn];
	scanf("%s",s);
	int len=strlen(s);
	sort(s,s+len); 
	printf("%s",s);
	*/
	
	return 0;
}
