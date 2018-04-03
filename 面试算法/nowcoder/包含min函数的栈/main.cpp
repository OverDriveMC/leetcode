/*
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/
class Solution {
public:
    void push(int value) {
        s.push(value);
		/**
		* 入栈的时候判断一下,假如栈顶的最小元素比value小,那入minn栈的元素即为value,否则依旧是栈顶元素
		*/
        if(!minn.empty()){
            minn.push( std::min(value,minn.top()) );
        }else{
            minn.push(value);
        }
    }
    void pop() {
        s.pop();
        minn.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return minn.top();
    }
private:
    stack<int>s;
	//使用一个辅助栈存储当前最小元素
    stack<int>minn;
};