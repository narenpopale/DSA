public class DLL {
    Node head = null;
    Node tail = null;
    private int size;

    DLL() {
        this.size = 0;
    }

    class Node {
        int data;
        Node next;
        Node prev;

        Node(int data) {
            this.data = data;
            this.next = null;
            this.prev = null;
        }
    }

    // Prints All elements in DLL
    public void printList() {
        Node currNode = head;

        while (currNode != null) {
            System.out.print(currNode.data + " ");
            currNode = currNode.next;
        }

        System.out.println();
    }

    // Add new element at First
    public void addFirst(int data) {
        Node node = new Node(data);

        size++;
        if (head == null) {
            head = node;
            tail = node;
            return;
        }

        node.next = head;
        head.prev = node;
        head = node;
    }

    // Add new element at Last
    public void addLast(int data) {
        Node node = new Node(data);

        size++;
        if (tail == null) {
            tail = node;
            head = node;
            return;
        }

        tail.next = node;
        node.prev = tail;
        tail = node;
    }

    // Insert new element at any position
    public void addAtPosition(int data, int pos) {
        Node node = new Node(data);

        size++;
        if (pos == 0) {
            node.next = head;
            head.prev = node;
            head = node;
            return;
        }

        if (pos == this.size - 1) {
            tail.next = node;
            node.prev = tail;
            tail = node;
            return;
        }

        Node currNode = head;
        int i = 1;
        while (i < pos) {
            currNode = currNode.next;
            i++;
        }

        node.next = currNode.next;
        currNode.next = node;
        node.next.prev = node;
        node.prev = currNode;
    }

    // Delete element at any position
    public void deleteAtPosition(int pos) {

        if (pos == 0) {
            head = head.next;
            head.prev.next = null;
            head.prev = null;
            return;
        }

        if (pos == this.size - 1) {
            tail = tail.prev;
            tail.next.prev = null;
            tail.next = null;
            return;
        }

        Node currNode = head;
        int i = 0;
        while (i < pos) {
            currNode = currNode.next;
            i++;
        }

        currNode.prev.next = currNode.next;
        currNode.next.prev = currNode.prev;
        currNode.next = null;
        currNode.prev = null;
    }

    // Get size of List
    public int getSize() {
        return this.size;
    }

    public static void main(String[] args) {

        DLL list = new DLL();
        list.addFirst(5);
        list.addLast(6);
        list.addLast(7);
        list.addFirst(4);
        list.addLast(8);
        list.printList();
        list.deleteAtPosition(2);
        list.printList();
        System.out.println(list.getSize());
    }

}
