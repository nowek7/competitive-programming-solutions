#include <algorithm>
#include <cassert>
#include <vector>

int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit)
{
  std::vector<std::tuple<int, int, int>> jobs(profit.size());
  for (int i = 0; i < jobs.size(); ++i) {
    jobs[i] = {endTime[i], startTime[i], profit[i]};
  }
  std::sort(jobs.begin(), jobs.end());

  std::vector<int> scheduledJobs(jobs.size() + 1);
  for (int i = 0; i < jobs.size(); ++i) {
    auto [endTime, startTime, earn] = jobs[i];
    int latestNonConflicJobIdx = std::upper_bound(
                                   jobs.begin(),
                                   jobs.begin() + i,
                                   startTime,
                                   [&](int time, const auto& job) {
                                     return time < std::get<0>(job);
                                   }
                                 )
      - jobs.begin();

    scheduledJobs[i + 1] = std::max(scheduledJobs[i], scheduledJobs[latestNonConflicJobIdx] + earn);
  }

  return scheduledJobs.back();
}

int main()
{
  // 1235. Maximum Profit in Job Scheduling

  {
    std::vector<int> startTime = {1, 2, 3, 3};
    std::vector<int> endTime = {3, 4, 5, 6};
    std::vector<int> profit = {50, 10, 40, 70};
    assert(jobScheduling(startTime, endTime, profit) == 120);
  }

  {
    std::vector<int> startTime = {1, 2, 3, 4, 6};
    std::vector<int> endTime = {3, 5, 10, 6, 9};
    std::vector<int> profit = {20, 20, 100, 70, 60};
    assert(jobScheduling(startTime, endTime, profit) == 150);
  }

  return 0;
}
