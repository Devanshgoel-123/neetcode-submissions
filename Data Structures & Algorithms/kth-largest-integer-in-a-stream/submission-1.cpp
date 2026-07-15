class KthLargest {
public:
    vector<int> elementsListed;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        sort(nums.begin(), nums.end());
        int start = max(0, (int)nums.size() - k);
        for (int i = start; i < nums.size(); i++) {
            elementsListed.push_back(nums[i]);
        }
    }
    
    int add(int val) {
        if (elementsListed.size() < k) {
            elementsListed.push_back(val);
            int index = elementsListed.size() - 1;
            while (index > 0 && elementsListed[index] < elementsListed[index - 1]) {
                swap(elementsListed[index], elementsListed[index - 1]);
                index--;
            }

            return elementsListed[0];
        }
        if (val <= elementsListed[0]) return elementsListed[0];
        for (int i = 1; i < elementsListed.size(); i++) {
            elementsListed[i - 1] = elementsListed[i];
        }
        int index = elementsListed.size() - 1;
        while (index > 0 && elementsListed[index - 1] > val) {
            elementsListed[index] = elementsListed[index - 1];
            index--;
        }
        elementsListed[index] = val;
        return elementsListed[0];
    }
};
