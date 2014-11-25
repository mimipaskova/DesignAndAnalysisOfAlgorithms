#include <iostream>
#include <cstdio>

using namespace std;

int masiv [100000];
long sortArr[100000];
int index = 0;
long long inversions;

void push(int number){
    sortArr[index] = number;
    index++;
}

void merge(int l,int r){
    int begin1=l;
    int begin2=(l+r)/2+1;
    index = 0;
    while(begin1<=(l+r)/2 || begin2<=r){

        if(begin1<=(l+r)/2 && begin2<=r){
            if(masiv[begin1]<masiv[begin2]){
                push(masiv[begin1]);
                begin1++;
            }
            else{
                push(masiv[begin2]);
                begin2++;
            }
        }
        else{
            if(begin1<=(l+r)/2){
                push(masiv[begin1]);
                begin1++;
            }
            else if(begin2<=r){
                push(masiv[begin2]);
                begin2++;
            }

        }
    }
    for(int i = l; i <= r; i++)
    {
        masiv[i] = sortArr[i-l];
    }

}

void mergeSort(int l, int r){
    if(l >= r)
        return;
    mergeSort(l,(l+r)/2);
    mergeSort(((l+r)/2)+1,r);
    merge(l,r);
}


int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &masiv[i]);
    }
    mergeSort(0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ", masiv[i]);
    }
    printf("\n");
    return 0;
}
