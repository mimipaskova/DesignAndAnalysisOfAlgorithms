#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int masiv[500];
int sum = 0;
int can[100000];

int main()
{

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &masiv[i]);
        sum +=masiv[i];
    }
    for (int i = 1; i <= sum; i++) {
        can[i] = 0;
    }
    can[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = sum; j+1 > 0; j--)
            if (can[j])
                can[j + masiv[i]] = 1;

        for (int i = sum / 2; i > 1; i--)
        if (can[i]) {
                int firstObj = i;
                int secindObj = sum-i;
                printf("%d\n", abs(firstObj-secindObj));
        return 0;
        }
}
