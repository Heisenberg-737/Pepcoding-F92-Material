public class fibbo
{
    public static void main(String[] args)
    {
        System.out.println(fib(6));
    }

    public static int fib(int n)
    {
        if(n==0) return 0;
        else if(n==1) return 1;
        else return fib(n-1)+fib(n-2);
    }
}