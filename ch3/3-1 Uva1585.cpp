#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
	//ตรทึ
	int sorce=0,kase=0;
	char c;
	while((c=getchar())!=EOF){
	
		if(c=='O'){
			kase++;
			sorce+=kase;
			
		}else
			kase=0;
			
	}
	printf("%d",sorce);


	return 0; 
} 
