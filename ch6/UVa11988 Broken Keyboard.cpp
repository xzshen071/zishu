#include<cstdio>
#include<cstring>
const int maxn = 100000 + 5;
int last, cur, next[maxn];      //next[0]ָ������ߵ��ַ���next[last]ָ�����ұߵ��ַ���next[i]Ϊs[i]����ָ����ַ�
char s[maxn];                   

int main() {
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
     //��������ַ�����s[1]��ʼ����s�ַ������У�s[0]������������s[0]һֱָ��0�����Բ��ã�
    while(scanf("%s", s+1) == 1) {     
        int n = strlen(s+1);
        last = cur = 0;
        next[0] = 0;
        
        //���ζ��������ÿ���ַ�
        for(int i = 1; i <= n; i++) {   
            char ch = s[i];
            if(ch == '[') cur = 0;
            else if(ch == ']') cur = last;
            else {
                /*
                �������������
                    1������[��]�������ַ���һ��ָ��0�������ַ�������һ���ַ�����
                    2����[�������ַ�����next[0]ǰ�棻next[0]ָ����ַ�
                    3����]�����ַ���һ��ָ��next[last]��next[last]ָ����ַ�(���ǰһ��last�ַ���ָ��0)
                */
                next[i] = next[cur];        //�ɵ�һ�������֪��ǰһ��last�ַ���next[last]��ʼ��ָ��0
                next[cur] = i;
                if(cur == last) last = i;   //���¡����һ���ַ������
                cur = i;                    //�ƶ���ָ꣬������ַ�Ҳ����һ���ַ���ǰһ���ַ�
            }      
        }
        //��ӡ
        for(int i = next[0]; i != 0; i = next[i]) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    //fclose(stdin);//�ر��ļ�
    //fclose(stdout);//�ر��ļ�
    
    return 0;  
}
