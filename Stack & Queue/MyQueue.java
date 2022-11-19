public class MyQueue {
    private int[] arr;
    private int st = 0;
    private int end = 0;
    private int size = 0;

    MyQueue() {
        this.arr = new int[10];
    }

    MyQueue(int size) {
        this.arr = new int[size];
    }

    public int size() {
        return this.size();
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public int front() {
        if (this.size == 0) {
            System.err.println("Queue is Empty!!");
            return -1;
        }

        return arr[st];
    }

    public void push(int data) {
        if (this.size == this.arr.length) {
            System.err.println("Queue is overflow!!");
            return;
        }

        this.arr[this.end] = data;

        this.end = (this.end + 1) % this.arr.length;
        this.size++;
    }

    public int pop() {
        if (this.size == 0) {
            System.err.println("Queue is Empty!!");
            return -1;
        }

        int rv = this.arr[this.st];
        this.arr[this.st] = 0;

        this.size--;
        this.st = (this.st + 1) % this.arr.length;

        return rv;
    }

    public void print() {
        if (this.size == 0) {
            System.err.println("Queue is Empty!!");
            return;
        }

        for (int i = st; i < end - 1; i++) {
            System.out.print(arr[i] + "-->");
        }
        System.out.println(arr[end - 1]);
    }

}