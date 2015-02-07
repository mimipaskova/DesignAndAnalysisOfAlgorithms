    //Dijkstra

    #include <iostream>
    #include<vector>
    #include<algorithm>
    #include <cstdio>
    #include <queue>
    #include <math.h>

    using namespace std;

    struct point{
        double x;
        double y;

    };

    point points[1024];
    int n;
    vector<pair <double,double> > allEdges[1024];
    bool marked[1024];
    double lqlq = 0;

    struct edge{
        double key;
        int parent;
        int current;

        bool operator < (edge other) const {
            return key>other.key;
        }
    };


    double Prim(int nachalo){
    //    for(int i=0;i<m;i++){
    //        marked[i] = false;
    //    }
        double distance = 0;
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
                distance += currentNode.key;
    //            d[cur] = currentNode.key;
    //            pi[cur] = currentNode.parent;
                for(int i=0;i<allEdges[cur].size();i++){

                        edge neigh;
                        neigh.key = allEdges[cur][i].second;
                        neigh.parent = cur;
                        neigh.current = allEdges[cur][i].first;
                    if(marked[neigh.current] != true){
                        PQ.push(neigh);
                    }
                }
            }
        }
        return distance;
    }

    int main()
    {
        scanf("%d", &n);
        double x, y;
        double dist;

        for(int i=0; i<n;i++){
            scanf("%lf %lf", &x, &y);
            point p = {x, y};
            points[i]= p;
            for(int j = i-1; j>=0; j--) {
                dist = sqrt(pow((points[i].x - points[j].x),2) + pow((points[i].y - points[j].y),2));
                allEdges[i].push_back(make_pair(j,dist));
                allEdges[j].push_back(make_pair(i,dist));
                lqlq+=dist;
            }
        }
        lqlq = lqlq/n;

        printf("%.2lf\n", Prim(1));
        return 0;
    }
