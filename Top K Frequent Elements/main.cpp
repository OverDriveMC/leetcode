/**
题目描述：找出出现次数最多的k的元素
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Solution:
	通过unordered_map存储[key,count(key)]
	接着根据count(key)建立优先队列
	返回最高的k个
时间复杂度： 建立hashmap时间O(n),建堆输出时间O(Nlog(k))整体时间复杂度O(N+Nlog(k))=O(Nlog(k))

unordered_map中的元素没有按照它们的键值或映射值的任何顺序排序，而是根据它们的散列值组织成桶以允许
通过它们的键值直接快速访问单个元素（具有常数平均时间复杂度）。unordered_map容器比映射容器更快地通过它们的键来访问
各个元素，尽管它们通过其元素的子集进行范围迭代通常效率较低。无序映射实现直接访问操作符(operator []),
该操作符允许使用其键值作为参数直接访问映射值。
容器中的迭代器至少是前向迭代器。
关键词：无序的 快速的检索 达到的是更快的访问 但是子集的范围迭代效率低
*/
class Solution{
public:
	vector<int> topKFrequent(vector<int>&nums,int k){
		unordered_map<int,int>map;
		for(int i=0;i<nums.size();i++){
			map[nums[i]]++;
		}
		/**
		less:从大到小
		greater:从小到大
		*/
		priority_queue<pair<int,int>,vector<pair<int,int> >, std::greater<pair<int,int> > > pq;
		for(auto iter= map.begin(); iter!=map.end(); ++iter ){
			pq.push(make_pair(iter->second, iter->first));
			//一共只需要存储k个元素
			if(pq.size() > k){
				//使用greater,每次把最小的丢掉
				pq.pop();
			}
		}
		vector<int>res;
		while(!pq.empty()){
			res.push_back(pq.top().second);
			pq.pop();
		}
		//最后需要逆序，按照从大到小输出
        reverse(res.begin(),res.end());
		return res;
	}
	
};