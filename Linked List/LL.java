
class LL {
    Node head = null;
    private int size;

    LL() {
        this.size = 0;
    }

    class Node {
        String data;
        Node next;

        Node(String data) {
            this.data = data;
            this.next = null;
        }
    }

    // Add element to the first index
    public void addFirst(String data) {
        Node newNode = new Node(data);

        size++;

        if (head == null) {
            head = newNode;
            return;
        }

        newNode.next = head;
        head = newNode;
    }

    // Add element to the last index
    public void addLast(String data) {
        Node newNode = new Node(data);

        size++;

        if (head == null) {
            head = newNode;
            return;
        }

        Node currNode = head;
        while (currNode.next != null) {
            currNode = currNode.next;
        }

        currNode.next = newNode;
    }

    // Delete First Element
    public void deleteFirst() {

        if (head == null) {
            System.out.println("List is Empty!");
            return;
        }

        size--;

        head = head.next;
    }

    // Delete Last Element
    public void deleteLast() {

        if (head == null) {
            System.out.println("List is Empty!");
            return;
        }

        size--;

        if (head.next == null) {
            head = null;
            return;
        }

        Node secondLastNode = head;
        Node lastNode = head.next;
        while (lastNode.next != null) {
            lastNode = lastNode.next;
            secondLastNode = secondLastNode.next;
        }

        secondLastNode.next = null;
    }

    // Print all elements
    public void printList() {

        if (head == null) {
            System.out.println("List is Empty!");
            return;
        }

        Node currNode = head;
        while (currNode != null) {
            System.out.print(currNode.data + " -> ");
            currNode = currNode.next;
        }

        System.out.println("NULL");
    }

    // Get Size of all elements
    public int getSize() {
        return this.size;
    }

    public static void main(String[] args) {
        LL list = new LL();
        list.addFirst("good");
        list.addFirst("is");
        list.addFirst("naren");
        list.addLast("boy");
        list.printList();
        list.deleteFirst();
        list.deleteLast();
        list.printList();

        System.out.println(list.getSize());
    }

}