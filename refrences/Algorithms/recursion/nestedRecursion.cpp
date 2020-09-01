#include <stdio.h>
int fun(int n)
{
    if (n > 100)
        return n - 10;
    return fun(fun(n + 11));
}
int main()
{
    int num;
    int r;
    printf("Enter a number \n");
    scanf("%d", &num);
    r = fun(num);
    printf("%d\n", r);
    return 0;
}