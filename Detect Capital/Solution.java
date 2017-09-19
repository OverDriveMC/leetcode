class Solution {
    public boolean detectCapitalUse(String word) {
		if(word.length()<=1) return true;
		if(word.charAt(0)>'Z'){
			for(int i=1;i<word.length();i++ ){
				if(word.charAt(i)<'a' ){
					return false;
				}
			}
		}else{
			if(word.charAt(1)>'Z'){
				for(int i=1;i<word.length();i++ ){
					if(word.charAt(i)<'a' ){
						return false;
					}
				}
			}else{
				for(int i=1;i<word.length();i++ ){
					if(word.charAt(i)>'Z' ){
						return false;
					}
				}
			}
		}
		return true;
    }
}

class Solution {
	public boolean detectCapitalUse(String word) {
		return word.matches("[A-Z]+|[a-z]+|[A-Z][a-z]+");
	}
}
