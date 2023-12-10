#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define MaxSize 10

/*struct Edge
{
    int adjvex;
    Edge* next;
};*/

/*template<typename Element>
struct Vertex
{
    Element vertex;
    Edge* firstEdge;
};*/

struct Edge
{
    int lowcost;
    int adjvex;
};

template <typename Element>
class AMGraph
{
public:
    AMGraph();
    ~AMGraph() { }

    void bfTraverse(int v);
    void dfTraverse(int v);
    Element vertex[MaxSize];
    int edge[MaxSize][MaxSize];
    bool visited[MaxSize] = { false };
    int vertexNum;
    int edgeNum;
    Edge minEdge[MaxSize * MaxSize];

    void Dijkstra(int s, int d[], int p[]);
    void Kruskal();
    int find(int parent[], int f);
  
private:
    /*  Vertex<Element> adjList[Maxsize];
        Element vertex[MaxSize];
        int edge[MaxSize][MaxSize];
        int vertexNum, edgeNum;*/
};

template <typename Element>
AMGraph<Element>::AMGraph()
{
    //    cin >> vertexNum >> edgeNum;
    vertexNum = 6;
    edgeNum = 15;
    for (int i = 0; i < vertexNum; i++)
        cin >> vertex[i];
    for (int i = 0; i < vertexNum; i++)
        for (int j = 0; j < vertexNum; j++)
        {
            edge[i][j] = 0;
        }
    int v1, v2, power;
    for (int i = 0; i < edgeNum; i++)
    {
        cin >> v1 >> v2 >> power;
        edge[v1][v2] = power;
        edge[v2][v1] = power;
    }
}

template <typename Element>
void AMGraph<Element>::dfTraverse(int v)
{
    visited[v] = true;
    cout << vertex[v];
    for (int w = 0; w < vertexNum; w++)
    {
        if (edge[v][w] != 0 && !visited[w])
            dfTraverse(w);
    }
}

template <typename Element>
void AMGraph<Element>::bfTraverse(int v)
{
    bool visited[MaxSize];
    for (int i = 0; i < vertexNum; i++)
        visited[i] = false;
    queue<int> q;
    cout << vertex[v];
    visited[v] = true;
    q.push(v);
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        for (int j = 0; j < vertexNum; j++)
        {
            if (edge[v][j] != 0 && !visited[j])
            {
                visited[j] = true;
                cout << vertex[j];
                q.push(j);
            }
        }
    }
}

int shortEdge(Edge minEdge[], int vertexNum)
{
    int min = INT_MAX;  
    int k = -1;
    for (int i = 0; i < vertexNum; i++)
    {
        if (minEdge[i].lowcost != 0 && minEdge[i].lowcost < min)
        {
            min = minEdge[i].lowcost;
            k = i;
        }
    }
    return k;
}
/*
void mst_Prim(AMGraph<char> G, int k)
{
    cout << endl;
    for (int i = 0; i < G.vertexNum; i++)
    {
        G.minEdge[i].lowcost = G.edge[k][i];
        G.minEdge[i].adjvex = 0;
    }
    G.minEdge[k].lowcost = 0;
    for (int i = 1; i < G.vertexNum; i++)
    {
        k = shortEdge(G.minEdge,G.vertexNum);
        cout << G.vertex << G.minEdge[k].adjvex;
        cout << G.minEdge[k].lowcost;
        G.minEdge[k].lowcost = 0;
        for (int j = 0; j < G.vertexNum; j++)
        {
            if (G.edge[k][j] < G.minEdge[j].lowcost)
            {
                G.minEdge[j].lowcost = G.edge[k][j];
                G.minEdge[j].adjvex = k;
            }
        }
    }
    cout << endl;
}
*/
void mst_Prim(AMGraph<char> G, int k)
{
    cout << endl;
    for (int i = 0; i < G.vertexNum; i++)
    {
        G.minEdge[i].lowcost = G.edge[k][i];
        G.minEdge[i].adjvex = 0;
    }
    G.minEdge[k].lowcost = 0;
    for (int i = 1; i < G.vertexNum; i++)
    {
        k = shortEdge(G.minEdge, G.vertexNum);
        cout << G.vertex[k] << G.vertex[G.minEdge[k].adjvex]<<endl;
        cout << G.minEdge[k].lowcost<<endl;
        G.minEdge[k].lowcost = 0;
        for (int j = 0; j < G.vertexNum; j++)
        {
            if (G.edge[k][j] < G.minEdge[j].lowcost && G.minEdge[j].lowcost != 0)
            {
                G.minEdge[j].lowcost = G.edge[k][j];
                G.minEdge[j].adjvex = k;
            }
        }
    }
    cout << endl;
}

// Dijkstra算法成员函数
template <typename Element>
void AMGraph<Element>::Dijkstra(int start, int d[], int p[])
{
    bool visited[MaxSize] = { false };
    for (int i = 0; i < vertexNum; i++)
    {
        d[i] = edge[start][i];
        p[i] = (d[i] < INT_MAX) ? start : -1;
    }
    d[start] = 0;
    visited[start] = true;

    for (int i = 1; i < vertexNum; i++)
    {
        int min = INT_MAX, u = start;
        for (int j = 0; j < vertexNum; j++)
        {
            if (!visited[j] && d[j] < min)
            {
                u = j;
                min = d[j];
            }
        }
        visited[u] = true;
        for (int j = 0; j < vertexNum; j++)
        {
            if (!visited[j] && edge[u][j] < INT_MAX && d[u] + edge[u][j] < d[j])
            {
                d[j] = d[u] + edge[u][j];
                p[j] = u;
            }
        }
    }
}

int main()
{
    AMGraph<char> a;
    cout << "BFS:";
    a.bfTraverse(0);
    cout << endl;

    cout << "DFS:";
    a.dfTraverse(0);
    cout << endl;

    cout << "Prim:";
    mst_Prim(a, 2);
    cout << endl;

    int d[MaxSize]; //用于存储从起始顶点到图中每个其他顶点的最短距离。
    int p[MaxSize];//用于存储最短路径树中每个顶点的前驱节点索引。如果顶点i在最短路径树中的前驱节点是顶点j，则p[i]的值就是j。
    cout << "Dijkstra:";
    a.Dijkstra(0, d, p);
    for (int i = 0; i < 6; i++)
    {
        cout << "d[" << i << "]:" << d[i];
 //       cout << "  p[" << i << "]:" << p[i]<<endl;
    }

    return 0;
}

