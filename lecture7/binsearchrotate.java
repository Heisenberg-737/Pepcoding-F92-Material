public class binsearchrotate {

    public static void main(String[] args)
    {
        int[] arr={3,4,5,1,2};
        int data=3;
        int p=pivot(arr,data,0,arr.length-1);

        System.out.println(p);


        if(arr[p]>=data) System.out.println("Index found at: "+BS(arr,data,0,p));
        else System.out.println("Index found at: "+BS(arr,data,p+1,arr.length-1));
        
    }

    public static int BS (int[] arr,int data,int li,int ri)
    {

        while(li<=ri)
        {
            int mid=(li+ri)/2;

            if(arr[mid]==data)
                     return mid;

            if(arr[mid]<data) li=mid+1;
            else ri=mid-1;
        }

        return -1;

    }

    public static int pivot (int[] arr,int data,int li,int ri)
    {   
        int mid=(li+ri)/2;
        while(li<=ri)
        {
            mid=(li+ri)/2;

            if(arr[mid]>=arr[ri] && arr[mid]>=arr[li])
                     break;

            else if(arr[mid]<data) li=mid+1;
            else ri=mid-1;
        }


        return mid;

    }
}
