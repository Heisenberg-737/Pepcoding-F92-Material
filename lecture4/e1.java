import java.util.Scanner;

public class e1{
    public static Scanner scn=new Scanner(System.in);

    public static void main(String[] args)
    {
        System.out.print("Enter size of array: ");
        int n=scn.nextInt();

        int[] arr=new int[n];

        System.out.print("\nEnter values in the array: ");
        for(int i=0;i<n;i++) arr[i]=scn.nextInt();

        display(arr);
    }

    public static void display(int[] arr)
    {
        System.out.print("\nDisplaying the array: ");

        for(int i=0;i<arr.length;i++) System.out.print(arr[i]+" ");
    }
}