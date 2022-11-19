#include <iostream>
#include <vector>
#include <List>
#include <queue>

using namespace std;

//Creating_Graph====================================================================================================================
class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int val, int wt)
    {
        this->v = val;
        this->w = wt;
    }

    Edge(){};
};

vector<vector<Edge *>> graph;
vector<vector<Edge *>> dgraph;

void AddCheck(int u, int v, int w)
{
    if (u >= graph.size() || u < 0 || v < 0 || v >= graph.size())
        return;

    graph[u].push_back(new Edge(v, w)); //bidirectional graph
    graph[v].push_back(new Edge(u, w));
}

void caseI()
{
    for (int i = 0; i < 6; i++)
    {
        vector<Edge *> arr;
        graph.push_back(arr);

        vector<Edge *> arr1;
        dgraph.push_back(arr1);
    }

    //Graph-1
    // AddCheck(0, 3, 10);
    // AddCheck(0, 1, 10);
    // AddCheck(1, 2, 10);
    // AddCheck(2, 3, 40);
    // AddCheck(3, 4, 2);
    // AddCheck(4, 5, 2);
    // AddCheck(4, 6, 3);
    // AddCheck(5, 6, 8);

    //Graph-2
    AddCheck(0, 1, 5);
    AddCheck(0, 2, 2);
    AddCheck(1, 2, 8);
    AddCheck(1, 3, 4);
    AddCheck(2, 4, 7);
    AddCheck(1, 4, 2);
    AddCheck(3, 4, 6);
    AddCheck(3, 5, 3);
    AddCheck(4, 5, 1);
}

void Display()
{
    for (int i = 0; i < dgraph.size(); i++)
    {
        cout << i << " => ";
        for (int j = 0; j < dgraph[i].size(); j++)
        {
            cout << "(" << dgraph[i][j]->v << "|" << dgraph[i][j]->w << ") ";
        }

        cout << endl;
    }
}

//Dijkstra=================================================================================================

class dpair
{
public:
    int vtx = 0;
    int pvtx = 0;
    int w = 0;
    int wsf = 0;
    string psf = "";

    dpair(int vtx, int pvtx, int w, int wsf, string psf)
    {
        this->vtx = vtx;
        this->pvtx = pvtx;
        this->w = w;
        this->wsf = wsf;
        this->psf = psf;
    }

    bool operator<(const dpair &o) const
    {
        // return this->wsf <o.wsf; //weak->strong->weak(upper). //max heap //
        //return this->wsf > o.wsf; //strong->weak->strong(down). //min heap //dijkstra
        return this->w > o.w; // for prims
    }

    dpair(){};
};

void AddCheck2(int u, int v, int w)
{
    if (u >= dgraph.size() || u < 0 || v < 0 || v >= dgraph.size())
        return;

    dgraph[u].push_back(new Edge(v, w)); //bidirectional graph
    dgraph[v].push_back(new Edge(u, w));
}

void dijkstra(int src)
{
    priority_queue<dpair> que;
    vector<bool> vis(graph.size(), false);
    int des = 5;
    bool Path = false;

    dpair root(src, -1, 0, 0, to_string(src));
    que.push(root);

    while (que.size() > 0)
    {
        dpair rpair = que.top();
        que.pop();

        if (vis[rpair.vtx])
            continue;

        if (rpair.vtx == des && !Path)
        {
            Path = true;
            cout << rpair.psf << " -> " << rpair.wsf << endl;
        }

        if (rpair.pvtx != -1)
            AddCheck2(rpair.vtx, rpair.pvtx, rpair.w);

        vis[rpair.vtx] = true;

        for (Edge *e : graph[rpair.vtx])
        {
            if (!vis[e->v])
            {
                dpair npair(e->v, rpair.vtx, e->w, e->w + rpair.wsf, rpair.psf + " " + to_string(e->v));
                que.push(npair);
            }
        }
    }

    Display();
}

//Prims=====================================================================================================================

void prims(int src)
{

    priority_queue<dpair> que;
    vector<bool> vis(graph.size(), false);
    int des = 5;
    bool Path = false;

    dpair root(src, -1, 0, 0, to_string(src));
    que.push(root);

    while (que.size() > 0)
    {
        dpair rpair = que.top();
        que.pop();

        if (vis[rpair.vtx])
            continue;

        if (rpair.vtx == des && !Path)
        {
            Path = true;
            cout << rpair.psf << " -> " << rpair.wsf << endl;
        }

        if (rpair.pvtx != -1)
        {
            AddCheck2(rpair.vtx, rpair.pvtx, rpair.w);
        }

        vis[rpair.vtx] = true;

        for (Edge *e : graph[rpair.vtx])
        {
            if (!vis[e->v])
            {
                dpair npair(e->v, rpair.vtx, e->w, e->w + rpair.wsf, rpair.psf + " " + to_string(e->v));
                que.push(npair);
            }
        }
    }

    Display();
}

int main(int args, char **argv)
{
    caseI();
    //dijkstra(0);
    prims(0);
}