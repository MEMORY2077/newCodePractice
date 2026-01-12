#include <vector>
#include <queue>
using namespace std;
class MedianFinder {
    public:
        MedianFinder() {
            
        }
        
        void addNum(int num) {
            //先顺清思路吧
            //规定如果两边个数不相等的话，必须左比右多一个
            //那么，如果现在来了一个数
            //若两边个数相等
            //看他是否足够大，大的放右边，然后从右边踢出来一个放左边
            //如果他还足够小，小的放左边，就没有然后了
            //如果都空呢，放左边
            //如果两边个数不相等，肯定是左边多，右边少
            //看他是否足够大，足够大直接放右边，然后不踢
            //看他是否足够小，足够小直接放左边，然后踢一个
            //换个想法呢
            //直接看他是否足够大，大的放右边，如果此时右边比左边多了，就踢一个放左边
            //看他是否足够小，小的放左边，如果左边比右边多了两个，就踢一个放右边
            //空了就直接放左边
            //思考结束
            if(right.size()==left.size()){
                right.push(num);
                int outNum=right.top();
                right.pop();
                left.push(outNum);
                return;
            }
            else{
                left.push(num);
                int outNum=left.top();
                left.pop();
                right.push(outNum);
            }
        }
        
        double findMedian() {
            if(left.size()>right.size()) return left.top();
            return (left.top()+right.top())/2.0;
        }
    private:
    priority_queue<int,vector<int>,less<>>left;
    priority_queue<int,vector<int>,greater<>>right;
    };