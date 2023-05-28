// Heaps

import java.net.Inet4Address;
import java.util.*;

// Max Heap Class
class MaxHeap {

    List<Integer> arr = new ArrayList<Integer>(100);
    int size;

    MaxHeap() {
        arr.add(-1);
        this.size = 0;
    }

    // Insertion in Heap
    public void insert(int val) {

        // step 1: Insert node at last
        size++;
        arr.add(val);

        // step 2: Take last node to its correct position
        int index = size;

        while (index > 1) {
            int parent = index / 2;

            if (arr.get(parent) < arr.get(index)) {
                Collections.swap(arr, parent, index);
                index = parent;
            } else
                return;
        }
    }

    // Deletion in Heap
    public void delete() {

        if (this.size == 0) {
            System.out.println("Heap is Empty");
            return;
        }

        // step 1: Replcae first node with last node
        arr.set(1, arr.get(size));

        // step 2: Remove last node
        arr.remove(size);
        this.size--;

        // step 3: Take root node to its correct position
        int index = 1;

        while (index <= size) {
            int leftIndex = 2 * index;
            int rightIndex = (2 * index) + 1;

            if (leftIndex <= this.size && arr.get(leftIndex) > arr.get(index)) {
                Collections.swap(arr, leftIndex, index);
                index = leftIndex;
            } else if (rightIndex <= this.size && arr.get(rightIndex) > arr.get(index)) {
                Collections.swap(arr, rightIndex, index);
                index = rightIndex;
            } else {
                return;
            }
        }
    }

    public void print() {
        for (int i = 1; i <= size; i++) {
            System.out.print(arr.get(i) + " ");
        }
    }
}

public class Heap {

    public static void main(String[] args) {

        MaxHeap heap = new MaxHeap();

        heap.insert(70);
        heap.insert(50);
        heap.insert(60);
        heap.insert(30);
        heap.insert(20);
        heap.insert(65);
        heap.insert(80);

        // heap.print();

        heap.delete();

        heap.print();
    }

}