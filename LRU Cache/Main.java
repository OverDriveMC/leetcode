import java.util.*;

class LRUCache {
    private DoubleLinkNode head;
    private DoubleLinkNode tail;
    private int capacity;
    Map<Integer,DoubleLinkNode>map;
    
    
    public LRUCache(int capacity) {
        this.capacity=capacity;
        head=new DoubleLinkNode();
        tail=new DoubleLinkNode();
        head.next=tail;
        tail.pre=head;
        head.pre=null;
        tail.next=null;
        map=new HashMap<Integer,DoubleLinkNode>();
    }
    
    private void moveToHead(DoubleLinkNode node){
        removeNode(node);
        addNode(node);
    }
    private void removeNode(DoubleLinkNode node){
        node.pre.next=node.next;
        node.next.pre=node.pre;
    }
    private void addNode(DoubleLinkNode node){
        head.next.pre=node;
        node.pre=head;
        node.next=head.next;
        head.next=node;
        
    }
    
    
    public int get(int key) {
        DoubleLinkNode val=map.get(key);
        if(val==null){
            return -1;
        }
        moveToHead(val);
        return val.getValue();
    }
    
    public void put(int key, int value) {
        DoubleLinkNode val=map.get(key);
        if(val==null){
            //先插入再删除,避免长度为0
            DoubleLinkNode node=new DoubleLinkNode();
            node.setValue(value);
            node.setKey(key);
            addNode(node);
            map.put(key,node);
            if(map.size()>this.capacity){
                DoubleLinkNode toDelete=tail.pre;
                map.remove(toDelete.getKey());
                removeNode(toDelete);
            }
        }else{
            val.setValue(value);
            moveToHead(val);
        }
    }
    
    
    class  DoubleLinkNode{
        private int key;
        private int value;
        private DoubleLinkNode pre;
        private DoubleLinkNode next;

        public void setKey(int key){
            this.key=key;
        }
        public int getKey(){
            return key;
        }

        public void setValue(int value){
            this.value=value;
        }
        public int getValue(){
            return value;
        }
        public void setPre(DoubleLinkNode pre){
            this.pre=pre;
        }
        public DoubleLinkNode getPre(){
            return pre;
        }
        public void  setNext(DoubleLinkNode next){
            this.next=next;
        }
        public DoubleLinkNode getNext(){
            return next;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
 
 
public class Main{
	public  static void main(String[]args){
		LRUCache cache=new LRUCache(2);
		cache.put(1, 1);
		cache.put(2, 2);
		int val=cache.get(1);       // returns 1
		System.out.println(val);
		cache.put(3, 3);    // evicts key 2
		val=cache.get(2);       // returns -1 (not found)
		System.out.println(val);
		cache.put(4, 4);    // evicts key 1
		val=cache.get(1);       // returns -1 (not found)
		System.out.println(val);
		val=cache.get(3);       // returns 3
		System.out.println(val);
		val=cache.get(4);       // returns 4
		System.out.println(val);
	}
 
}