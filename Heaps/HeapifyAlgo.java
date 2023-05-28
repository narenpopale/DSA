
// Heapify Algorithm 
// T.C.-> O(log n)

import java.util.*;

public class HeapifyAlgo {

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

        // Swap and Apply heapify for below sub tree
        if (largestIndex != i) {
            int temp = arr[i];
            arr[i] = arr[largestIndex];
            arr[largestIndex] = temp;
            maxHeapify(arr, n, largestIndex);
        }
    }

    // Min - Heapify Algorithm
    static void minHeapify(int arr[], int n, int i) {

        int smallestIndex = i;
        int leftIndex = i * 2;
        int rightIndex = i * 2 + 1;

        if (leftIndex <= n && arr[leftIndex] < arr[smallestIndex]) {
            smallestIndex = leftIndex;
        }
        if (rightIndex <= n && arr[rightIndex] < arr[smallestIndex]) {
            smallestIndex = rightIndex;
        }

        // Swap and Apply heapify for below sub tree
        if (smallestIndex != i) {
            int temp = arr[i];
            arr[i] = arr[smallestIndex];
            arr[smallestIndex] = temp;
            minHeapify(arr, n, smallestIndex);
        }
    }

    public static void main(String[] args) {

        int arr[] = { -1, 52, 53, 50, 54, 55 };
        int n = 5;

        // T.C. for building heap using heapify is O(n)
        for (int i = n / 2; i > 0; i--) {
            maxHeapify(arr, n, i);
        }

        // for (int i = n / 2; i > 0; i--) {
        // minHeapify(arr, n, i);
        // }

        for (int i = 1; i <= n; i++) {
            System.out.print(arr[i] + " ");
        }
    }

}