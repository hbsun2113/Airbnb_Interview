#include<bits/stdc++.h>
using namespace std;
class Vector2D {
public:
    // 一刷地址：https://leetcode.com/submissions/detail/241637111/
    // https://yezizp2012.github.io/2017/06/01/airbnb%E9%9D%A2%E8%AF%95%E9%A2%98%E6%B1%87%E6%80%BB/
    Vector2D(vector<vector<int>>& vec) {
        v=vec;
        reset();
    }

    int next() {
        hasNext();
        auto v=*it;
        it++;
        // cout<<v<<endl;
        return v;
    }

    bool hasNext() {
        while(cur_row!=end && it==cur_row->end()){ // 说明此时begin为空
            cur_row++;
            if(cur_row==end) break; // ++完可能就变为end了
            it=cur_row->begin();
        }
        if(cur_row==end) return false;
        else return true;
    }

    // remove上一次next的结果。没next就remove返回null。
    // 主旨思想，只要it前面有有效元素，我们就要删除离它最近的那个，无论跨越多少个空vector
    bool remove(){
        if(it!=cur_row->begin()){
            cur_row->erase(prev(it));
            it--; // 易错点：erase后当前行所有元素会向前移动一位，因此此时it指向了下一个元素，我们要纠正它。
            return true;
        }
        else{
            auto pre_row=prev(cur_row);
            while(pre_row!=begin && pre_row->size()==0) pre_row--;
            if(pre_row->size()==0) return false;
            auto tmp=pre_row->end();
            pre_row->erase(prev(tmp));
            // 因为是erase了一个元素，所以cur_row和其后的行没有受到影响
            return true;
        }
    }

    void reset(){
        cout<<"global size = "<<v.size()<<endl;
        begin=v.begin();
        end=v.end();
        cur_row=v.begin();
        while(cur_row!=end && cur_row->size()==0){
            cur_row++;
        }
        if(cur_row!=end) it=cur_row->begin();
    }


    vector<vector<int>>::iterator begin,end,cur_row;
    vector<int>::iterator it;
    vector<vector<int>> v;

};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next(); // 调用next后，当前元素失效，下一次调用next会输出下一个元素
 * bool param_2 = obj->hasNext(); // 只是判断当前是否还有元素。但我们把它设计为：调用next之前必先调用hasNext，hasNext确保我们当前指向了一个有效位置。
 */

int main(){
    vector<vector<int>> v={{1,2},{},{3},{4}};
    Vector2D* obj = new Vector2D(v);

    // TEST1：测试next功能
//    while(obj->hasNext()) cout<<obj->next()<<" ";
//    cout<<endl;

    // TEST2：测试remove删除的是前一个next输出的元素
//    cout<<obj->next()<<endl;
//    obj->remove();
//    obj->reset();
//    while(obj->hasNext()) cout<<obj->next()<<" ";
//    cout<<endl;

    // TEST3：测试remove删除的是前一个next输出的元素
//    cout<<obj->next()<<endl;
//    cout<<obj->next()<<endl;
//    obj->remove();
//    obj->reset();
//    while(obj->hasNext()) cout<<obj->next()<<" ";
//    cout<<endl;

    // TEST4：测试remove删除的是前一个next输出的元素
    cout<<obj->next()<<endl;
    cout<<obj->next()<<endl;
    cout<<obj->next()<<endl;
    obj->remove();
    obj->reset();
    while(obj->hasNext()) cout<<obj->next()<<" ";
    cout<<endl;

    // TEST5：测试remove删除的是前一个next输出的元素：因为之前没有调用next，所以什么都没有删除。
//    obj->remove();
//    obj->reset();
//    while(obj->hasNext()) cout<<obj->next()<<" ";
//    cout<<endl;

    return 0;

















    /* 这段代码说明erase当前元素后，后面的元素还是有效的
    vector<int> vec={1,2,3,4,5,6,7};
    auto it=vec.begin();
    while(!vec.empty()){
        cout<<*it<<" ";
        vec.erase(it);
    }
    cout<<endl;
    return 0;
     */
}