#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	while(scanf("%d", &t) == 1) {
		int symbol = 1;
		while(t--) {
			if(symbol) symbol = 0;
			else printf("\n");
			//ö�ٷ����������������������
			char s[100];
			scanf("%s", s);
			int len = strlen(s);
			for(int i = 1; i <= len; i++) {//ö�� 
				int flag = 1; 
				if(len % i == 0) {//���iΪ��С���ڣ���ô�ַ������ȱض���i��������
					for(int j = i; j < len; j++) {//�ж�i�Ƿ�Ϊ������ 
						if(s[j-i] != s[j]) {
							flag = 0;
							break;
						}
					}
					if(flag) {
						printf("%d\n", i); 
						break;//ֻ��ӡ��С���� 
					}
				}	
			}	
		}
	}
	return 0;
}
