import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

public class ArticulationPoint {
    public static Scanner scn = new Scanner(System.in);
    public static ArrayList<Edge>[] graph = new ArrayList[7];

    public static void main(String[] args) {
        caseI();
        // Display();
        Arrays.fill(dis, -1);
        root = 0;
        AP(0, -1);
        vis[0] = root > 1 ? true : false;

        for (int i = 0; i < graph.length; i++) {
            if (vis[i])
                System.out.println(i);
        }
    }

    public static class Edge {
        int v = 0;
        int w = 0;

        Edge(int v, int w) {
            this.v = v;
            this.w = w;
        }

        Edge() {
        };
    }

    public static void caseI() {
        for (int i = 0; i < graph.length; i++)
            graph[i] = new ArrayList<Edge>();

        AddCheck(0, 3, 10);
        AddCheck(0, 1, 10);
        AddCheck(1, 2, 10);
        AddCheck(2, 3, 40);
        AddCheck(3, 4, 2);
        AddCheck(4, 5, 2);
        AddCheck(4, 6, 3);
        AddCheck(5, 6, 8);

    }

    public static void Display() {
        for (int i = 0; i < graph.length; i++) {
            System.out.print(i + "=>");
            for (int j = 0; j < graph[i].size(); j++) {
                System.out.print("(" + graph[i].get(j).v + "|" + graph[i].get(j).w + ") ");
            }

            System.out.println();
        }
    }

    public static void AddCheck(int u, int v, int w) {
        if (u >= graph.length || u < 0 || v < 0 || v >= graph.length)
            return;

        graph[u].add(new Edge(v, w));
        graph[v].add(new Edge(u, w));
    }

    public static int[] par = new int[graph.length];
    public static int[] low = new int[graph.length];
    public static int[] dis = new int[graph.length];
    public static boolean[] vis = new boolean[graph.length];
    public static int time = 0;
    public static int root = 0;

    public static void AP(int vtx, int parent) {

        dis[vtx] = low[vtx] = time++;

        for (Edge e : graph[vtx]) {
            if (dis[e.v] == -1) {
                par[e.v] = vtx;
                root++;

                AP(e.v, vtx);

                if (dis[vtx] <= low[e.v])
                    vis[vtx] = true;

                low[vtx] = Math.min(low[vtx], low[e.v]);

            } else if (par[vtx] != e.v)
                low[vtx] = Math.min(low[vtx], dis[e.v]);

        }
    }

}