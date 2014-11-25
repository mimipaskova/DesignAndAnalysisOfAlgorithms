#include <iostream>
#include <cstdio>

using namespace std;

int p[1 << 16];
int br=0;

void bubleSort(){
    for(int i=0; i<br;i++){
        for(int j=0;j<br-1;j++){
            if(p[j]>p[j+1]){
                swap(p[j],p[j+1]);
            }
        }
    }
}

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF){
        p[br]=n;
        br++;
    }

    bubleSort();

    for(int i=0; i<=br-1;i++){
        printf ("%d ", p[i]);
    }
    return 0;
}
