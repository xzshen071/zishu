#include<cstdio>
#include<cstring>
const int maxn = 100000 + 5;
int last, cur, next[maxn];      //next[0]指向最左边的字符，next[last]指向最右边的字符，next[i]为s[i]向右指向的字符
char s[maxn];                   

int main() {
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
     //将读入的字符串从s[1]开始存入s字符数组中，s[0]保留（不能让s[0]一直指向0，所以不用）
    while(scanf("%s", s+1) == 1) {     
        int n = strlen(s+1);
        last = cur = 0;
        next[0] = 0;
        
        //依次读入此行中每个字符
        for(int i = 1; i <= n; i++) {   
            char ch = s[i];
            if(ch == '[') cur = 0;
            else if(ch == ']') cur = last;
            else {
                /*
                存在三种情况：
                    1、不是[或]：将此字符下一个指向0；将此字符插在下一个字符后面
                    2、是[：将此字符插在next[0]前面；next[0]指向此字符
                    3、是]：此字符下一个指向next[last]；next[last]指向此字符(则此前一个last字符不指向0)
                */
                next[i] = next[cur];        //由第一种情况可知，前一个last字符的next[last]会始终指向0
                next[cur] = i;
                if(cur == last) last = i;   //更新“最后一个字符”编号
                cur = i;                    //移动光标，指向这个字符也即下一个字符的前一个字符
            }      
        }
        //打印
        for(int i = next[0]; i != 0; i = next[i]) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    //fclose(stdin);//关闭文件
    //fclose(stdout);//关闭文件
    
    return 0;  
}
