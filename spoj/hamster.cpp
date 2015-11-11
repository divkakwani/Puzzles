#include <bits/stdc++.h>

using namespace std;

int
main(void) {

    int t;
    scanf("%d", &t);

    while(t--) {
        long double v, k1, k2;
        long double g = 10.00; 
       
        scanf("%LF %LF %LF", &v, &k1, &k2);

        long double theta = (atan(-4*k1/k2)+M_PI)/2;

        printf("%.3LF ", theta);
        

        long double points;
        
        points = ((v*v)/g) * (k1*abs(sin(2*theta)) + (k2/2)*sin(theta)*sin(theta));
        
        printf("%.3LF\n", points) ;
    }
    return 0;
}
