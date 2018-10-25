#include<stdio.h>
#include<string.h>//保证memset函数可以用，此函数方便对数组进行初始化 
#include<ctype.h>//保证isalpha函数能使用，类似的还有idigit，isprint 
/*
//逆序输出 
//#define maxn 100//应该声明比限制稍大的数，题目是说maxn<=100 
//#define maxn 1000000//测试数组定义在外或者在里的区别
#define maxn 105 
int a[maxn];//数组定义最好在外面，只有放在外面数组a才可以开得很大 
*/
/*
//开灯问题 
#define maxn 1005
int a[maxn];
*/
/*
//蛇形填数 
#define maxn 10
int a[maxn][maxn]; 
*/
/*
//MERTYU 
char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";//定义常量数组，善用常量数组易于简化代码，斜杠需要用"\\"表示
*/ 
/*
//回文词 
const char* rev="A   3  HIL JM O   2TUVWXY51SE Z  8 ";//为啥要定义成指针（记录首地址，数组传递相当于传递数组的首地址）,不定义成指针这句话也没错 
const char* msg[]={"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};//不定义成指针则报错
char r(char ch){//子函数 
	if(isalpha(ch))//isalpha(ch)用来判断ch是否是字母 
		return rev[ch-'A'];//'A'的序号是0 
	else//是数字 
		return rev[ch-'0'+25];//ch-'0'是这个数字本身，数字在26个字母之后才出现，但是下标从0开始计算 
}
*/
/*
//猜数字游戏的提示 
#define maxn 1050
*/
/*
//生成元 
#define maxn 100005
*/
/* 
//环状序列 
#define maxn 105
//环状串的表示法p是否比表示法q的字典序小 
int less(const char*s,int p,int q){
	int n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[(p+i)%n]!=s[(q+i)%n])
			return s[(p+i)%n] < s[(q+i)%n];//p<q的话返回1 
	}
	return 0;//相等 
}
*/ 
int ans[maxn];
int main(){
/* 
	//逆序输出
	int x,n=0;
	//int a[maxn];//数组定义在里面，空间开的太大，即maxn过大会异常退出 
	while(scanf("%d",&x)==1)
		a[n++]=x;//最后一个数位a[n-1] 
	for(int i=n-1;i>0;i--)
		printf("%d ",a[i]);
	printf("%d\n",a[0]);//保证最后一位空行 
*/
	
/*	
	//开灯问题
	int k,n,count=0;
	//int frist=1;
	scanf("%d%d",&n,&k);
	//数组初始化
	//for(int s=1;s<=n;s++)
		//a[s]=-1; 
	
	memset(a,0,sizeof(a));//对数组a中的所有元素清零，简化初始化 
	for(int i=1;i<=k;i++)//人 
		for(int j=1;j<=n;j++){//灯 
			if(i*j<=n) 
				a[i*j]=-a[i*j];
			else 
				break;
				
			//or 
			//if(j%i == 0)//j是i的倍数 
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
			//if(frist)//保证满足输出格式，即第一个不要空格，后面输出要空一格 
				//frist=0;
			//else
				//printf(" ");
			//printf("%d",i);
		//} 
		
	}
	printf("\n");
		 
*/

/* 
	//测试memcpy、memset函数和对数组赋值的理解 
	int b[6]={1},k=5;
	int a[10]={1,2,23,3,33,3,3,44,4};//这样给数组赋值必须是定义的时候赋值，若先定义a[10],再a[10]={...}将报错 
	//memset函数是将一个数组清零，而不是使数组全部元素等于同一个数 
	//memset(a,0,sizeof(a));
	
	//memcpy(b,a,sizeif(int)*k),b是操作对象，目的是将数组a复制k个元素到数组b，其中a，b都要为整形数组，若是浮点型将int改成double
	//这里复制k个元素指的是复制前k个元素	 
	memcpy(b,a,sizeof(int)*5);	
	for(int i=0;i<6;i++)
		printf("%d ",b[i]);//整数也可以求非，不是1的数求非则是0，！0=1 
		
	//对 int a[maxn]={0};的理解 
	//数组初始化列表中的元素个数小于指定的数组长度时，不足的元素补以默认值，这里的默认值指的是0；但是你不给数组赋值它的值就是随机的。 
*/

/* 
	//蛇形填数
	//写题目除了看出规律，还应该注重判定条件，说不定会有思路
	int num=1,n,x=0,y;//y=n-1;//y这里赋值错误，n没有值 
	scanf("%d",&n);
	//初始化二维数组
	memset(a,0,sizeof(a));
	a[x][y=n-1]=num;//c语言有简介的语法，但前提是保持代码的可读性 
	
	while(num<n*n){
		
		while(x+1<n && !a[x+1][y] )//注意这些判定条件，指的是填入下一个值的条件 
			a[++x][y]=++num; 
		while(y-1>=0 && !a[x][y-1])
			a[x][--y]=++num;
		while(x-1>=0 && !a[x-1][y])
			a[--x][y]=++num;
		while(y+1<n & !a[x][y+1])
			a[x][++y]=++num;

		//!a[++x][y]为什么错
		//写程序应该保持一个原则：先判断再移动，而不是遇到错误了再退回来。（下面这个程序存在这一个问题：错误了但是也移动了，也没有退回来） 
		//下面这段程序是错的	
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
	//竖式问题 
	//伪代码（写程序时可以先写伪代码，再从它出发完善代码的具体内容） 
	char s[20];//C语言中字符型又char表示，它实际存储的是字符的ASIIC码，在语法上可以把字符当作int型使用 
	int count=0;
	scanf("%s",s);//与scanf("%d",&n)不同，没有&，但是性质类似不会读入空格、TAB和回车符，scanf("%s",s)读入的数据存入字符数组s，遇到空白字符会停下来
	//也可用scanf("%s",s[i])这个形式，表示读取第i个字符串，自己尝试一下 
	for(int abc=111;abc<=999;abc++)///尝试所有的abc（三位数）和de（二位数） 
		for(int de=11;de<=99;de++){
			if(abc*de是合法的竖式){ 
				printf("<%d>\n",++count);
				打印abc*de的竖式和其后的空行 
			}
		printf("The number of solutions = %d\n",count); 
		} 
	*/ 
	/* 
	//此程序需要解决的问题
	//1、输入没有空格如何将数字分开->用字符型数组存，字符型数组语法上也可以当成int型使用,字符串相当于字符数组 
	//2、怎么判断abc,de,adc*e,abc*d,abc*de是否再输入的数字集合内->strchr函数（在一个字符串中查找单个字符，不成功返回NULL） 
	//3、输出格式->%5d... 
	char s[20],buf[99];
	int count=0;
	scanf("%s",s);//将字符串存入字符数组中，%s指的是字符串类型 
	//for(int i=0;i<strlen(s);i++)
		//printf("%c",s[i]);//输出单个字符格式必须是%c 
	
	for(int abc=111;abc<=999;abc++)///尝试所有的abc（三位数）和de（二位数） 
		for(int de=11;de<=99;de++){
			int x=abc*(de%10),y=abc*(de/10),z=abc*de;
			//sprintf（输出到字符串（字符数组））、printf（输出到屏幕）和fprintf（输出到文件）类似， 
			sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);//将abc,de,adc*e,abc*d,abc*de存入字符数组buf中,%d之间没有空格是因为若有，空格符也会被存入buf中 
			//结果等于是sprintf(buf,"字符串"); 意思是将"..."这个字符串存入buf中； 
			int ok=1;
			for(int i=0;i<strlen(buf);i++){//strlen函数返回的是\0前字符的个数，即存入123，加上\0存了4个字符，此函数返回3
				if(strchr(s,buf[i])==NULL)
					ok=0;
			}
			if(ok){ 
				printf("<%d>\n",++count);
				//打印abc*de的竖式和其后的空行，这里的abc和de是整数
				//存在一个问题，要是相乘超过5位怎么办？，这个问题不存在 
				printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);//这里的%5d,它表示按照5位数打印，不足5再前面补空格，%03d左边补0 
			}
		} 
	printf("The number of solutions = %d\n",count); 
*/ 
	
/* 
	//strchqr演示
	const char str[] = "http://www.runoob.com6666666";
   	const char ch = '.';
   	char *ret;

  	ret = strchr(str, ch);//strchr的返回值是在str中第一次出现ch的位置（指针），会输出此指针后的值，未找当即返回NULL 

  	printf("|%c| 之后的字符串是 - |%s|\n", ch, ret); 
	//打印结果：|.| 之后的字符串是 - |.runoob.com6666666|
*/
	
/* 
	//++、--实验 
	int count=0;
	printf("%d %d %d",count++,count++,count++);
	//当count=0时，打印是2 1 0 
	printf("%d %d %d",++count,++count,++count);
	//当count=0时，打印是3 3 3 
	count=count++;
	printf("%d",count);
	//当count=0时，打印是0
	//以上编译结果其实跟编译器有一定的关系
	//说明一点：平时应该避免这样的程序，即++、--,+=这类的运算符每条语句最好只出现一次，并且被修改的变量也只出现一次
*/

	//竞赛题目选讲	
/* 
	//TeX中的引号
	//要解决的问题
	//1、输入的字符串存储方式->不能用scanf,则就一个字符一个字符的判断，也就不用在字符串数组中存储，改字符，打印。直接打印就ok 
	//2、怎么判断是不是双引号，且是要注意是左双引号，还是又双引号 ->getchar()获得标准输入的字符，用一个标记判断是左还是右 
	int c,flag=1;
	//注意：在使用getchar与fgetc时避免写出与操作系统相关的程序，即不同的操作系统的回车换行符是不一致的，windows是'\r'与'\n'，Linux是'\n，MacOS是'\r' 
	while((c=getchar())!=EOF){//getchar的返回值是int(因为有一个结束标记EOF，它不是char)，getchar()=fgetc(stdin),，fgetc(fin)可以从文件读下一个字符
		if(c=='"'){//记住c是int型，在语法上char型可以当作int型处理，'"'可以值的是"的ASIIC码 
			printf("%s",flag?"''":"”");//单个判断直接打印 ，a?b:c，判断a，a真则执行b，否则执行c 
			flag=!flag; 
		}else
			printf("%c",c);
	} 
	//scanf("%s",s);//遇到空格、TAB就会停下来
	//printf("%s",s);//测试，空格、Tab、回车后面的字符不输出 
	//扩展：可以用fgets(buf,maxn,fin)读取文件中完整的一行。
	//1、其中buf的声明为char buf[maxn]，这个函数不会读取超过maxn-1个字符，然后再末尾添加结束符'\0'； 
	//2、能读取一行的原因是一旦碰到"\n"读取工作停止，而"\n"也会被作为有效字符读取，最后一个字符仍是"\0"。我们需保证输入文件的每行均已回车符结尾； 
	//3、存在gets(s)，但是它会不断的存内容进s中，不推荐使用它（没有接收的最大个数限制） 
*/
	
/* 
	//WERTYU
	int i,c;
	while((c=getchar())!=EOF){
		for(i=0;s[i] && s[i]!=c;i++);//结束条件：找到这个c或者没找到（当c=' '的情况下），s[i]也可以看作是整型，因为计算机保存的是ASIIC码 
		if(s[i])
			putchar(s[i-1]);
		else
			putchar(c);//getchar正常返回值是int，如果赋值给char会自动转换
		
	} 
*/ 
	
	//回文词
	/* 
	//我写的程序 
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
	//答案
/* 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char s[30];
	while(scanf("%s",s)==1){//连续输入 
		int len=strlen(s);
		int p=1,m=1;//用来判断输出哪一个字符串 
		for(int i=0;i<=len/2;i++){
			//还是分开判断两次比较好，虽然判定条件差不多 
			if(i<len-i-1 && s[i] != s[len-1-i])
				p=0; //不是回文串 
			if(i<len-i-1 && r(s[i])!=s[len-1-i])
				m=0; //不是镜像文 
		}
		printf("%s -- is %s.\n\n",s,msg[m*2+p]); //0：不是回文串，1：是回文串，2：是镜像串，3：是镜像回文串 
	}	
*/
	
/* 
	 //猜数字游戏的提示
	 //scanf赋值的时候千万别忘了& 
	 //我写的程序，答案有问题（判定条件出错） 
	 int a[30],b[30];
	 int count=0,n;
	 FILE *fin,*fout;
	 fin=fopen("input.txt","rb");
     fout=fopen("output.txt","wb");
     //fin=stdin;
     //fout=stdout;
	 while(fscanf(fin,"%d",&n)==1 && n){//有输入且不是0 
	 
	 	for(int i=0;i<n;i++)
	 		fscanf(fin,"%d",&a[i]);
	 	count++; 
	 	fprintf(fout,"Game %d:\r\n",count); //\r\n才能空行 
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
	//答案 
	int n,a[maxn],b[maxn];
	int kase=0;
	while(scanf("%d",&n)==1 && n){//n=0时结束 
		printf("Game %d:\n",++kase);
		for(int i = 0;i < n; i++)
			scanf("%d",&a[i]);
		while(1){//要将这一行读完才行 
			int A=0,B=0;
			for(int i=0;i<n;i++){
				scanf("%d",&b[i]);
				if(a[i]==b[i])
					A++;
					
			}

			if(b[0]==0)
				break;//正常的猜测序列不会有0，所以只要判断第一个数是否为0即可 
			for(int d=1;d<=9;d++){//1~9，统计数字d在答案序列和猜测序列中各出现多少次 
				int c1=0,c2=0;
				for(int i=0;i<n;i++){ 
					if(a[i]==d)
						c1++;
					if(b[i]==d)
						c2++;
				}
				if(c1<c2)//min(c1,c2)是对B的贡献 
					B+=c1;
				else
					B+=c2;
			}
			printf("    (%d,%d)\n",A,B-A);
		}
		
	} 
*/

/*
	//生成元
	//可以枚举n-1个数，但是每次计算一个n的生成元都需要枚举n-1个数，很不方便 
	//伪代码 
	int n,x=1;
	scanf("%d",&n);
	for(;x<n;x++){
		if(x是n的生成元)
			break; 
			
	}
	if(x==n)
		printf("0\n");
	else
		printf("%d",x);	
	*/
	/* 
	//查表，把1~100000的数的生成元都算出来
	int T,n;
	memset(ans,0,sizeof(ans));
	for(int m=1;m<maxn;m++){
		int x=m,y=m;
		while(x>0){//这句话很关键，可以把x的每一位都算出来且加在y上 
			y+=x%10;
			x/=10;
		}
		if(ans[y]==0 || m<ans[y])//存最小生成元，m是当前的数，y是m+m各个位 
			ans[y]=m; 
	}	
//	scanf("%d",&T);
//	while(T--){
		scanf("%d",&n);
		printf("%d\n",ans[n]);
		
	//} 
*/
	 
/* 
	//环状序列
	char s[maxn];
	int n,ans=0;
	scanf("%s",s);
	n=strlen(s);  
	for(int i=0;i<n;i++){
		if(less(s,i,ans))//跟求n个元素中的最小值类似，只是比较的方式有所不同 
			ans=i;
	}
	for(int i=0;i<n;i++){
		putchar(s[(ans+i)%n]);
	}
	putchar('\n');
*/ 
 
	return 0;
	
}
