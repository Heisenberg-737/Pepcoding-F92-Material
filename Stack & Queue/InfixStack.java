import java.util.Stack;

public class InfixStack {

    public static void main(String[] args) {

    }

    public static boolean isOperator(char ch) {
        if ((ch == '+') && (ch == '-') && (ch == '*') && (ch == '/') && (ch == '^') && (ch == '%'))
            return true;

        return false;
    }

    public static int priority(char ch) {
        if ((ch == '+') || (ch == '-'))
            return 0;

        else if ((ch == '*') || (ch == '/') || (ch == '%'))
            return 1;

        else if (ch == '^')
            return 2;

        return -1;
    }

    public static int performOperation(int val1, int val2, char ch) {
        if (ch == '+')
            return val2 + val1;
        else if (ch == '-')
            return val2 - val1;
        else if (ch == '*')
            return val2 * val1;
        else if (ch == '/')
            return val2 / val1;
        else if (ch == '%')
            return val2 % val1;
        else
            return (int) Math.pow(val2, val1);
    }

    public static int InfixEval(String str) {
        Stack<Integer> numSt = new Stack<>();
        Stack<Character> opSt = new Stack<>();

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch >= '0' && ch <= '9')
                numSt.push(ch - '0');
            else if (ch == '(')
                opSt.push(ch);
            else if (isOperator(ch)) {
                while (opSt.size() != 0 && opSt.peek() != '(' && priority(opSt.peek()) > priority(ch)) {
                    int val1 = numSt.pop();
                    int val2 = numSt.pop();
                    char c = opSt.pop();

                    int ans = performOperation(val1, val2, c);
                    numSt.push(ans);
                }
                opSt.push(ch);
            } else {
                while (opSt.peek() != '(') {
                    int val1 = numSt.pop();
                    int val2 = numSt.pop();
                    char c = opSt.pop();

                    int ans = performOperation(val1, val2, c);
                    numSt.push(ans);
                }

                opSt.pop();
            }
        }

        while (opSt.size() != 0) {
            int val1 = numSt.pop();
            int val2 = numSt.pop();
            Character c = opSt.pop();

            int ans = performOperation(val1, val2, c);
            numSt.push(ans);

        }

        return numSt.pop();
    }
}
