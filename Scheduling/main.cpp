#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Event{
    int begin;
    int duration;
    int end;
};

long length= 1<<20;
Event* events = new Event [length];
int br = 0;

 bool comparator(Event a, Event b) {
    return a.end < b.end;
}

int main()
{
    int begin, duration,end;

     while(scanf("%d %d", &begin, &duration)!=EOF){
        events[br].begin = begin;
        events[br].duration = duration;
        events[br].end = events[br].duration + events[br].begin;
        br++;
    }

    sort(events, events + br, comparator);

    int counter = 0;
    int maxEvents = 1;

    for(int i=1;i<br;i++){
        if(events[i].begin >= events[counter].end){
            maxEvents++;
            counter = i;
        }
    }

    if(br>0){
        printf("%d\n", maxEvents);
    }
    else
        printf("0\n");
}
