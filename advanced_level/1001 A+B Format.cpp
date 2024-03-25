#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int a, b, num, temp, base;
    char s[10];
    scanf("%d%d", &a, &b);
    if(a+b < 0) {printf("-");}
    sprintf(s, "%d", abs(a+b));
    
    base = 0;
    num = strlen(s) % 3;
    while(s[base+num] != '\0'){
        for (temp = 0; temp < num; temp++) {
            putchar(s[base+temp]);
        }
        if (num) {putchar(',');}
        base += num;
        num = 3;
    };
    for (temp = 0; temp < num; temp++) {
        putchar(s[base+temp]);
    }
    putchar('\n');
    return 0;
}
