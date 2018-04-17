class Solution {
public:
/**
主要注意dq的操作函数
*/
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int>res; 
		//dq存储的是num下标
        deque<int>dq;
        if(size==0 || num.size()<size) return res;
        for(int i=0;i<num.size();i++){
			//从后面依次弹出队列中比当前num值小的元素,同时也能保证队列首元素为当前窗口最大值下标
            while(!dq.empty() && num[i]>num[dq.back()] ){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=size-1){
                res.push_back(num[dq.front() ] );
				//当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
                if(dq.front() <= (i-size+1) ){
                    dq.pop_front();
                }
            }
        }
        return res;
    }
};