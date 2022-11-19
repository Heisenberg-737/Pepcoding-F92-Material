public class pairtriplet {

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 10, 11, 12, 13, 14, 15 };

        int data = 16;

        check(arr, data);

    }

    public static void check(int[] arr, int data) {
        for (int i = 0; i < arr.length - 2; i++) {
            int li = i + 1;
            int ri = arr.length - 1;

            while (li < ri) {
                int sum = arr[i] + arr[li] + arr[ri];

                if (sum == data) {
                    System.out.println("(" + arr[i] + " , " + arr[li] + " , " + arr[ri] + ")");
                    li++;
                }
                if (sum < data)
                    li++;
                else
                    ri--;
            }
        }

    }
}