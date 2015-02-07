#include <iostream>
#include<vector>
#include<algorithm>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;

int n,m;
int pi[201];
int rang[201];

struct edge{
    int st,fin,dist;

    bool operator < (edge other) const {
        if (dist < other.dist) return true;
        if (dist == other.dist) {
            if(st < other.st) return true;
            if(st == other.st){
                return fin <other.fin;
            }
        }
        return false;
    }
};

set <edge> allRebra;
set <edge> result;

int d[50001];

int Find(int vertex){
    if (vertex != pi[vertex]){
        pi[vertex] = Find(pi[vertex]);
    }
    return pi[vertex];
}

void Union(int u, int v){
    int u1 = Find(u);
    int v1 = Find(v);
    if(rang[u1]<rang[v1]){
        pi[u1] = v1;
        //zalepi u durvoto kum v durvoto
    }
    else if(rang[u1]>rang[v1]){
        pi[v1] = u1;
        //zalepi v durvoto u durvoto
    }
    else{
        pi[v1] = u1;
        rang[u1]++;
        //radni, rang + 1
    }
}

int Kruskal(){
    for(int i=1;i<=n;i++){
        pi[i] = i;
        rang[i] = 1;
    }

    int mpd = 0;

    set<edge>::iterator toDelete = allRebra.end();
    for (set<edge>::iterator it=allRebra.begin(); it!=allRebra.end(); ++it){
        if(Find(it->st) != Find(it->fin)){
            Union(it->st,it->fin);
            mpd += it->dist;
            //tuk trqbva da ima obedinenie
        }
        else{
            toDelete = it;
        }
    }
    if(toDelete!= allRebra.end()){
        allRebra.erase(toDelete);
    }

    return mpd;
}


int main()
{
    scanf("%d %d", &n, &m);
    int currSt, currF,currDist;

    for(int i=0; i<m;i++){
        scanf("%d %d %d", &currSt, &currF, &currDist);
        edge currentEdge;
        currentEdge.st = currSt;
        currentEdge.fin = currF;
        currentEdge.dist = currDist;
        allRebra.insert(currentEdge);
        int allRoads = Kruskal();

        int firstEl = Find(1);

        for(int j= 2;j<=n; j++){
            if(Find(j)!=firstEl){
                allRoads = -1;
                break;
            }
        }
        printf("%d\n", allRoads);
    }

    return 0;
}
