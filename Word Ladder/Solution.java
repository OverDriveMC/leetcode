class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        //需要开头判断下是否包含该字符串
        if(!wordList.contains(endWord)){
            return 0;
        }
        
        Set<String>beginSet=new HashSet<String>();
        Set<String>endSet=new HashSet<>();
        beginSet.add(beginWord);
        endSet.add(endWord);
        Set<String>visit=new HashSet<String>();
        /**
        * 现在开头传递的是wordList,里面有重复元素,所以需要自己手动构造一个Set初始化
        */
        Set<String>wordSet=new HashSet<String>(wordList);
        int path=1;
        while(!beginSet.isEmpty() && !endSet.isEmpty() ){
            /*
            *维护两个Set,每次使用短的去运算,看能否从beginSet中找到String通过变化一个字符
            *得到endSet中的字符
            */
            if(beginSet.size() > endSet.size()){
                Set<String>temp=beginSet;
                beginSet=endSet;
                endSet=temp;
            }
            path++;
            Set<String>temp=new HashSet();
            for(String str : beginSet){
                char[]arr=str.toCharArray();
                for(int i=0;i<arr.length;i++){
                    char cur=arr[i];
                    ///从a-z遍历所有字符
                    for(char c='a';c<='z';c++){
                        arr[i]=c;
                        String ss=String.valueOf(arr);
                        ///假如endSet中包含,直接退出即可
                        if(endSet.contains(ss)){
                            return path;
                        }
                        ///判断是否曾经遍历过,假如没有遍历过,并且原有的List里包含该字符,添加进temp Set中
                        if(!visit.contains(ss) && wordSet.contains(ss)){
                            temp.add(ss);
                            visit.add(ss);
                        }
                    }
                    arr[i]=cur;
                }
            }
            ///下一轮的beginSet即是temp Set
            beginSet=temp;
        }
        return 0;
    }
}