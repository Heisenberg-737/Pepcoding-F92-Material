public class Client {

    public static void main(String[] args) {
        // Stack st1 = new Stack();

        // st1.push(10);
        // st1.push(20);
        // st1.push(56);
        // st1.push(12);
        // st1.push(17);
        // st1.push(1);

        // st1.print();

        // System.out.println(st1.pop() + " is removed!!");

        // st1.print();

        // MyQueue q1 = new MyQueue();

        DynamicStack st = new DynamicStack();
        for (int i = 0; i < 30; i++) {
            st.push(i + 100);
        }

        st.print();

    }
}