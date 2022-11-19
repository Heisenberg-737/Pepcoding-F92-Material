import java.util.Scanner;

public class bits3
{
    public static Scanner scn=new Scanner(System.in);

    public static void main(String[] args)
    {
         
        // int[] arr={5,2,8,7,14,10,7,5,8};

        System.out.println(OntoOff());;
          
    }

    public static int OntoOff()
    {
        int a=scn.nextInt();
        int k=scn.nextInt();

        int mask=(1<<k);

        a|=mask;

        return a;

    }
    
    /*
    public static void noofsetbits_03(int n)
    {
        int count=0;

        while(n!=0)
        {
            n&=(n-1);
            count++;
        }

        System.out.println(count);
    }

    public static void uniqueforK(int[] arr,int k)
    {
        int[] bits=new int[32];

        for(int ele:arr)
        {
            for(int i=0;i<32;i++)
            {
                int mask=(1>>i);

                if((ele&i)!=0)
                {
                    bits[i]++;
                }

            }
        }

        for(int ele:bits) System.out.println(ele+" ");
    }

    */
}
