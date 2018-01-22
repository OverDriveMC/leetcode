class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>>map=new HashMap<String,List<String>>();
        for(int i=0;i<strs.length;i++){
			///先转化成字符数组
            char ca[]=strs[i].toCharArray();
            Arrays.sort(ca);
            String val=String.valueOf(ca);
			///先判断存不存在,不存在先put个List进去
            if(!map.containsKey(val)){
                map.put(val, new ArrayList<String>());
            }
			//最后统一添加
            map.get(val).add(strs[i]); 
        }
		//通过map.values()构造
        return new ArrayList<List<String>>(map.values());
    }
}