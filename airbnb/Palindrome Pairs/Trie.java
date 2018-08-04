class Trie{
    int pos;
    List<Integer>palins;
    Trie [] node;
    public Trie(){
        pos=-1;
        palins=new ArrayList<>();
        node=new Trie[26];
    }
}

public class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        List<List<Integer>>res=new ArrayList<>();
        Trie root=new Trie();
        for(int i=0;i<words.length;i++){
            add(root, words[i], i);
        }
        for(int i=0;i<words.length;i++){
            search(root,words[i],i,res);
        }
        return res;
    }
    private void search(Trie root, String word, int index, List<List<Integer>>res){
        for(int i=0;i<word.length() && root!=null ;i++){
			/**
			search的时候也是 一开始是代表 "" 的位置,之后才是搜索第一个字母是否存在
			*/
            if(root.pos>=0 && root.pos!=index  && isPalindrome(word,i,word.length()-1) ){
                res.add(Arrays.asList(new Integer[]{index,root.pos } ));
            }
            root=root.node[word.charAt(i)-'a'];
        }
		/**
		此时,单词结束,例如搜索abc,
		此时root指向c
		将所有 ""cba    "xx"cba  c之前是回文串的单词添加进来
		*/
        if(root!=null && root.palins.size()>0){
            for(int add_after : root.palins){
                if(add_after!=index){
                    res.add(Arrays.asList(new Integer[]{index,add_after} ) );
                }
            }
        }
    }
    
    
    private void add(Trie root, String word,int index){
        for(int i=word.length()-1;i>=0;i--){
			/**
			root先判断是否是回文串,此时root还没进入该单词的node
			root判回文串 第一次是整个单词  (word,0,word.length()-1)
			*/
            if(isPalindrome(word,0,i)){
                root.palins.add(index);
            }
            //注意这里创建新的字典树node的方式
            if(root.node[word.charAt(i)-'a' ]==null){
                root.node[word.charAt(i)-'a' ]=new Trie();
            }
            root=root.node[word.charAt(i)-'a' ];
        }
        root.pos=index;
        //这里加上的话,上面遍历到最后的时候就不用单独判断是否到字典树尾了
		/**
		例如 {"abcd","dcba"}
		当search的时候例如  abcd开始搜索,树结构为下面这样
		d--->c--->b--->a(0)
		a--->b--->c--->d(1)
		abcd搜索末尾root==d 的时候,搜索到i==word.length退出所有循环,这个时候
		abcd ""后面是空字符串,空字符串必然也是回文串,所有遇到带pos的结点可以直接添加组成回文串
		
		另一种解释:
			一个word的最前面是 ""  也是回文串,所以可以直接添加在最前面的单词(倒着添加的)的结点palins那里
			添加自己的下标
		*/
        root.palins.add(index);
    }
    private boolean isPalindrome(String s, int start,int last){
        while(start<last){
            if(s.charAt(start++)!=s.charAt(last--)){
                return false;
            }
        }
        return true;
    }
}