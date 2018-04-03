/**
记录一个最小值,同时栈内维护与最小值的差值
假如push的时候遇到一个更小的,那么栈内多加一个与当前最小值的差值(一定为负数)
例如当前最小值为2,假如push 1,  那么栈会push(-1)   push(0)
所以pop的时候,先pop出去,之后判断栈顶元素是否为负,假如为负,则更新最小值
*/

class Solution {
public:
    void push(int value) {
        if(diff.empty()){
            diff.push(0);
            minn=value;
        }else{
            if(minn>value){
                diff.push(value-minn);
                diff.push(0);
                minn=value;
            }else{
                diff.push(value-minn);
            }
        }
    }
    void pop() {
        diff.pop();
        if(diff.top()<0){
            minn-=diff.top();   
            diff.pop();
        }
    }
    int top() {
        return diff.top()+minn;
    }
    int min() {
        return minn;
    }
private:
    stack<int>diff;
    int minn;
};