class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
		/**
		记录下开始与结尾的迭代器
		通过y记录当前迭代器的遍历位置
		*/
        i=vec2d.begin();
        end=vec2d.end();
        y=0;
    }

    int next() {
        return (*i)[y++];
    }

    bool hasNext() {
		/**
		每次判断y到结尾的时候,如果i没有到结尾,更新到下一个迭代器里面开始遍历
		*/
        while( (y==(*i).size() )  &&  (i!=end)   ){
            i++;
            y=0;
        }
		///当i==end的时候,说明没有next了
        return i!=end;
    }
private:
    vector<vector<int>>::iterator i,end;
    int y;
};