#include <iostream>
#include <cstdio>

using namespace std;

int a,b,c,d, n;

bool oneTour ( int x, int y){
    if(x<a || y<b){
        return false;
    }
    if(x==a && y==b){
        return true;
    }
    if(x>y){
        return oneTour(x-y,y);
    }
    else{
        return oneTour(x,y-x);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        bool lqlq = oneTour(c,d);
        if(lqlq){
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}
