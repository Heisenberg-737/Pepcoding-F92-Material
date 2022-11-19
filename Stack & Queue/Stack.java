public class Stack {
    private int[] st;
    private int idx = -1;

    Stack() {
        this.st = new int[10];
    }

    Stack(int size) {
        this.st = new int[size];
    }

    public void print() {
        System.out.print("[");

        for (int i = idx; i > 0; i--)
            System.out.print(st[i] + ",");

        System.out.println(st[0] + "]");
    }

    public int size() {
        return idx + 1;
    }

    public boolean isEmpty() {
        return idx == -1;
    }

    public int top() {
        if (idx == -1) {
            System.out.println("Stack is Empty!!");
            return -1;
        }

        return st[idx];
    }

    public void push(int data) {
        if (this.idx == st.length) {
            System.out.println("Stack is full!!");
            return;
        }

        idx++;
        this.st[idx] = data;
    }

    public int pop() {
        if (this.idx == -1) {
            System.out.println("Stack is Empty");
            return -1;
        }

        int rv = this.st[idx];
        this.st[idx] = 0;

        return rv;
    }

}