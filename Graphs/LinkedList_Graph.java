import java.util.Scanner;
import java.util.ArrayList;
import java.util.LinkedList;

public class LinkedList_Graph {
    public static Scanner scn = new Scanner(System.in);
    public static ArrayList<Edge>[] graph = new ArrayList[7];

    // BFSpair======================================================================================================================

    public static class BFSpair {
        int vtx = 0;
        int wsf = 0;
        String psf = "";

        BFSpair(int v, int wsf, String psf) {
            this.vtx = v;
            this.wsf = wsf;
            this.psf = psf;
        }
    }

    public static void BFS_ShortestPath_00(int src, int des) {
        LinkedList<BFSpair> que = new LinkedList<>();
        boolean[] visited = new boolean[graph.length]; // by default all are marked false

        BFSpair root = new BFSpair(src, 0, src + "");

        que.addLast(root);

        int cycleCounter = 0;
        boolean isPath = false;

        while (que.size() != 0) {
            BFSpair removepair = que.removeFirst();

            // Cycle
            if (visited[removepair.vtx]) {
                System.out.println("CycleNumber:" + cycleCounter++ + " @ " + removepair.psf);
            }

            visited[removepair.vtx] = true; // mark

            if (removepair.vtx == des && !isPath) {
                System.out.println(removepair.psf);
                isPath = true;
            }

            for (Edge e : graph[removepair.vtx]) {
                int vtx = e.u;

                if (!visited[vtx]) {
                    BFSpair pair = new BFSpair(e.u, removepair.wsf + e.w, removepair.psf + "-->" + e.u);
                    que.addLast(pair);
                }
            }

        }
    }

    public static void BFS_ShortestPath_01(int src, int des) {
        LinkedList<BFSpair> que = new LinkedList<>();
        boolean[] visited = new boolean[graph.length];

        BFSpair root = new BFSpair(src, 0, src + "");

        que.addLast(root);
        que.addLast(null);

        int cycleCounter = 0;
        boolean isPath = false;
        int level = 1;

        while (que.size() != 1) {
            BFSpair removepair = que.removeFirst();

            // Cycle
            if (visited[removepair.vtx]) {
                System.out.println("CycleNumber:" + cycleCounter++ + " @ " + removepair.psf);
            }

            visited[removepair.vtx] = true; // mark

            if (removepair.vtx == des && !isPath) {
                System.out.println(removepair.psf + " Level: " + level);
                isPath = true;
            }

            for (Edge e : graph[removepair.vtx]) {
                int vtx = e.u;

                if (!visited[vtx]) {
                    BFSpair pair = new BFSpair(e.u, removepair.wsf + e.w, removepair.psf + "-->" + e.u);
                    que.addLast(pair);
                }
            }

            if (que.getFirst() == null) {
                que.removeFirst();
                que.addLast(null);
                level++;
            }

        }
    }

    public static void BFS_ShortestPath_02(int src, boolean[] visited) {
        LinkedList<BFSpair> que = new LinkedList<>();

        BFSpair root = new BFSpair(src, 0, src + "");

        que.addLast(root);

        int cycleCounter = 0;
        boolean isPath = false;
        int level = 1;
        int des = 6;

        while (que.size() != 0) {

            int size = que.size();
            while (size-- > 0) { // automatically decreases the size
                BFSpair removepair = que.removeFirst();

                // Cycle
                if (visited[removepair.vtx]) {
                    System.out.println("CycleNumber:" + cycleCounter++ + " @ " + removepair.psf);
                }

                visited[removepair.vtx] = true; // mark

                if (removepair.vtx == des && !isPath) {
                    System.out.println(removepair.psf + " Level: " + level);
                    isPath = true;
                }

                for (Edge e : graph[removepair.vtx]) {
                    int nbr = e.u;

                    if (!visited[nbr]) { // checking for unmarked nbr's
                        BFSpair pair = new BFSpair(e.u, removepair.wsf + e.w, removepair.psf + "-->" + e.u);
                        que.addLast(pair);
                    }
                }

            }
            level++;

        }
    }

    // Disjoint-Graphs==================================================================================================================
    public static void Disjoint_Graphs() {
        int count = 0;
        boolean[] visited = new boolean[graph.length];

        for (int i = 0; i < graph.length; i++) {
            if (!visited[i]) {
                BFS_ShortestPath_02(i, visited);
                count++;
            }
        }

        System.out.println("Dis-jointed Graphs=" + count);
    }

    // CreatingGraph=====================================================================================================================
    public static void main(String[] args) {
        caseI();
        // Display();
        // BFS_ShortestPath_02(0, 6);

        Disjoint_Graphs();
    }

    public static class Edge {
        int u = 0;
        int w = 0;

        Edge(int u, int w) {
            this.u = u;
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
                System.out.print("(" + graph[i].get(j).u + "|" + graph[i].get(j).w + ") ");
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

    // ====================================================================================================================================

}