//Dijkstra

#include <iostream>
#include<vector>
#include<algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int n,m,x,y,z;
vector<pair <int,int> > allEdges[50001];
bool marked[50001];
int d[50001];
int pi[50001];

struct edge{
    int key;
    int parent;
    int current;

    bool operator < (edge other) const {
        return key>other.key;
    }
};


void Dijkstra(int nachalo){
//    for(int i=0;i<m;i++){
//        marked[i] = false;
//    }

    edge node;
    node.key = 0;
    node.parent = -1;
    node.current = nachalo;
    priority_queue<edge> PQ;
    PQ.push(node);
    while(!PQ.empty()){
        edge currentNode = PQ.top();
        PQ.pop();
        int cur = currentNode.current;
        if(marked[cur] == false){
            marked[cur] = true;
            d[cur] = currentNode.key;
            pi[cur] = currentNode.parent;
            for(int i=0;i<allEdges[cur].size();i++){
                edge neigh;
                neigh.key = currentNode.key + allEdges[cur][i].second;
                neigh.parent = cur;
                neigh.current = allEdges[cur][i].first;
                PQ.push(neigh);
            }
        }
    }
}



int main()
{
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &z);
    int currSt, currF,currDist;


    for(int i=0; i<m;i++){
        scanf("%d %d %d", &currSt, &currF, &currDist);
        allEdges[currSt].push_back(make_pair(currF,currDist));
        allEdges[currF].push_back(make_pair(currSt,currDist));
    }

    Dijkstra(y);

    if(d[x]==0 || d[z]==0){
        printf("%d\n", -1);
        return 0;
    }

    printf("%d\n", d[x]+d[z]);
    int put[m+1];
    for(int i=0;i<=m;i++){
        put[i] = -1;
    }

    int roditel = z;
    put[m] = z;
    int i=1;
    while(pi[roditel]!=-1){
        put[m-i] = pi[roditel];
        i++;
        roditel = pi[roditel];
    }
    roditel = x;
    put[0] = x;
    i=1;

    while(pi[roditel]!= y){
        put[i] = pi[roditel];
        i++;
        roditel = pi[roditel];
    }

    for(int p=0;p<m+1;p++){
        if(put[p]!=-1){
            printf("%d ", put[p]);
        }
    }
    printf("\n");

    return 0;
}
