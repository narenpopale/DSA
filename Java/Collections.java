// Java Collection Framework

import java.util.*;


public class Collections {
    public static void main(String[] args) {
        
        // 1. ArrayList
        ArrayList<Integer> nums = new ArrayList<>();


        // ADD
        // add(element) - appends element at the last
        nums.add(1);
        nums.add(2);
        nums.add(3);
        
        // add(index, element) - add element at specific index
        nums.add(1, 90);
        
        // addAll() - add one list to another
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(9);
        arr.add(8);
        nums.addAll(arr);

        
        // READ
        // Accessing elements
        nums.get(1);

        
        //DELETE
        // remove(index) - Deleting elements
        nums.remove(1);

        // Deleting specific element
        nums.remove(Integer.valueOf(1));

        // Delete all elements
        // nums.clear();

        
        // UPDATE
        // Updating value at index
        nums.set(1, 80);

        // check element present in list or not
        nums.contains(3);

        // check size
        nums.size();

        // Iterate on list
        for(int i = 0;i < nums.size(); i++) {
            System.out.println(nums.get(i));
        }

        for(Integer i: nums) {
            System.out.println(i);
        }


        // 2. Stack
        Stack<String> animals = new Stack<>();

        // PUSH
        animals.push("dog");
        animals.push("cat");

        //TOP
        animals.peek();

        //POP
        animals.pop();


        
        // 3. Queue using likedlist
        Queue<Integer> queue = new LinkedList<>();

        // PUSH
        queue.offer(1);
        queue.offer(2);
        queue.offer(3);

        // Access Front Element
        queue.peek();

        // Access and Delete front element
        queue.poll();



        // 4. PriorityQueue 

        // MIN HEAP 
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        // MAX HEAP 
        // PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());

        // PUSH
        pq.offer(1);
        pq.offer(2);
        pq.offer(3);

        // Access top Element
        pq.peek();

        // Access and Delete top element
        pq.poll();

    }
}