#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

vector<vector<Edge *>> graph(7, vector<Edge *>());

void AddCheck(int u, int v, int w)
{
    if (u >= graph.size() || u < 0 || v < 0 || v >= graph.size())
        return;

    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

void caseI()
{

    AddCheck(0, 3, 10);
    AddCheck(0, 1, 10);
    AddCheck(1, 2, 10);
    AddCheck(2, 3, 40);
    AddCheck(3, 4, 2);
    AddCheck(4, 5, 2);
    AddCheck(4, 6, 3);
    AddCheck(5, 6, 8);
}

void Display()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " => ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "(" << graph[i][j]->v << "|" << graph[i][j]->w << ") ";
        }

        cout << endl;
    }
}

bool hasPath(int src, int des, vector<bool> &visited, string ans)
{
    if (visited[src])
        return false;

    if (src == des)
    {
        cout << ans << endl;
        return true;
    }

    visited[src] = true;
    bool res = false;
    for (Edge *e : graph[src])
    {
        int v = e->v;
        res = res || hasPath(v, des, visited, ans + to_string(v) + "->");
    }

    return res;
}

void hasPath_allPath(int src, int des, vector<bool> &visited, string ans)
{
    if (visited[src])
        return;

    if (src == des)
    {
        cout << ans << endl;
        return;
    }

    visited[src] = true; //mark
    for (Edge *e : graph[src])
    {
        int v = e->v;
        hasPath_allPath(v, des, visited, ans + to_string(v) + "->");
    }

    visited[src] = false; //unmark
}

//Pre-Order Path===========================================================================================================

void PreOrder_Path(int src, vector<bool> &visited, string ans)
{
    visited[src] = true; //mark

    cout << to_string(src) + "->" + ans + to_string(src) << endl;

    for (Edge *e : graph[src])
    {
        int v = e->v;
        if (!visited[v])
            PreOrder_Path(v, visited, ans + to_string(src) + "->");
    }

    visited[src] = false; //unmark
}

//Post-Order Path============================================================================================================

void PostOrder_Path(int src, vector<bool> &visited, string ans)
{
    visited[src] = true; //mark

    for (Edge *e : graph[src])
    {
        int v = e->v;
        if (!visited[v])
            PostOrder_Path(v, visited, ans + to_string(src) + "->");
    }

    cout << to_string(src) + "->" + ans + to_string(src) << endl;

    visited[src] = false; //unmark
}

//Wt PreOrder_Path=========================================================================================================================

void Wt_PreOrder_Path(int src, int w, vector<bool> &visited, string ans)
{
    visited[src] = true; //mark

    cout << to_string(src) + "->" + ans + to_string(src) + " @ " + to_string(w) << endl;

    for (Edge *e : graph[src])
    {
        int v = e->v;
        int wt = e->w;
        if (!visited[v])
            Wt_PreOrder_Path(v, w + wt, visited, ans + to_string(src) + "->");
    }

    visited[src] = false; //unmark
}

//Wt_PostOrder_Path==========================================================================================================================

void Wt_PostOrder_Path(int src, int w, vector<bool> &visited, string ans)
{
    visited[src] = true; //mark

    for (Edge *e : graph[src])
    {
        int v = e->v;
        int wt = e->w;
        if (!visited[v])
            Wt_PostOrder_Path(v, w + wt, visited, ans + to_string(src) + "->");
    }

    cout << to_string(src) + "->" + ans + to_string(src) + " @ " + to_string(w) << endl;

    visited[src] = false; //unmark
}

//Lightest PreOrder_Path=======================================================================================================================

int fwt = INT8_MAX;
string fans = "";

void Lightest_Wt_PreOrder_Path(int src, int des, int w, vector<bool> &visited, string ans)
{
    if (src == des)
    {
        if (w < fwt)
        {
            fwt = w;
            fans = ans + to_string(src);
        }

        return;
    }

    visited[src] = true; //mark

    //cout << to_string(src) + "->" + ans + to_string(src) + " @ " + to_string(w) << endl;

    for (Edge *e : graph[src])
    {
        int v = e->v;
        int wt = e->w;
        if (!visited[v])
            Lightest_Wt_PreOrder_Path(v, des, w + wt, visited, ans + to_string(src) + "->");
    }

    visited[src] = false; //unmark
}

//Second approach for LightestPath
class pair_path
{

public:
    int wt = INT8_MAX;
    string s = "";
    pair_path(int wt, string s)
    {
        this->wt = wt;
        this->s = s;
    }

    pair_path(){};
};

pair_path *lightestPath_01(int src, int dest, vector<bool> &vis)
{
    if (src == dest)
    {
        pair_path *obj = new pair_path(0, to_string(src) + "");
        return obj;
    }

    vis[src] = true;
    pair_path *myAns = new pair_path();

    for (Edge *e : graph[src])
    {
        int nbr = e->v;
        int w = e->w;
        if (!vis[nbr])
        {
            pair_path *recRes = lightestPath_01(nbr, dest, vis);
            if (recRes->wt + w < myAns->wt)
            {
                myAns->wt = recRes->wt + w;
                myAns->s = to_string(src) + recRes->s;
            }
        }
    }

    vis[src] = false;
    return myAns;
}

//HamiltanionPath===========================================================================================================================

void hamintonianPathCycle(int src, int osrc, int cnt, int wt, vector<bool> &vis, string ans)
{
    if (cnt == graph.size() - 1)
    {
        cout << ans + to_string(src);
        for (Edge *e : graph[src])
        {
            if (e->v == osrc)
            {
                cout << " -> Cycle";
            }
        }
        cout << endl;
        return;
    }

    //mark.
    vis[src] = true;
    for (Edge *e : graph[src])
    {
        int nbr = e->v;
        int w = e->w;
        if (!vis[nbr])
        {
            hamintonianPathCycle(nbr, osrc, cnt + 1, wt + w, vis, ans + to_string(src));
        }
    }

    vis[src] = false;
}

//==========================================================================================================================================

int main(int args, char **argv)
{
    caseI();
    //Display();

    // int des;
    // cout << "Enter the Destination vertex: ";
    // cin >> des;

    vector<bool> visited(graph.size(), false);
    //hasPath(0, 6, visited, to_string(0) + "->");
    // PreOrder_Path(0, 6, visited, "");
    //PostOrder_Path(0, visited, "");
    // Wt_PreOrder_Path(0, 0, visited, "");
    //Wt_PostOrder_Path(0, 0, visited, "");
    // Lightest_Wt_PreOrder_Path(0, 6, 0, visited, "");
    // cout << fans << " @ " << fwt << endl;

    // pair_path *ans = lightestPath_01(0, 6, visited);
    // cout << ans->s << " -> " << ans->wt << endl;

    return 0;
}