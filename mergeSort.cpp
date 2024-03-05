// mergesort
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums){
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
private:
    void mergeSort(vector<int> &nums, int low, int high){
        if (low < high){
            int mid = (high + low) / 2;
            mergeSort(nums, low, mid);
            mergeSort(nums, mid + 1, high);
            merge(nums, low, mid, high);
        }
    }
    void merge(vector<int> &nums, int low, int mid, int high){
        int n1 = mid - low + 1;
        int n2 = high - mid;
        vector<int> left(n1);
        vector<int> right(n2);
        for (int i = 0; i < n1; i++)
            left[i] = nums[low + i];
        for (int j = 0; j < n2; j++)
            right[j] = nums[mid + 1 + j];
        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2){
            if (left[i] <= right[j]){
                nums[k] = left[i];
                i++;
            }
            else{
                nums[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < n1){
            nums[k] = left[i];
            i++;
            k++;
        }
        while (j < n2){
            nums[k] = right[j];
            j++;
            k++;
        }
    }
};