#include <iostream>
#include <vector>
#include <queue>  // For using priority_queue (min heap in this case)

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    // Create a min-heap using a priority queue
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Push the first k elements into the heap
    for (int i = 0; i < k; i++) {
        minHeap.push(nums[i]);
    }

    // Iterate through the rest of the array
    for (int i = k; i < nums.size(); i++) {
        // If the current element is greater than the root of the heap
        if (nums[i] > minHeap.top()) {
            // Pop the smallest element and push the current element
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }

    // The root of the heap is the k-th largest element
    return minHeap.top();
}

int main() {
    // Example input
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    // Find the k-th largest element
    int result = findKthLargest(nums, k);

    // Print the result
    cout << "The " << k << "-th largest element is: " << result << endl;

    return 0;
}
