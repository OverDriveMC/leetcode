import java.util.*;
public class Solution {
	public static void main(String[]args){
		Solution s=new Solution();
		String[]L={"foo","bar","the"};
		List<Integer>list=s.findSubstring("barfoofoobarthefoobarman",L);
		for(Integer i : list){
			System.out.print(i+"  ");
		}
		System.out.println();
	}
	static class TrieNode{
		int value;
		Map<Character,TrieNode>children=new HashMap<>();
	}
	public List<Integer> findSubstring(String s, String[] words) {
		List<Integer>res=new ArrayList<>();
		if(words.length==0){
			return res;
		}
		//先根据words建立字典树
		TrieNode root=new TrieNode();
		buildTree(root,words);
		//计算words内字母的总数量
		int length=words[0].length()*words.length;
		//每次查找[i,i+length)是否都在字典树中，并且每个单词的数量相等
		for(int i=0;i<=s.length()-length;i++){
			if(isSubString(root,s,i,i+length)){
				res.add(i);
			}
		}
		return res;
    }
	public void buildTree(TrieNode root, String[]words){
		for(String word : words){
			addWord(root,word);
		}
	}
	//添加单词进字典树
	public void addWord(TrieNode root,String word){
		TrieNode node=root;
		for(int i=0;i<word.length();i++){
			TrieNode next=node.children.get(word.charAt(i));
			if(next==null){
				next=new TrieNode();
				node.children.put(word.charAt(i),next);
			}
			node=next;
		}
		//最后叶子节点的value+1,说明该单词出现的次数
		node.value++;
	}
	
	public boolean isSubString(TrieNode root,String s,int start,int end){
		TrieNode node=root;
		for(int i=start;i<end;i++){
			TrieNode next=node.children.get(s.charAt(i));
			//假如该字母不存在或者node.value已经减到0了，说明不匹配
			if(next==null){
				return false;
			}
			node=next;
			//只有根上的value是大于0的，匹配到这里说明到单词的结尾
			//开始找下一个单词
			if(next.value>0){
				next.value--;
				//匹配到结尾或者下一个单词也匹配
				if( (i+1==end) || isSubString(root,s,i+1,end)){
					//重置根节点上的value
					next.value++;
					return true;
				}else{
					//只有减的时候才要加回去，减的地方只有if内部，所以在这也要加
					node.value++;
					break;
				}
			}
		}
		return false;
	}
	
	public void sop(Object obj){
		System.out.println(obj);
	}
}