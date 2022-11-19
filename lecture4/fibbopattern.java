import java.util.Scanner;

public class fibbopattern{
    public static Scanner scn=new Scanner(System.in);

public static void pattern(int n)
{
    int nst=1;
    int f=0;
    int t,s=1;

    System.out.println(f+" ");
    System.out.print(s+" ");

    for(int r=1;r<=n-1;r++)
    {
        
        for(int cst=1;cst<=nst;cst++){
          t=f+s;  
          System.out.print(t+" ");
          f=s;
          s=t;
        }
        if(r==1) nst+=2;
        else nst++;
        System.out.println();
    }

}

public static void main(String[] args)
{
    System.out.print("Enter a number: ");
    int rows=scn.nextInt();

    pattern(rows);
    
}
}