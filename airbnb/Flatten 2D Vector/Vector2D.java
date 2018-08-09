public class Vector2D implements Iterator<Integer> {
	//通过两个迭代器实现
    Iterator<List<Integer>>i;
    Iterator<Integer>j;
    
    public Vector2D(List<List<Integer>> vec2d) {
        i=vec2d.iterator();
        j=null;
    }

    @Override
    public Integer next() {
        Integer res=null;
        if(hasNext()){
            res=j.next();
        }
        return res;
    }

    @Override
    public boolean hasNext() {
		/**
		当i还有 next的时候 j==null或者j没有next的时候
		更新j到i的next的迭代器
		*/
        while(  (j==null || !j.hasNext()) && i.hasNext()     ){
            j=i.next().iterator();
        }
		//判断是否到最后一个元素了
        return j!=null && j.hasNext() ;
    }

    @Override
    public void remove() {
        j.remove();
    }
}