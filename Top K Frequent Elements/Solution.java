class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer,Integer>map=new HashMap<>();
        for(int i : nums){
            map.put(i, map.getOrDefault(i,0)+1 );
        }
        PriorityQueue<Integer> heap= new PriorityQueue<>(
            (n1,n2) -> map.get(n1) -map.get(n2)
            );
        for(int i : map.keySet()){
            heap.add(i);
            if(heap.size()> k){
                heap.poll();
            }
        }
        List<Integer> res=new LinkedList<>();
        while(!heap.isEmpty() ){
            res.add(heap.poll());
        }
        Collections.reverse(res);
        return res;
    }
}