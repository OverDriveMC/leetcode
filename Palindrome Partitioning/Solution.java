class Solution {
    public List<List<String>> partition(String s) {
		List<List<String>>res=new ArrayList<>();
		backtrack(res,new ArrayList<>(),s,0);
		return res;
    }
	void backtrack(List<List<String> >res, List<String>list,String s, int start ){
		if(start==s.length()){
			res.add(new ArrayList<>(list));
		}else{
			for(int i=start;i<s.length();i++){
				//每次以start为开头, i为结尾的子串如果是回文串,开始新一轮的搜索
				if(isPalindrome(s, start,i)){
					list.add(s.substring(start,i+1));
					backtrack(res,list, s, i+1);
					list.remove(list.size()-1);
				}
			}
		}
	}
	boolean isPalindrome(String s, int start,int last){
		while(start<last){
			if(s.charAt(start)!=s.charAt(last)){
				return false;
			}
			start++;
			last--;
		}
		return true;
	}
}