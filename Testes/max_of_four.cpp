#include <iostream>

int max_of_four(int a, int b, int c, int d){
    int max=0;
    if (a>max){	
        max=a;
    }
    if (b>max){
        max=b;
    }
    if (c>max){
        max=c;
    }
    if (d>max){
        max=d;
    }
    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("Máximo = %d\n", ans);
    
    return 0;
}
