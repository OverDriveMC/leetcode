/**
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
给出所有字典里单词组成s 的情况

*/


class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        return dfs(s,wordDict, new HashMap<String,LinkedList<String>> () )  ;
    }
	/**
	* 使用Map维护所有能够组成s的情况
	*  key:s    value:组成s的所有情况
	*/
    public List<String> dfs(String s, List<String>wordDict, Map<String,LinkedList<String>>map){
        if(map.containsKey(s)){
            return map.get(s);
        }
        LinkedList<String>curConsist=new LinkedList<String>();
		//假如当前字符串已经为空了,那么直接返回即可
        if(s.length()==0){
            curConsist.add("");
            return curConsist;
        }
        for(String str : wordDict){
			///假如s可以以当前串为前缀
            if(s.startsWith(str)){
				///计算以当前串为前缀之后的串的组成方式
                List<String>res=dfs( s.substring(str.length() ) ,wordDict, map);
				///之后所有的组成方式与str组合,即可形成所有以str为前缀的组成s的方式
                for(String sub : res){
                    curConsist.add(str+ (sub.isEmpty() ? "" : ( " "+sub) )  );
                }
            }
        }
		///每次计算出来组成s的所有组成方式,同时放入Map中
        map.put(s, curConsist);
        return curConsist; 
    }
}