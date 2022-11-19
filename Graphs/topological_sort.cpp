#include <iostream>
#include <vector>
#include <List>
#include <queue>

using namespace std;

class Edge
{
public:
    int u = 0;
    int v = 0;

    Edge(int u, int v)
    {
        this->u = u;
        this->v = v;
    }

    Edge(){};
};

vector<vector<Edge *>> graph(7, vector<Edge *>());

void addEdge(int u, int v)
{
    graph[u].push_back(new Edge(u, v));
}

void Display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " : ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "(" << graph[i][j]->u << " -> " << graph[i][j]->v << ")";
        }

        cout << endl;
    }
}

void create()
{
    //Graph-1
    // addEdge(0, 1);
    // addEdge(1, 2);
    // addEdge(2, 3);
    // addEdge(0, 5);
    // addEdge(4, 5);
    // addEdge(4, 6);
    // addEdge(6, 3);

    //Graph-2
    addEdge(7, 5);
    addEdge(7, 6);
    addEdge(5, 4);
    addEdge(5, 2);
    addEdge(6, 4);
    addEdge(6, 3);
    addEdge(2, 1);
    addEdge(3, 1);
    addEdge(1, 0);
}

void topo_sort(int src, vector<int> &st, vector<bool> &vis)
{
    vis[src] = true;

    for (Edge *e : graph[src])
    {
        if (!vis[src])
            topo_sort(e->v, st, vis);
    }

    //post area
    st.push_back(src);
}

void TopologicalSort()
{
    vector<int> st;
    vector<bool> vis(graph.size(), false);

    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
        {
            topo_sort(i, st, vis);
        }
    }

    for (int i = st.size() - 1; i >= 0; i--)
        cout << st[i] << " ";
}

//for_cycle_detection=====================================================================================================

bool topo_sortcycle(int src, vector<int> &st, vector<bool> &vis, vector<bool> &cycle)
{
    vis[src] = true;
    cycle[src] = true;
    bool res = false;

    for (Edge *e : graph[src])
    {
        if (!vis[src])
            res = res || topo_sortcycle(e->v, st, vis, cycle);

        else if (cycle[e->v])
            return false;
    }

    //post area
    st.push_back(src);
    cycle[src] = false;
    return true;
}

void TopologicalSortcycle()
{
    vector<int> st;
    vector<bool> vis(graph.size(), false);
    vector<bool> cycle(graph.size(), false);

    bool res = true;

    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
        {
            res = res || topo_sortcycle(i, st, vis, cycle);
        }
    }

    for (int i = st.size() - 1 && !res; i >= 0; i--)
        cout << st[i] << " ";
}

//=============================================================================================================================

void KahnsAlgo()
{
    list<int> que;
    for (int i = 0; i < inc.size(); i++)
    {
        if (inc[i] == 0)
        {
            que.push_back(i);
        }
    }

    while (!que.empty())
    {
        int n = que.front();
        que.pop_front();

        if (inc[n] == 0)
        {
            ans.push_back(n);
        }

        for (Edge *e : graph[src])
        {
            inc[e->v] -= 1;
            if (inc[e->v] == 0)
                que.push_back(e->v);
        }
    }
}

int main(int args, char **argv)
{
    create();
    //Display();

    //TopologicalSort();
    //TopologicalSortcycle();
    return 0;
}