public class binarysearchupper {

    public static void main(String[] args) {
        int[] arr = { -2, 0, 2, 2, 2, 2, 2, 2, 2, 3, 3, 5, 7, 9, 12, 22, 33, 34, 46, 56, 67, 89, 92 };

        if (BS(arr, 2) == -1)
            System.out.println("Integer not found!!");
        else
            System.out.println("Integer was found at: " + (BS(arr, 2) + 1));

    }

    public static int BS(int[] arr, int data) {
        int li = 0;
        int ri = arr.length - 1;

        while (li <= ri) {
            int mid = (li + ri) / 2;

            if (arr[mid] == data) {
                if (mid + 1 < arr.length && arr[mid] == arr[mid + 1])
                    li = mid + 1;
                else
                    return mid;

            }

           else  if (arr[mid] < data)
                li = mid + 1;
            else
                ri = mid - 1;
        }

        return -1;

    }
}