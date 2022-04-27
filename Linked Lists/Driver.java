public class Driver {
    public static void main(String[] args) {
        LinkedList firstList = new LinkedList();
        LinkedList secondList = new LinkedList();
        firstList.append(new Node("A"));
        firstList.append(new Node("B"));
        firstList.append(new Node("C"));
        secondList.append(new Node("G"));
        secondList.append(new Node("H"));
        secondList.append(new Node("I"));

        firstList.zip(secondList, 0);
        System.out.println(firstList.toString());
        
    }
}
