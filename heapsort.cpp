// heapsort
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums){
        heapSort(nums);
        return nums;
    }
private:
    void heapSort(vector<int> &nums){
        int n = nums.size();
        // build the largest heap
        for (int i = n / 2 - 1; i >= 0; i--){
            heapify(nums, n, i);
        }
        // take the largest element from the heap 
        //in order and rebuild the heap
        for (int i = n - 1; i > 0; i--){
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }
    void heapify(vector<int> &nums, int n, int root)
    {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        // compaire the left node and the root node
        if (left < n && nums[left] > nums[largest]){
            largest = left;
        }
        if (right < n && nums[right] > nums[largest]){
            largest = right;
        }
        if (largest != root){
            swap(nums[root], nums[largest]);
            heapify(nums, n, largest);
        }
    }
};