public class pairssum{

    public static void main(String[] args)
    {
        int[] arr={1,2,3,4,10,12,14,15};
        
        int data=16;

        check(arr,data);

    }

    public static void check(int[] arr,int data)
    {
        int li=0;
        int ri=arr.length-1;

        while(li<=ri)
        {
            int sum=arr[li]+arr[ri];
            if(sum==data)
            {
                System.out.println("("+arr[li]+" , "+arr[ri]+")");
                li++;
            }
            if(sum<data) li++;
            else ri--;
        }

    }
} 