public class HeapSort {

    public static void heapSort(int[] arr, boolean isMax) {
        for (int i = arr.length - 1; i >= 0; i--)
            downHeapify(arr, i, arr.length - 1, isMax);

        for (int i = 0; i < arr.length; i++) {
            
        }

        for (int ele : arr)
                System.out.print(ele + " ");

        
    }

    public static void downHeapify(int arr[], int idx, int x, boolean isMax) {
        int maxidx = idx;
        int lci = 2 * idx + 1;
        int rci = 2 * idx + 2;

        if (lci < arr.length && compareTo(arr[lci], arr[maxidx], isMax) > 0) {
            maxidx = lci;
        }

        if (rci < arr.length && compareTo(arr[rci], arr[maxidx], isMax) > 0) {
            maxidx = rci;
        }

        if (maxidx != idx) {
            swap(maxidx, idx);
            downHeapify(arr, maxidx);
        }
    }

    public int compareTo(int val1, int val2, boolean isMax) {
        if (isMax) {
            return (val1 - val2);
        } else {
            return val2 - val1;
        }
    }

    public void swap(int arr[], int x, int y) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
    }

}