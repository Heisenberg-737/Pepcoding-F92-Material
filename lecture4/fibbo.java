import java.util.Scanner;

public class fibbo{
    public static Scanner scn=new Scanner(System.in);

    public static void main(String[] args)
    {
        System.out.print("Enter a number: ");
        int n=scn.nextInt();

        fib(n);

        char a=65;
        System.out.print(++a);
    }

    public static void fib(int n)
    {
        int f=0;
        int t,s=1;

        System.out.print(f+" "+s+" ");

        for(int i=0;i<n-2;i++)
        {
            t=f+s;
            System.out.print(t+" ");

            f=s;
            s=t;
        }

    }
}    