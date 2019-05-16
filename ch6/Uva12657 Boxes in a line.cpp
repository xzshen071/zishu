#include<cstdio>
const int maxn = 100000 + 5;
int right[maxn], left[maxn];        //����i���ҵı��

void link(int L, int R);
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, kase = 0;
    while(scanf("%d%d", &n, &m) == 2) {
        //��ų�ʼ��������ߵı��������������ұ������ұ߶�Ϊ0
        for(int i = 1; i <= n; i++) {
            left[i] = i - 1; 
            right[i] = (i + 1) % (n + 1);
        }
        right[0] = 1; left[0] = n;  //˫��ѭ������ 
        int op, X, Y, inv = 0;      //opΪ����ţ�X��YΪ��������inv�ж��Ƿ�����ת
        
        //�������ִ�в���
        while(m--) {
            scanf("%d", &op);
            //printf("%d\n", op);
            if(op == 4) inv = !inv; //Ϊ��ӡ�ṩ���ݣ������ת��������-û��ת����λ�ĺ�
            else {
                scanf("%d%d", &X, &Y);
                if(op != 3 && inv) op = 3 - op; //���������ת������1���2������2���1
                if(op == 1 && left[Y] == X) continue;
                if(op == 2 && right[Y] == X) continue;
                
                int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
                if(op == 1) {                   //��X����Y���
                    link(LX, RX); link(LY, X); link(X, Y);   
                }else if(op == 2) {             //��X����Y�ұ�
                    link(LX,RX); link(Y,X); link(X,RY);
                }else if(op == 3) {             //����λ��
                	//printf("3\n");
                	//printf("%d %d\n", left[X], Y);
                    if(left[X] == Y) {           //Y��X���
                        link(LY, X); link(X, Y); link(Y, RX); 
                    }else if(right[X] == Y) {   //Y��X�ұ�
                        link(LX, Y); link(Y, X); link(X, RY); //printf("swap: %d %d\n", X, Y); 
                    }else {                    
                        link(LX, Y); link(Y, RX); link(LY, X); link(X, RY);
                    }
                }    
            }   
        }
        
        //��ӡ
        int b = 0;
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            b = right[b];
            if(i % 2 == 1) ans += b;            //����
        }
        if(inv && n % 2 == 0) ans = (long long)(n * ( n + 1) / 2) - ans;  //����ת��������ż��������������ȥ��ͷ���ֵ
        printf("Case %d: %ld\n", ++kase, ans);
    }
    //fclose(stdin);//�ر��ļ�
    //fclose(stdout);//�ر��ļ�
    return 0;
}
void link(int L, int R) {
    right[L] = R; left[R] = L;
}
