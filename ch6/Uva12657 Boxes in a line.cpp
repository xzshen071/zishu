#include<cstdio>
const int maxn = 100000 + 5;
int right[maxn], left[maxn];        //存编号i左右的编号

void link(int L, int R);
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m, kase = 0;
    while(scanf("%d%d", &n, &m) == 2) {
        //编号初始化，最左边的编号它的左边与最右边它的右边都为0
        for(int i = 1; i <= n; i++) {
            left[i] = i - 1; 
            right[i] = (i + 1) % (n + 1);
        }
        right[0] = 1; left[0] = n;  //双向循环链表 
        int op, X, Y, inv = 0;      //op为命令号，X、Y为操作对象，inv判断是否发生翻转
        
        //针对命令执行操作
        while(m--) {
            scanf("%d", &op);
            //printf("%d\n", op);
            if(op == 4) inv = !inv; //为打印提供依据，如果翻转则是总数-没翻转奇数位的和
            else {
                scanf("%d%d", &X, &Y);
                if(op != 3 && inv) op = 3 - op; //如果发生翻转则命令1变成2，命令2变成1
                if(op == 1 && left[Y] == X) continue;
                if(op == 2 && right[Y] == X) continue;
                
                int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
                if(op == 1) {                   //把X放在Y左边
                    link(LX, RX); link(LY, X); link(X, Y);   
                }else if(op == 2) {             //把X放在Y右边
                    link(LX,RX); link(Y,X); link(X,RY);
                }else if(op == 3) {             //交换位置
                	//printf("3\n");
                	//printf("%d %d\n", left[X], Y);
                    if(left[X] == Y) {           //Y在X左边
                        link(LY, X); link(X, Y); link(Y, RX); 
                    }else if(right[X] == Y) {   //Y在X右边
                        link(LX, Y); link(Y, X); link(X, RY); //printf("swap: %d %d\n", X, Y); 
                    }else {                    
                        link(LX, Y); link(Y, RX); link(LY, X); link(X, RY);
                    }
                }    
            }   
        }
        
        //打印
        int b = 0;
        long long ans = 0;
        for(int i = 1; i <= n; i++) {
            b = right[b];
            if(i % 2 == 1) ans += b;            //奇数
        }
        if(inv && n % 2 == 0) ans = (long long)(n * ( n + 1) / 2) - ans;  //若翻转且总数是偶数，则拿总数减去从头算的值
        printf("Case %d: %ld\n", ++kase, ans);
    }
    //fclose(stdin);//关闭文件
    //fclose(stdout);//关闭文件
    return 0;
}
void link(int L, int R) {
    right[L] = R; left[R] = L;
}
