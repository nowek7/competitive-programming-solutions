#include <cassert>
#include <stack>
#include <vector>

int sumSubarrayMins(std::vector<int>& arr)
{
  const int mod = 1e9 + 7;

  long sum = 0;
  std::stack<int> heap;
  for (int i = 0; i <= arr.size(); ++i) {
    while (!heap.empty() && (i == arr.size() || arr[heap.top()] >= arr[i])) {
      int mid = heap.top();
      heap.pop();

      int left = heap.empty() ? -1 : heap.top();
      int right = i;

      long count = (mid - left) * (right - mid) % mod;
      sum += (count * arr[mid]) % mod;
      sum %= mod;
    }

    heap.push(i);
  }

  return sum;
}

int main()
{
  // 907. Sum of Subarray Minimums

  {
    std::vector<int> arr = {3, 1, 2, 4};
    assert(sumSubarrayMins(arr) == 17);
  }

  {
    std::vector<int> arr = {11, 81, 94, 43, 3};
    assert(sumSubarrayMins(arr) == 444);
  }

  return 0;
}
