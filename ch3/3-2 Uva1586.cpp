#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	//分子量
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,flag=1;
	scanf("%d",&t); 
	while(t--){
		double mol,sum=0.0;
		char c;
		int ge=1;
		//getchar可以接收到空格、回车、Tab等符号(第一行有多余的空格) 
		if(flag){
			c=getchar();
			flag=0;
		}	
		//虽然说第一行多余空格会导致循环里的程序不会运行，但是这会浪费一次t的次数（输出为0），导致后面的输入没有输出结果	
		while((c=getchar())!='\n'){//标准的键盘输出时，输出结束时回车+ctrl z,所以getchar会接收回车符再执行一次，放在文件里输出不会是这种情况（不空行） 
		//文件输入的时候最好也是已回车符结尾，注意格式	
			switch(c){//当选择没有规律少俩的时候可以用switch语句 
				case 'C'://case里面可以执行多条语句，各类函数都可以用，例如if等，可以把它当作标号用，不过要注意逻辑 
					mol=12.01;
					//sum=sum+(ge*mol);
					break;
				case 'H':
					mol=1.008;
					break;
				case 'O':
					mol=16.00;
					break;
				case 'N':
					mol=14.01;
					break;
				default:
					ge=c-'1';
					break;
			}
			///printf("%d\n",ge);
			sum=sum+(ge*mol);
			ge=1;
		}

		printf("%f\n",sum);
	}	
	
	
	
	
	
	
	
	return 0;
}
