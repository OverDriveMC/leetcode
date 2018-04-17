/**
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
*/
class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
         ++num[ch-'\0'];
        if(num[ch-'\0']==1){
            q.push(ch);
        }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
		///假如数量已经不为1了,那么pop出队列
        while(!q.empty() &&  num[q.front()-'\0'] >1   ){
            q.pop();
        }
        return q.empty() ? '#' : q.front();
    }
private:
/**
使用num记录字母出现数量
q记录之间只出现一次的字母
*/
    queue<char>q;
    int num[128];
};