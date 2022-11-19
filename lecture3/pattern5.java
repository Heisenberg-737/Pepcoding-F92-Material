import java.util.Scanner;

public class pattern5 {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

        System.out.print("Enter number of rows: ");
        int rows = scn.nextInt();

        fulldiamond(rows);
    }

    public static void fulldiamond(int n) {
        int nst = 1;
        int nsp = n - 1;

        for (int r = 1; r <= n; r++) {
            int m = r;

            if (r > (n + 1) / 2)
                m = n - r + 1;

            for (int csp = 1; csp <= nsp; csp++)
                System.out.print(" ");

            for (int cst = 1; cst <= nst; cst++) {
                if (cst <= nst / 2) {
                    System.out.print(m++);
                } else
                    System.out.print(m--);
            }

            if (r <= n / 2) {
                nst += 2;
                nsp--;
            } else {
                nst -= 2;
                nsp++;
            }
            System.out.println();
        }
    }
}