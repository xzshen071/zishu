#include<stdio.h>
#include<string.h>//��֤memset���������ã��˺��������������г�ʼ�� 
#include<ctype.h>//��֤isalpha������ʹ�ã����ƵĻ���idigit��isprint 
/*
//������� 
//#define maxn 100//Ӧ�������������Դ��������Ŀ��˵maxn<=100 
//#define maxn 1000000//�������鶨������������������
#define maxn 105 
int a[maxn];//���鶨����������棬ֻ�з�����������a�ſ��Կ��úܴ� 
*/
/*
//�������� 
#define maxn 1005
int a[maxn];
*/
/*
//�������� 
#define maxn 10
int a[maxn][maxn]; 
*/
/*
//MERTYU 
char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";//���峣�����飬���ó����������ڼ򻯴��룬б����Ҫ��"\\"��ʾ
*/ 
/*
//���Ĵ� 
const char* rev="A   3  HIL JM O   2TUVWXY51SE Z  8 ";//ΪɶҪ�����ָ�루��¼�׵�ַ�����鴫���൱�ڴ���������׵�ַ��,�������ָ����仰Ҳû�� 
const char* msg[]={"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};//�������ָ���򱨴�
char r(char ch){//�Ӻ��� 
	if(isalpha(ch))//isalpha(ch)�����ж�ch�Ƿ�����ĸ 
		return rev[ch-'A'];//'A'�������0 
	else//������ 
		return rev[ch-'0'+25];//ch-'0'��������ֱ���������26����ĸ֮��ų��֣������±��0��ʼ���� 
}
*/
/*
//��������Ϸ����ʾ 
#define maxn 1050
*/
/*
//����Ԫ 
#define maxn 100005
*/
/* 
//��״���� 
#define maxn 105
//��״���ı�ʾ��p�Ƿ�ȱ�ʾ��q���ֵ���С 
int less(const char*s,int p,int q){
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[(p+i)%n]!=s[(q+i)%n])
			return s[(p+i)%n] < s[(q+i)%n];//p<q�Ļ�����1 
	}
	return 0;//��� 
}
*/ 
int ans[maxn];
int main(){
/* 
	//�������
	int x,n=0;
	//int a[maxn];//���鶨�������棬�ռ俪��̫�󣬼�maxn������쳣�˳� 
	while(scanf("%d",&x)==1)
		a[n++]=x;//���һ����λa[n-1] 
	for(int i=n-1;i>0;i--)
		printf("%d ",a[i]);
	printf("%d\n",a[0]);//��֤���һλ���� 
*/
	
/*	
	//��������
	int k,n,count=0;
	//int frist=1;
	scanf("%d%d",&n,&k);
	//�����ʼ��
	//for(int s=1;s<=n;s++)
		//a[s]=-1; 
	
	memset(a,0,sizeof(a));//������a�е�����Ԫ�����㣬�򻯳�ʼ�� 
	for(int i=1;i<=k;i++)//�� 
		for(int j=1;j<=n;j++){//�� 
			if(i*j<=n) 
				a[i*j]=-a[i*j];
			else 
				break;
				
			//or 
			//if(j%i == 0)//j��i�ı��� 
				//a[j]=!a[j];//!0=1,!1=0
				
		}
	for(int i=1;i<=n;i++){
		if(count){
			printf(" ");
			count=0;
		}
	
		if(a[i]==1){
			printf("%d",i);
			count=1;
		}
		
		//or
		//if(a[i]){
			//if(frist)//��֤���������ʽ������һ����Ҫ�ո񣬺������Ҫ��һ�� 
				//frist=0;
			//else
				//printf(" ");
			//printf("%d",i);
		//} 
		
	}
	printf("\n");
		 
*/

/* 
	//����memcpy��memset�����Ͷ����鸳ֵ����� 
	int b[6]={1},k=5;
	int a[10]={1,2,23,3,33,3,3,44,4};//���������鸳ֵ�����Ƕ����ʱ��ֵ�����ȶ���a[10],��a[10]={...}������ 
	//memset�����ǽ�һ���������㣬������ʹ����ȫ��Ԫ�ص���ͬһ���� 
	//memset(a,0,sizeof(a));
	
	//memcpy(b,a,sizeif(int)*k),b�ǲ�������Ŀ���ǽ�����a����k��Ԫ�ص�����b������a��b��ҪΪ�������飬���Ǹ����ͽ�int�ĳ�double
	//���︴��k��Ԫ��ָ���Ǹ���ǰk��Ԫ��	 
	memcpy(b,a,sizeof(int)*5);	
	for(int i=0;i<6;i++)
		printf("%d ",b[i]);//����Ҳ������ǣ�����1�����������0����0=1 
		
	//�� int a[maxn]={0};����� 
	//�����ʼ���б��е�Ԫ�ظ���С��ָ�������鳤��ʱ�������Ԫ�ز���Ĭ��ֵ�������Ĭ��ֵָ����0�������㲻�����鸳ֵ����ֵ��������ġ� 
*/

/* 
	//��������
	//д��Ŀ���˿������ɣ���Ӧ��ע���ж�������˵��������˼·
	int num=1,n,x=0,y;//y=n-1;//y���︳ֵ����nû��ֵ 
	scanf("%d",&n);
	//��ʼ����ά����
	memset(a,0,sizeof(a));
	a[x][y=n-1]=num;//c�����м����﷨����ǰ���Ǳ��ִ���Ŀɶ��� 
	
	while(num<n*n){
		
		while(x+1<n && !a[x+1][y] )//ע����Щ�ж�������ָ����������һ��ֵ������ 
			a[++x][y]=++num; 
		while(y-1>=0 && !a[x][y-1])
			a[x][--y]=++num;
		while(x-1>=0 && !a[x-1][y])
			a[--x][y]=++num;
		while(y+1<n & !a[x][y+1])
			a[x][++y]=++num;

		//!a[++x][y]Ϊʲô��
		//д����Ӧ�ñ���һ��ԭ�����ж����ƶ����������������������˻�����������������������һ�����⣺�����˵���Ҳ�ƶ��ˣ�Ҳû���˻����� 
		//������γ����Ǵ��	
		while(x+1<n && !a[++x][y] ){
			a[x][y]=++num; 
			printf("%d\n",a[x][y]);
		} 
		while(y-1>=0 && !a[x][--y]){
			a[x][y]=++num;
			printf("%d\n",a[x][y]);	
		}
		while(x-1>=0 && !a[--x][y]){
			a[x][y]=++num;
			printf("%d\n",a[x][y]);	
		}
		while(y+1<n & !a[x][++y]){
			a[x][y]=++num;
			printf("%d\n",a[x][y]);
		}
			
				
	} 
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d\t",a[i][j]);
			
			
		} 
	printf("\n");	
	}	
*/ 
		
/* 
	//��ʽ���� 
	//α���루д����ʱ������дα���룬�ٴ����������ƴ���ľ������ݣ� 
	char s[20];//C�������ַ�����char��ʾ����ʵ�ʴ洢�����ַ���ASIIC�룬���﷨�Ͽ��԰��ַ�����int��ʹ�� 
	int count=0;
	scanf("%s",s);//��scanf("%d",&n)��ͬ��û��&�������������Ʋ������ո�TAB�ͻس�����scanf("%s",s)��������ݴ����ַ�����s�������հ��ַ���ͣ����
	//Ҳ����scanf("%s",s[i])�����ʽ����ʾ��ȡ��i���ַ������Լ�����һ�� 
	for(int abc=111;abc<=999;abc++)///�������е�abc����λ������de����λ���� 
		for(int de=11;de<=99;de++){
			if(abc*de�ǺϷ�����ʽ){ 
				printf("<%d>\n",++count);
				��ӡabc*de����ʽ�����Ŀ��� 
			}
		printf("The number of solutions = %d\n",count); 
		} 
	*/ 
	/* 
	//�˳�����Ҫ���������
	//1������û�пո���ν����ַֿ�->���ַ�������棬�ַ��������﷨��Ҳ���Ե���int��ʹ��,�ַ����൱���ַ����� 
	//2����ô�ж�abc,de,adc*e,abc*d,abc*de�Ƿ�����������ּ�����->strchr��������һ���ַ����в��ҵ����ַ������ɹ�����NULL�� 
	//3�������ʽ->%5d... 
	char s[20],buf[99];
	int count=0;
	scanf("%s",s);//���ַ��������ַ������У�%sָ�����ַ������� 
	//for(int i=0;i<strlen(s);i++)
		//printf("%c",s[i]);//��������ַ���ʽ������%c 
	
	for(int abc=111;abc<=999;abc++)///�������е�abc����λ������de����λ���� 
		for(int de=11;de<=99;de++){
			int x=abc*(de%10),y=abc*(de/10),z=abc*de;
			//sprintf��������ַ������ַ����飩����printf���������Ļ����fprintf��������ļ������ƣ� 
			sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);//��abc,de,adc*e,abc*d,abc*de�����ַ�����buf��,%d֮��û�пո�����Ϊ���У��ո��Ҳ�ᱻ����buf�� 
			//���������sprintf(buf,"�ַ���"); ��˼�ǽ�"..."����ַ�������buf�У� 
			int ok=1;
			for(int i=0;i<strlen(buf);i++){//strlen�������ص���\0ǰ�ַ��ĸ�����������123������\0����4���ַ����˺�������3
				if(strchr(s,buf[i])==NULL)
					ok=0;
			}
			if(ok){ 
				printf("<%d>\n",++count);
				//��ӡabc*de����ʽ�����Ŀ��У������abc��de������
				//����һ�����⣬Ҫ����˳���5λ��ô�죿��������ⲻ���� 
				printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);//�����%5d,����ʾ����5λ����ӡ������5��ǰ�油�ո�%03d��߲�0 
			}
		} 
	printf("The number of solutions = %d\n",count); 
*/ 
	
/* 
	//strchqr��ʾ
	const char str[] = "http://www.runoob.com6666666";
   	const char ch = '.';
   	char *ret;

  	ret = strchr(str, ch);//strchr�ķ���ֵ����str�е�һ�γ���ch��λ�ã�ָ�룩���������ָ����ֵ��δ�ҵ�������NULL 

  	printf("|%c| ֮����ַ����� - |%s|\n", ch, ret); 
	//��ӡ�����|.| ֮����ַ����� - |.runoob.com6666666|
*/
	
/* 
	//++��--ʵ�� 
	int count=0;
	printf("%d %d %d",count++,count++,count++);
	//��count=0ʱ����ӡ��2 1 0 
	printf("%d %d %d",++count,++count,++count);
	//��count=0ʱ����ӡ��3 3 3 
	count=count++;
	printf("%d",count);
	//��count=0ʱ����ӡ��0
	//���ϱ�������ʵ����������һ���Ĺ�ϵ
	//˵��һ�㣺ƽʱӦ�ñ��������ĳ��򣬼�++��--,+=����������ÿ��������ֻ����һ�Σ����ұ��޸ĵı���Ҳֻ����һ��
*/

	//������Ŀѡ��	
/* 
	//TeX�е�����
	//Ҫ���������
	//1��������ַ����洢��ʽ->������scanf,���һ���ַ�һ���ַ����жϣ�Ҳ�Ͳ������ַ��������д洢�����ַ�����ӡ��ֱ�Ӵ�ӡ��ok 
	//2����ô�ж��ǲ���˫���ţ�����Ҫע������˫���ţ�������˫���� ->getchar()��ñ�׼������ַ�����һ������ж��������� 
	int c,flag=1;
	//ע�⣺��ʹ��getchar��fgetcʱ����д�������ϵͳ��صĳ��򣬼���ͬ�Ĳ���ϵͳ�Ļس����з��ǲ�һ�µģ�windows��'\r'��'\n'��Linux��'\n��MacOS��'\r' 
	while((c=getchar())!=EOF){//getchar�ķ���ֵ��int(��Ϊ��һ���������EOF��������char)��getchar()=fgetc(stdin),��fgetc(fin)���Դ��ļ�����һ���ַ�
		if(c=='"'){//��סc��int�ͣ����﷨��char�Ϳ��Ե���int�ʹ���'"'����ֵ����"��ASIIC�� 
			printf("%s",flag?"''":"��");//�����ж�ֱ�Ӵ�ӡ ��a?b:c���ж�a��a����ִ��b������ִ��c 
			flag=!flag; 
		}else
			printf("%c",c);
	} 
	//scanf("%s",s);//�����ո�TAB�ͻ�ͣ����
	//printf("%s",s);//���ԣ��ո�Tab���س�������ַ������ 
	//��չ��������fgets(buf,maxn,fin)��ȡ�ļ���������һ�С�
	//1������buf������Ϊchar buf[maxn]��������������ȡ����maxn-1���ַ���Ȼ����ĩβ��ӽ�����'\0'�� 
	//2���ܶ�ȡһ�е�ԭ����һ������"\n"��ȡ����ֹͣ����"\n"Ҳ�ᱻ��Ϊ��Ч�ַ���ȡ�����һ���ַ�����"\0"�������豣֤�����ļ���ÿ�о��ѻس�����β�� 
	//3������gets(s)���������᲻�ϵĴ����ݽ�s�У����Ƽ�ʹ������û�н��յ����������ƣ� 
*/
	
/* 
	//WERTYU
	int i,c;
	while((c=getchar())!=EOF){
		for(i=0;s[i] && s[i]!=c;i++);//�����������ҵ����c����û�ҵ�����c=' '������£���s[i]Ҳ���Կ��������ͣ���Ϊ������������ASIIC�� 
		if(s[i])
			putchar(s[i-1]);
		else
			putchar(c);//getchar��������ֵ��int�������ֵ��char���Զ�ת��
		
	} 
*/ 
	
	//���Ĵ�
	/* 
	//��д�ĳ��� 
	char s[20];
	scanf("%s",s);
	int L=strlen(s),flag=0,ok=1;
	for(int j=0;j<L;j++){
		if(strchr(c,s[i])==NULL)
			ok=0;		
	}
	for(int i=0;i<=L/2;i++){
		if(ok){
			if(isalpha(s[i]))
				s[i]=c[s[i]-'A'];
			else
				s[i]=c[s[i]-'0'+25]; 
		}
		if(i<L-i-1 && s[i]==s[L-i-1]){
			flag++;
					
		}	
			
	}
	if(flag==L/2)
		printf("%s -- is a regular palindrome.",s);
	else 
		printf("%s -- is not palindrome.",s);
	*/
	//��
/* 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char s[30];
	while(scanf("%s",s)==1){//�������� 
		int len=strlen(s);
		int p=1,m=1;//�����ж������һ���ַ��� 
		for(int i=0;i<=len/2;i++){
			//���Ƿֿ��ж����αȽϺã���Ȼ�ж�������� 
			if(i<len-i-1 && s[i] != s[len-1-i])
				p=0; //���ǻ��Ĵ� 
			if(i<len-i-1 && r(s[i])!=s[len-1-i])
				m=0; //���Ǿ����� 
		}
		printf("%s -- is %s.\n\n",s,msg[m*2+p]); //0�����ǻ��Ĵ���1���ǻ��Ĵ���2���Ǿ��񴮣�3���Ǿ�����Ĵ� 
	}	
*/
	
/* 
	 //��������Ϸ����ʾ
	 //scanf��ֵ��ʱ��ǧ�������& 
	 //��д�ĳ��򣬴������⣨�ж��������� 
	 int a[30],b[30];
	 int count=0,n;
	 FILE *fin,*fout;
	 fin=fopen("input.txt","rb");
     fout=fopen("output.txt","wb");
     //fin=stdin;
     //fout=stdout;
	 while(fscanf(fin,"%d",&n)==1 && n){//�������Ҳ���0 
	 
	 	for(int i=0;i<n;i++)
	 		fscanf(fin,"%d",&a[i]);
	 	count++; 
	 	fprintf(fout,"Game %d:\r\n",count); //\r\n���ܿ��� 
		while(1){
			int A=0,B=0;
			for(int i=0;i<n;i++)
	 			fscanf(fin,"%d",&b[i]);
	 		if(b[0]==0)
	 			break;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(b[i]==a[j]){
						if(i==j)
							A++;
						else
							B++;
					}
					
				}
			}
			fprintf(fout,"\t(%d,%d)\r\n",A,B);	
					
			}
	 			
		
		} 		
	*/
/* 
	//�� 
	int n,a[maxn],b[maxn];
	int kase=0;
	while(scanf("%d",&n)==1 && n){//n=0ʱ���� 
		printf("Game %d:\n",++kase);
		for(int i = 0;i < n; i++)
			scanf("%d",&a[i]);
		while(1){//Ҫ����һ�ж������ 
			int A=0,B=0;
			for(int i=0;i<n;i++){
				scanf("%d",&b[i]);
				if(a[i]==b[i])
					A++;
					
			}

			if(b[0]==0)
				break;//�����Ĳ²����в�����0������ֻҪ�жϵ�һ�����Ƿ�Ϊ0���� 
			for(int d=1;d<=9;d++){//1~9��ͳ������d�ڴ����кͲ²������и����ֶ��ٴ� 
				int c1=0,c2=0;
				for(int i=0;i<n;i++){ 
					if(a[i]==d)
						c1++;
					if(b[i]==d)
						c2++;
				}
				if(c1<c2)//min(c1,c2)�Ƕ�B�Ĺ��� 
					B+=c1;
				else
					B+=c2;
			}
			printf("    (%d,%d)\n",A,B-A);
		}
		
	} 
*/

/*
	//����Ԫ
	//����ö��n-1����������ÿ�μ���һ��n������Ԫ����Ҫö��n-1�������ܲ����� 
	//α���� 
	int n,x=1;
	scanf("%d",&n);
	for(;x<n;x++){
		if(x��n������Ԫ)
			break; 
			
	}
	if(x==n)
		printf("0\n");
	else
		printf("%d",x);	
	*/
	/* 
	//�����1~100000����������Ԫ�������
	int T,n;
	memset(ans,0,sizeof(ans));
	for(int m=1;m<maxn;m++){
		int x=m,y=m;
		while(x>0){//��仰�ܹؼ������԰�x��ÿһλ��������Ҽ���y�� 
			y+=x%10;
			x/=10;
		}
		if(ans[y]==0 || m<ans[y])//����С����Ԫ��m�ǵ�ǰ������y��m+m����λ 
			ans[y]=m; 
	}	
//	scanf("%d",&T);
//	while(T--){
		scanf("%d",&n);
		printf("%d\n",ans[n]);
		
	//} 
*/
	 
/* 
	//��״����
	char s[maxn];
	int n,ans=0;
	scanf("%s",s);
	n=strlen(s);  
	for(int i=0;i<n;i++){
		if(less(s,i,ans))//����n��Ԫ���е���Сֵ���ƣ�ֻ�ǱȽϵķ�ʽ������ͬ 
			ans=i;
	}
	for(int i=0;i<n;i++){
		putchar(s[(ans+i)%n]);
	}
	putchar('\n');
*/ 
 
	return 0;
	
}
