
// Heap Sort
// T.C. -> O(nlogn)

public class HeapSort {

    // Max - Heapify Algorithm
    static void maxHeapify(int arr[], int n, int i) {

        int largestIndex = i;
        int leftIndex = i * 2;
        int rightIndex = i * 2 + 1;

        if (leftIndex <= n && arr[leftIndex] > arr[largestIndex]) {
            largestIndex = leftIndex;
        }
        if (rightIndex <= n && arr[rightIndex] > arr[largestIndex]) {
            largestIndex = rightIndex;
        }

        if (largestIndex != i) {
            int temp = arr[i];
            arr[i] = arr[largestIndex];
            arr[largestIndex] = temp;
            maxHeapify(arr, n, largestIndex);
        }
    }

    // Heap Sort
    static void heapSort(int arr[], int n) {

        int size = n;

        while (size > 1) {
            // step 1: swap root node with last node
            int temp = arr[1];
            arr[1] = arr[size];
            arr[size] = temp;

            size--;

            // step 2: Take root node to its correct position (Heapify)
            maxHeapify(arr, size, 1);
        }

    }

    public static void main(String[] args) {

        int arr[] = { -1, 52, 53, 50, 54, 55 };
        int n = 5;

        // Max Heap Creation
        for (int i = n / 2; i > 0; i--) {
            maxHeapify(arr, n, i);
        }

        // Heap Sort
        heapSort(arr, n);

        for (int i = 1; i <= n; i++) {
            System.out.print(arr[i] + " ");
        }
    }

}