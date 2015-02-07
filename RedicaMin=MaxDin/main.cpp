#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
int x,y;
int broiRedici = 0;
vector<int> pomosht;

void sum() {
    pomosht.push_back(0 );
    pomosht.push_back(1);
    for(int i=2;i<=n;i++){
        pomosht.push_back(pomosht[i-1] + i);
    }
}

int main()
{
    scanf("%d", &n);
    sum();
    long br = 0;

    scanf("%d", &x);
    for(int i=1;i<n;i++){
        y = x;
        scanf("%d", &x);
        if(x==y){
            br++;
        }
        else{
            broiRedici += pomosht[br+1];
            br=0;
        }
    }
    broiRedici+=pomosht[br+1];
    printf("%d\n", broiRedici);
    return 0;
}
