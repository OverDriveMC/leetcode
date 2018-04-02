/**
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
		///假如栈2中有元素,直接出栈,
        if(!stack2.empty()){
            int res=stack2.top();
            stack2.pop();
            return res;
        }
		///当栈2中没有元素的时候,把栈1的元素全部放入栈2中
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int res=stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};