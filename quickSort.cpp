// Quicksort
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums){
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
private:
    void quickSort(vector<int> &nums, int low, int high){
        if (low >= high)
            return;
        int pivotIndex = partition(nums, low, high);
        quickSort(nums, low, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, high);
    }
    int partition(vector<int> &nums, int low, int high){
        int pivot = nums[high];
        int i = low - 1;
        for (int j = low; j < high; j++){
            if (nums[j] <= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[high], nums[i + 1]);
        return i + 1;
    }
};
