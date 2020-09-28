class Solution {
private:
    typedef struct item{
        int idx;
        int val;
    }ITEM;

public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        ITEM items[100000];
        for (int i = 0; i<nums.size(); ++i){
            items[i].idx = i;
            items[i].val = nums[i];
        }
        
        sort(items, items + nums.size(), [](ITEM i1, ITEM i2){return i1.val < i2.val;});
        for (int i = 0, j = nums.size()-1; i < j;){
            //cout << items[i].val << " " << items[j].val << endl;
            int tmp = items[i].val + items[j].val;
            if (tmp > target)
                --j;
            else if(tmp < target)
                ++i;
            else
                return {items[i].idx, items[j].idx};
        }
        return {0, 0};
    }
};