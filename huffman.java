import java.util.*;
 
abstract class Node implements Comparable<Node> {
    public  int frequency; // the frequency of this tree
    public  char data;
    public  Node left, right; 
    public Node(int freq) { 
      frequency = freq; 
    }
 
    // compares on the frequency
    public int compareTo(Node tree) {
        return frequency - tree.frequency;
    }
}
 
class HuffmanLeaf extends Node {
    
 
    public HuffmanLeaf(int freq, char val) {
        super(freq);
        data = val;
    }
}
 
class HuffmanNode extends Node {
    
    public HuffmanNode(Node l, Node r) {
        super(l.frequency + r.frequency);
        left = l;
        right = r;
    }

}


class Decoding {

/*  
	class Node
		public  int frequency; // the frequency of this tree
    	public  char data;
    	public  Node left, right;
    
*/ 

	void decode(String s, Node root) {
        StringBuffer store = new StringBuffer();
        //StringBuffer is a peer class of String that provides much of the functionality           of strings. String represents fixed-length, immutable character sequences                while StringBuffer represents growable and writable character                            sequences.StringBuffer may have characters and substrings inserted in the                 middle or appended to the end.
        
        Node cur=root; //cur ptr for help so that tree is not destroyed
        
        for(int i=0;i<s.length();i++)   //s is taken from input something like 10010
        {
            if(s.charAt(i)=='1')
            {
                cur=cur.right;      //right side 1
            }
            else
            {
                cur=cur.left;       //left side 0
            }
            if(cur!=null && cur.left==null && cur.right==null)  //when we are at leaf                                                                      node ie left right                                                                        null but has some data
            {
                store.append(cur.data);     //data will be appended to earlier processed                                                thing like this only ie stored in store
                cur=root;                   //again cur to root for next processing
            }
        }
        System.out.println(store.toString());  

       
    }
