//Dijkstra

#include <iostream>
#include<vector>
#include<algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int n,m;
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

struct svetofar{
    int green;
    int red;
};

    svetofar svetofari[5005];

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
                int distance = currentNode.key + allEdges[cur][i].second;
                int timeWaiting = 0;
//                printf("%d %d \n", svetofari[allEdges[cur][i].first].green, svetofari[allEdges[cur][i].first].red);
                int svetlini = svetofari[allEdges[cur][i].first].green + svetofari[allEdges[cur][i].first].red;

                edge neigh;
                if(distance <= svetlini) {
                    if(distance> svetofari[allEdges[cur][i].first].green){
                        timeWaiting = svetlini%distance;
                        neigh.key = svetlini;
                    }
                    else{
                        timeWaiting =0;
                        neigh.key = distance;
                    }
                }
                else{
                    if(distance%svetlini > svetofari[allEdges[cur][i].first].green){
                        timeWaiting = svetlini - distance%svetlini;
                    }
                    neigh.key = distance + timeWaiting;
                }


                neigh.parent = cur;
                neigh.current = allEdges[cur][i].first;
                PQ.push(neigh);
            }
        }
    }
}



int main()
{
    scanf("%d %d", &n, &m);
    int currSt, currF,currDist;
    int green, red;



    for(int i=0; i<m;i++){
        scanf("%d %d %d", &currSt, &currF, &currDist);
        allEdges[currSt].push_back(make_pair(currF,currDist));
        allEdges[currF].push_back(make_pair(currSt,currDist));
    }

    for(int i=1; i<=n; i++){
        scanf("%d %d", &svetofari[i].green, &svetofari[i].red);
    }

    Dijkstra(1);
//    printf("-------------------\n");
//
//    for(int i=0;i<=n;i++){
//        printf("%d %d\n", i, d[i]);
//    }
//    printf("-------------------\n");

    printf("%d\n", d[n]);


    return 0;
}
