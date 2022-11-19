import java.util.Scanner;
public class factorial{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args)
    {
        System.out.println("Enter value of n for factorial: ");
        int n=scn.nextInt();

            System.out.println("Factorial= "+fact(n));

        ncr();
    }

    public static int fact(int n)
{
    int r=1;

    for(int i=2;i<=n;i++)
    {
        r*=i;
    }

    return r;
}
    
public static void ncr()
{
    int n,r;

    System.out.println("Enter n and r:");
    n=scn.nextInt();
    r=scn.nextInt();

    int ans=fact(n)/((fact(n-r))*(fact(r)));

    System.out.println("Answer of Combination= "+ans);
}
}