#include<stdio.h>
#include<math.h>
#include<string.h>
#define maxn 5

int main(){
	//����  
	int t = 0;
	char a[maxn][maxn];//�ַ���Ҳ�����Ƕ�ά��
	//���� 
    while(1){
        //����
        if(t){
    		printf("\n");
		}
        fgets(a[0],10,stdin);//������ô��������10����������\n��β����ÿ�о���\n������ 
        int ok=1;
        if(a[0][0] == 'Z') break;//�жϵ��ǵ�һ����ĸ
        int m = 0, n = 0;
        for(int i = 0; i <= 4; ++i) {
            if (i) {//���ǵ�һ��
                fgets(a[i],10,stdin);
            }
            for(int j = 0; j <= 4; ++j) {
                if(a[i][j]  == ' ' || a[i][j] == 0) {//ע�� ǰ�ĸ�λ���Ƿ��пգ�������λ�ã��ַ���β��Ϊ�ղ���ʾ������||ǰ��ĳ�����������ģ�
                    a[i][j] = ' ';
                    m = i; n = j;//���յ�λ�ü�����
                }
            }
        }
        //�ƶ� 
        char c;
    	while((c=getchar())!='\n'){
    		if(c!='0'){
    			switch(c){
    				case 'A':
    					if(m-1<0){
    						ok=0;
						}else{
							a[m][n]=a[m-1][n];
							m--;
						}
						break;
					case 'B':
						if(m+1>maxn){
    						ok=0;
						}else{
							a[m][n]=a[m+1][n];	
							m++;
						}

						break;
					case 'R':
    					if(n+1>maxn){
    						ok=0;
						}else{
							a[m][n]=a[m][n+1]; 
							n++;
						}
    					break;
    				case 'L':
    					if(n-1<0){
    						ok=0;
						}else{
							a[m][n]=a[m][n-1];
							n--;	
						}
    					break;
    				default:
						ok=0;
						break; 
				}
    			a[m][n]=' ';
    			
			}//else
				//brek;//��Ҫ�����䣬�ᵼ��getchar()û���յ�'\n'��������һ�����뷢�����󣬼������˻�û���յ�'\n' 
    			
		}
		//��� 
		printf("Puzzle #%d:\n",++t);
		if(ok){
			for(int i=0;i<5;i++){
				for(int j=0;j<5;j++){
					if(j)
						printf(" ");
					printf("%c",a[i][j]);
				}
				printf("\n");
			}
		}else
			printf("This puzzle has no final configuration\n");
	
	}   	
	
	
	
	
	
	
	
	return 0;
}
