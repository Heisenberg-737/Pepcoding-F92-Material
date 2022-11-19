import java.util.Scanner;

public class pascaltriangle{
    public static Scanner scn=new Scanner(System.in);


    public static void pattern(int rows)
    {
      for(int n=0;n<=rows;n++)
      {
        int val=1;
        for(int r=0;r<=n;r++)
       {
         System.out.print(val+" ");
         val=(val*(n-r))/(r+1);
       }

       System.out.println();
     }  

    }

public static void main(String[] args)
  {
    System.out.print("Enter number of rows: ");
    int rows=scn.nextInt();

    pattern(rows);

  }

}