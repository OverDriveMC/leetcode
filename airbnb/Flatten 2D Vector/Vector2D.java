class Vector2D implements Iterable<Integer>{
	private List<List<Integer>>lists;
	private int xIndex,yIndex;
	
	public Vector2D(List<List<Integer>> lists){
		this.lists=lists;
		xIndex=0;
		yIndex=0;
	}
	@Override
	public boolean hasNext(){
		if(xIndex==lists.size()){
			return false;
		}
		return true;
	}
	@Override
	public Integer getNext(){
		if(xIndex>=lists.size() || yIndex>=lists.get(xIndex).size()  ){
			return null;
		}
		Integer res=lists.get(xIndex).get(yIndex);
		yIndex++;
		if(yIndex==lists.get(xIndex).size() ){
			xIndex++;
			yIndex=0;
		}
		return res;
	}
	@Override
	public void remove(){
		
		
	}

}