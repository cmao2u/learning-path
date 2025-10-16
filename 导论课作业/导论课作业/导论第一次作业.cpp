#include <stdio.h>  int main(){ 

int main() {
    int a;
    unsigned int b;
    printf("请输入一个有符号整数、一个无符号整数：");
    scanf("%d%u", &a, &b);
    printf("a=%d \n", a);
    printf("ua=%u \n", a);
    printf("ub=%u \n", b);
    printf("b=%d \n", b);
    printf("a = b ? %s \n", (a = b) ? "true" : "false");  // 输出判断：a、b是否相等 
    printf("a存于%p \n", &a);
    printf("b存于%p \n", &b);
    return 0;
}