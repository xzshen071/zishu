#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<ctype.h>
#define maxn 5
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//����  
	int t = 0;
	char a[maxn][maxn];//�ַ���Ҳ�����Ƕ�ά��
	//���� 
    while(1){
        //����
        if(t) getchar();
        fgets(a[0],10,stdin);//������ô��������10����������\n��β����ÿ�о���\n������
		//cout << a[0] << endl;
		 
        int ok=1;
        if(a[0][0] == 'Z') break;//�жϵ��ǵ�һ����ĸ
        if(t) cout << endl;
        int m = 0, n = 0;
        for(int i = 0; i <= 4; ++i) {
            if(i) {//���ǵ�һ��
                fgets(a[i],10,stdin);
                //cout << a[i] << endl;
            }
            for(int j = 0; j <= 4; ++j) {
                if(a[i][j]  == ' ' || a[i][j] == 0) {//ע�� ǰ�ĸ�λ���Ƿ��пգ�������λ�ã��ַ���β��Ϊ�ղ���ʾ������||ǰ��ĳ�����������ģ�
                    a[i][j] = ' ';
                    m = i; n = j;//���յ�λ�ü�����
                }
            }
        }
        //cout << m << " " << n << endl;
        //�ƶ� 
        char c;
    	while(c = getchar()) {
    		//cout << c << endl;
    		if((isalpha(c) || isdigit(c)) && c != '0'){
    			switch(c){
    				case 'A':
    					if(m-1<0){
    						ok=0;
    						//cout << c << " " << "1" << endl;
						}else{
							a[m][n]=a[m-1][n];
							m--;
						}
						break;
					case 'B':
						if(m+1>=maxn){
    						ok=0;
    						//cout << c << " " << "2" << endl;
						}else{
							a[m][n]=a[m+1][n];	
							m++;
						}

						break;
					case 'R':
    					if(n+1>=maxn){
    						ok=0;
    						//cout << c << " " << "3" << endl;
						}else{
							a[m][n]=a[m][n+1]; 
							n++;
						}
    					break;
    				case 'L':
    					if(n-1<0){
    						ok=0;
    						//cout << c << " " << "4" << endl;
						}else{
							a[m][n]=a[m][n-1];
							n--;	
						}
    					break;
    				default:
    					//cout << c << " " << "5" << endl;
						ok=0;
						break; 
				}
    			a[m][n]=' ';
    			
			}else if(c == '0') {
				//cout << "0" << endl;
				break; 
			}
    			
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
			printf("This puzzle has no final configuration.\n");
		
	}   	
	
	return 0;
}
