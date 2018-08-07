class Solution {
public:
    string alienOrder(vector<string> &words) {
		unordered_set<char>ch;
		set<pair<char,char>>edges;
		vector<int>indegree(256,0);
		//保存所有出现过的单词
		for(auto word : words){
			ch.insert(word.begin(),word.end());
		}
		for(int i=0;i<words.size()-1;i++){
			string w1=words[i];
			string w2=words[i+1];
			int len=min(w1.size(),w2.size());
			int j=0;
			for(;j<len;j++){
				if(w1[j]==w2[j]){
					continue;
				}
				edges.insert(make_pair(w1[j],w2[j]));
				break;
			}
			if(j==len){
				return "";
			}
		}
		for(auto a:edges){
			indegree[a.second]++;
		}
		//字母大的放在后面,使用greater实现
		priority_queue<char,vector<char>,greater<char>>q;
		for(auto a : ch){
			if(indegree[a]==0){
				q.push(a);
			}
		}
		stringstream ss;
		while(!q.empty()){
			char w=q.top();
			q.pop();
			ss<<w;
			for(auto a : edges){
				if(a.first==w){
					indegree[a.second]--;
					if(indegree[a.second]==0){
						q.push(a.second);
					}
				}
				
			}
		}
		//假如有字母没有添加进来,说明入度最后也不为0,说明成环
		return ss.str().size()==ch.size() ? ss.str() :"";
    }
};