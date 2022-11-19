public class shoesearch {

    public static void main(String[] args)
    {
        int[] arr={1,1,2,2,3,3,4,4,5,5,6,6,7,8,8,9,9};

        shoe(arr);
    }

    public static int shoe (int[] arr)
    {
        int li=0;
        int ri=arr.length-1;

        while(li<=ri)
        {
            int mid=(li+ri)/2;

            if(arr[mid]==) return mid;

            if(arr[mid]<data) li=mid+1;
            else ri=mid-1;
        }

        return -1;

    }
}