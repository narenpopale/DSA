// Java Collection Framework

import java.util.*;


public class CollectionsFramework {
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



        // 5. ArrayDeque - Doubly ended queue
        ArrayDeque<Integer> adq = new ArrayDeque<>();
        
        // PUSH - back
        adq.offer(1);
        adq.offerLast(2);

        // PUSH - front
        adq.offerFirst(3);
        
        // Access Front Element
        adq.peek();
        adq.peekFirst();
        
        // Access Back Element
        adq.peekLast();
        
        // Access and Delete front element
        adq.poll();
        adq.pollFirst();

        // Access and Delete back element
        adq.pollLast();



        // 6. Set - Unique elements

        // HashSet - not maintains order
        Set<Integer> set = new HashSet<>();

        // LinkedHashSet - maintains order
        // Set<Integer> set = new LinkedHashSet<>();

        // TreeSet - maintains sorted order
        // Set<Integer> set = new TreeSet<>();

        // ADD
        set.add(1);
        set.add(2);
        set.add(3);

        // DELETE
        set.remove(2);

        // ELEMENT PRESENT OR NOT
        set.contains(4);

        // IS SET EMPTY
        set.isEmpty();

        // SIZE
        set.size();

        // DELETE ALL ELEMENTS
        set.clear();
        
        

        // 7. Map - Key, value pairs

        // HashMap - not maintains any order
        Map<String, Integer> m = new HashMap<>();

        // TreeMap - maintains sorted order of keys
        // Map<String, Integer> m = new TreeMap<>();

        // ADD
        m.put("abc", 10);
        m.put("pqr", 12);
        m.put("xyz", 14);

        // ITERATION ON MAP
        for(Map.Entry<String, Integer> e: m.entrySet()) {
            
            // Prints key value pairs
            System.out.println(e);
            
            // Prints only keys
            System.out.println(e.getKey());
            
            // Prints only values
            System.out.println(e.getValue());
            
        }
        
        // ITERATION ON KEYS
        for(String key: m.keySet()) {
            System.out.println(key);
        }

        // ITERATION ON VALUES
        for(int v: m.values()) {
            System.out.println(v);
        }

        //DELETE
        m.remove("abc");
        m.remove("pqr", 12);

        // KEY PRESENT OR NOT
        m.containsKey("abc");

        // VALUE PRESENT OR NOT
        m.containsValue(12);
        
        // PUT NEW KEY IF IT IS ABSENT
        m.putIfAbsent("ram", 90);
        
        // IS MAP EMPTY
        m.isEmpty();
    
        // SIZE
        m.size();
    
        // DELETE ALL PAIRS
        m.clear();




        // 8. Arrays Class
        int array[] = {1, 2, 3, 4, 5};

        // binary search - returns index
        Arrays.binarySearch(array, 3);

        // sort
        Arrays.sort(array);

        // fill one element in whole array
        Arrays.fill(array, 0);



        // 9. Collections Class
        List<Integer> ls = new ArrayList<>();

        ls.add(3);
        ls.add(2);
        ls.add(1);

        // MIN
        Collections.min(ls);

        // MAX
        Collections.max(ls);

        // FREQUENCY OF ELEMENT
        Collections.frequency(ls, 2);

        // SORT - increasing order
        Collections.sort(ls);

        // SORT - decreasing order
        Collections.sort(ls, Comparator.reverseOrder());



        // 10. Comparator Interface
        List<Student> students = new ArrayList<>();

        students.add(new Student("abc", 1));
        students.add(new Student("pqr", 2));
        students.add(new Student("xyz", 3));

        // SORT
        Collections.sort(students, new Comparator<Student>() {
            @Override
            public int compare(Student s1, Student s2) {
                return s1.name.compareTo(s2.name);
            }
        });

        // Lambda Expression
        Collections.sort(students, (s1, s2) -> s1.name.compareTo(s2.name)); // Sort based on name
        Collections.sort(students, (s1, s2) -> s1.rollNo - s2.rollNo); // Sort based on roll no
        
    }
}

class Student {
    String name;
    int rollNo;

    public Student(String name, int roll) {
        this.name = name;
        this.rollNo = roll;
    }
}