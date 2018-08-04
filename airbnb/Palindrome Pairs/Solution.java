class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
		List<List<Integer>>res=new ArrayList<>();
		if(words==null || words.length==0){
			return res;
		}
		Map<String,Integer>map=new HashMap<>();
		for(String str : words){
			map.put(str,map.size());
		}
		for(int i=0;i<words.length;i++){
			for(int j=0;j<=words[i].length();j++){
				/**
				pre=s1[0:cur]
				suf=s1[cur:]
				对于s1="abcd"
				pre取值为:  ""      "a"    "ab"   "abc"    "abcd"
				suf取值为:  "abcd"  "bcd"  "cd"   "d"      ""
				pre用来计算在前面添加串的情况:
				pre需要补充成为回文串需要在前面添加:
					"dcba"   "dcb"   "dc"   "d"    ""  (前提是保证pre是回文串的情况下)
				suf需要补充成为回文串需要在后面添加:
					""       "a"     "ba"   "cba"  "dcba"  (前提是保证suf是回文串的情况下)
				但是这样会有一种重复的情况:
					例如 abcd 后面添加  dcba
					和dcba 前面添加  abcd
				所以为了防止这种情况,特判了一下suf.length()不为0的情况
				(这样这种情况只会出现在在dcba前面添加abcd的情况)
				
				*/
				String pre=words[i].substring(0,j);
				String suf=words[i].substring(j);
				/**
				s2+s1的情况,即在前面添加的情况
				这个时候s2需要满足  == s1[cur:].reverse()
				*/
				if(isPalindrome(pre) ){
					String add_before=new StringBuilder(suf).reverse().toString();
					Integer index= map.get( add_before );
					if(index!=null && index!=i){
						List<Integer>list=new ArrayList<>();
						list.add(index);
						list.add(i);
						res.add(list);
					}
				}
				/**
				s1+s2的情况,即在后面添加的情况
				这个时候s2需要满足  ==s1[0:cur].reverse
				*/
				if(suf.length()!=0 && isPalindrome(suf) ){
					String add_after=new StringBuilder(pre).reverse().toString();
					Integer index=map.get(add_after);
					if(index!=null && index!=i){
						List<Integer>list=new ArrayList<>();
						list.add(i);
						list.add(index);
						res.add(list);
					}
				}
				
			}
		}
		return res;
    }
	
	
	private boolean isPalindrome(String str){
		int start=0;
		int last=str.length()-1;
		while(start<last){
			if(str.charAt(start++)!=str.charAt(last--)){
				return false;
			}
		}
		return true;
	}
}