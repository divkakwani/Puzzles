#include <stdio.h>

int main() {

    int t;
    scanf("%d", &t);

    long long x, a;

    while(t--) {
    
        scanf("%lld %lld", &x, &a);
        long long ans = ((a-x) * (a+x+3)) / 2;
        printf("%lld\n", ans);
    
    }

}
