import java.util.LinkedList;

public class HashMap {
    public class Node {
        Integer key;
        Integer val;

        Node(Integer key, Integer val) {
            this.key = key;
            this.val = val;
        }
    }

    LinkedList<Node>[] buckets = new LinkedList<Node>[10];

    HashMap() {
        for (Integer i = 0; i < buckets.length; i++)
            buckets[i] = new LinkedList<>();
    }

    public Node foundInGroup(LinkedList<Node> bucket,Integer key)
    {
        Node rn=null;
        int size=bucket.size();

        while(size-->0)
        {
            Node tnode=bucket.getFirst();
            if(tnode.key==key)
            {
                rn=tnode;
                break;
            }
        }

        bucket.addLast(bucket.removeFirst());
    }

    return rn;

}