public class DynamicStack extends Stack {
    private int[] st;
    private int idx = -1;

    DynamicStack() {
        this.st = new int[10];
    }

    DynamicStack(int size) {
        super(size);
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

    @Override
    public void push(int data) {
        if (this.idx == st.length - 1) {
            int[] temp = new int[this.st.length * 2];
            for (int i = 0; i < st.length; i++) {
                temp[i] = st[i];
            }

            this.st = temp;
        }

        super.push(data);
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