#include <iostream>
#include <cstdio>

using namespace std;

long length= 1<<20;
long* numbers = new long[length];
char command;
long number;
int br = 1;
long maxNumber;

void moveUp(int i){
    while(i>0){
        if(i == 1){
            return;
        }
        //left child
        if(i%2 == 0){
            if(numbers[i]>numbers[i/2]){
                swap(numbers[i],numbers[i/2]);
                i=i/2;
            }
            else{
                return;
            }
        }
        //right child
        else{
            if(numbers[i]>numbers[(i-1)/2]){
                swap(numbers[i],numbers[i/2]);
                i=(i-1)/2;
            }
            else{
                return;
            }
        }
    }
}

void push (long number, int index){
    numbers[index] = number;
    moveUp(index);

}

long getFirst(){
    return numbers[1];
}

void pop(int i){
    long maxFirst = numbers[1];
    long largest;
    numbers[i] = 0;
    bool noInv = false;
    while(!noInv){
        if((numbers[2*i]<=length) && (numbers[i]<numbers[2*i])){
            largest = 2*i;
        }
        else{
            largest = i;
        }
        if((numbers[2*i+1]<=length) && (numbers[largest]<numbers[2*i+1])){
            largest = 2*i+1;
        }
        if(largest!=i){
            swap(numbers[i], numbers[largest]);
            i=largest;
        }
        else{
            noInv = true;
        }
    }
}


int main()
{
    int n;
    while(scanf("%d", &n)!=EOF){
        numbers[br]=n;
        br++;
    }


    int peak = 1;

    while(true){
        scanf("%c", &command);
        if(command == 'A'){
            scanf("%ld\n", &number);
            push(number, br);
            br++;
        }
        if(command == 'L'){
            maxNumber = getFirst();
            if(maxNumber!=0){
                printf("%ld\n",maxNumber);
            }
            else{
                printf ("%s\n", "Not available");
            }
        }
        if(command == 'R'){
            maxNumber = getFirst();
            if(maxNumber!=0){
                printf("%ld\n",maxNumber);
                pop(1);
            }
            else{
                printf ("%s\n", "Not available");
            }
        }
        if(command == 'Q'){
            return 0;
        }
    }
        return 0;
}
