/*学习此代码的简洁性*/
/*
//代码超时 
#include<cstdio>
#include<cstring>
const int maxd = 20;
int s[1<<maxd];       //最大节点数为2^maxd - 1

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    while(scanf("%d", &n) == 1 && n != -1) {
        //对每一个case进行处理
        while(n--) {
            int D, I;
            scanf("%d%d", &D, &I);
            memset(s, 0, sizeof(s));
            int k, m = (1<<D) - 1;        //m为最大节点编号
            //对每个球进行操作
            for(int i = 0; i < I; i++) {
                k = 1;
                //第一种 
                for(;;) {
                    s[k] = !s[k];           //必须先进行这一步操作，不然k的值会变
                    k = s[k] ? 2*k : 2*k+1; //刚好相反，为1则走左边，为0则走右边     
                    if(k > m) break;         //超过最大编号。退出循环
                }
                //第二种 
                for(int j = 1; j < D; j++) {//循环D-1此刚好到达叶节点
                    if(s[k] == 1) {s[k] = 0; k = 2*k + 1;}
                    else {s[k] = 1; k = 2*k;}
                } 
            }
            printf("%d\n", k/2);            //由于它是通过超过最大编号判断的，所以要除以2     
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
        //对每一个case进行处理
        while(n--) {
            int D, I;
            scanf("%d%d", &D, &I);
            int k = 1; 
            //根据球到达节点的奇偶性，只模拟最后一个球 
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

