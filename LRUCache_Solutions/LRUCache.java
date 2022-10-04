package LinkedList;

import java.util.HashMap;
import java.util.Map;

class LRUCache{
    int size = 0;
    int capacity = 0;
    // the initialization of head and tail in this case is imp bcoz if
//    the delete function is called with a node which is currently tail or head
//    then it'll throw a null pointer exception. cuz head.prev is null and tail.next is null
//    so it's better to use head and tail purely as a pointer mimic
//    (since this is java,and we don't have actual pointers :D )
    Node head = new Node(0,0);
    Node tail = new Node(0,0);
    Map<Integer, Node> map = new HashMap<>();

    public LRUCache(int capacity){
        this.capacity = capacity;
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        Node tempNode = map.get(key);//don't use the new keyword unlike in the put function
        if(map.containsKey(key)){
            delete(tempNode);
            insert(tempNode);
            return map.get(key).value;
        }else{
            return -1;
        }
    }

    public void put(int key, int value) {
        Node tempNode = new Node(key, value);
        if(map.containsKey(key)){
            delete(map.get(key));
            //Don't pass tempNode cuz it's a separate node
//            and not a part of the already created doubly linked list
        }
        if(size == capacity){
            delete(tail.prev);
        }
        insert(tempNode);
    }

    void delete(Node node){
        map.remove(node.key);
        node.prev.next = node.next;
        node.next.prev = node.prev;
        size--;
    }
    void insert(Node node){

        node.next = head.next;
        node.prev = head;
        head.next = node;
        node.next.prev = node;
        size++;
        map.put(node.key,node);
    }
    class Node{
        int key,value;
        Node next, prev;

        Node(int key, int value){
            this.value = value;
            this.key = key;
            // this.next = null;
            // this.prev = null;
        }
    }

    public void display(){
        Node curr = head.next;
        while(curr != null){
            System.out.println("key-> " + curr.key + " val-> " + curr.value);
            curr = curr.next;
        }
    }

}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */