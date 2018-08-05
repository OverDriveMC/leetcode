/**
每个字母保存一个节点
使用to保存以该节点开头的边
*/
class Node{
	public int degree;
	public Set<Integer>to=new HashSet<>();
	public Node(){
		degree=0;
	}
}

public class Solution {
    public String alienOrder(String[] words) {
		Node []node=new Node[26];
		for(int i=0;i<26;i++){
			node[i]=new Node();
		}
		/*
		*记录所有出现的单词
		*因为有的单词可能不在拓扑序里面
		*例如 xy xz
		* x出现了,但是不在拓扑序里面
		*/
		boolean happens[]=new boolean[26];
		Arrays.fill(happens,false);
		Set<String>vis=new HashSet<String>();
		
		for(int i=0;i<words.length;i++){
			//先保存所有出现的单词
			for(int j=0;j<words[i].length();j++){
				happens[words[i].charAt(j)-'a' ]=true;
			}
			if(i!=words.length-1){
				int length=Math.min(words[i].length(),words[i+1].length());
				int from=0,to=0;
				for(int j=0;j<length;j++){
					//找到第一个不相同的单词
					if(words[i].charAt(j)==words[i+1].charAt(j) ){
						continue;
					}
					from=words[i].charAt(j)-'a';
					to=words[i+1].charAt(j)-'a';
					break;
				}
				if(from!=to){
					String edge=from+""+to;
					//防止边重复添加
					if(!vis.contains(edge)){
						node[to].degree++;
						node[from].to.add(to);
						vis.add(edge);
					}
					
					
				}
			}
		}
		StringBuilder sb=new StringBuilder();
		/**
		*使用优先队列,保证符合  特定的 顺序之外,还符合字典序
		*/
		Queue<Integer>queue=new PriorityQueue<>();
		for(int i=0;i<26;i++){
			if(node[i].degree==0 && happens[i]){
				queue.offer(i);
			}
		}
		while(!queue.isEmpty()){
			int now=queue.poll();
			//每次将队首元素放到结果中
			sb.append((char)(now+'a'));
			//遍历以它为开头的边,所有的入度减1,减到0的说明在它之前的边都放到了结果里面
			//因为只有(k,v)  k已经被加到sb里面了, v才有机会degree为0
			for(int toIndex : node[now].to){
				node[toIndex].degree--;
				if(node[toIndex].degree==0){
					queue.offer(toIndex);
				}
			}
		}
		//degree不为0的,说明有环
		for(int i=0;i<26;i++){
			if(node[i].degree!=0){
				return "";
			}
		}
		return sb.toString();
    }
}