/*ѧϰ�˴���ļ����*/
/*
//���볬ʱ 
#include<cstdio>
#include<cstring>
const int maxd = 20;
int s[1<<maxd];       //���ڵ���Ϊ2^maxd - 1

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    while(scanf("%d", &n) == 1 && n != -1) {
        //��ÿһ��case���д���
        while(n--) {
            int D, I;
            scanf("%d%d", &D, &I);
            memset(s, 0, sizeof(s));
            int k, m = (1<<D) - 1;        //mΪ���ڵ���
            //��ÿ������в���
            for(int i = 0; i < I; i++) {
                k = 1;
                //��һ�� 
                for(;;) {
                    s[k] = !s[k];           //�����Ƚ�����һ����������Ȼk��ֵ���
                    k = s[k] ? 2*k : 2*k+1; //�պ��෴��Ϊ1������ߣ�Ϊ0�����ұ�     
                    if(k > m) break;         //��������š��˳�ѭ��
                }
                //�ڶ��� 
                for(int j = 1; j < D; j++) {//ѭ��D-1�˸պõ���Ҷ�ڵ�
                    if(s[k] == 1) {s[k] = 0; k = 2*k + 1;}
                    else {s[k] = 1; k = 2*k;}
                } 
            }
            printf("%d\n", k/2);            //��������ͨ������������жϵģ�����Ҫ����2     
            //printf("%d\n", k);
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
*/
#include<cstdio>
#include<cstring>

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    while(scanf("%d", &n) == 1 && n != -1) {
        //��ÿһ��case���д���
        while(n--) {
            int D, I;
            scanf("%d%d", &D, &I);
            int k = 1; 
            //�����򵽴�ڵ����ż�ԣ�ֻģ�����һ���� 
            for(int i = 1; i < D; i++) {
            	if(I%2 == 0) { k = 2*k + 1; I /= 2; }
            	else { k = 2*k; I = (I+1) / 2; }
            } 
            printf("%d\n", k);
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

