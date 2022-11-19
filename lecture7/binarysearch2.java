public class binarysearch2 {

    public static void main(String[] args)
    {
        int[] arr={-2,0,2,2,2,2,2,2,2,3,3,5,7,9,12,22,33,34,46,56,67,89,92};

        System.out.println("Integer was found at/closest at: "+(BS(arr,80)+1));

    }

    public static int BS (int[] arr,int data)
    {
        int li=0;
        int ri=arr.length-1;

        while(li<=ri)
        {
            int mid=(li+ri)/2; 
            if(arr[mid]==data) return mid;

            if(arr[mid]<data) li=mid+1;
            else ri=mid-1;
        }

        if((data-arr[ri])<=(arr[li]-data)) return ri;
        else return li;

    }
}