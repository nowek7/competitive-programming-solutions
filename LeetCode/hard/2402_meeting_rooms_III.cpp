#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

int mostBooked(int n, std::vector<std::vector<int>>& meetings)
{
  std::sort(meetings.begin(), meetings.end());

  std::priority_queue<int, std::vector<int>, std::greater<int>> freeRooms;
  for (int i = 0; i < n; ++i) {
    freeRooms.push(i);
  }

  std::priority_queue<
    std::pair<long long, int>,
    std::vector<std::pair<long long, int>>,
    std::greater<std::pair<long long, int>>>
    onGoingMeetings;

  std::vector<int> rooms(n, 0);
  for (auto meeting: meetings) {
    auto start = meeting[0];
    auto end = meeting[1];

    while (!onGoingMeetings.empty() && onGoingMeetings.top().first <= start) {
      freeRooms.push(onGoingMeetings.top().second);
      onGoingMeetings.pop();
    }

    if (!freeRooms.empty()) {
      auto available = freeRooms.top();
      freeRooms.pop();

      ++rooms[available];
      onGoingMeetings.push({end, available});
    } else {
      auto [onGoingMeetingEnd, roomIdx] = onGoingMeetings.top();
      onGoingMeetings.pop();

      ++rooms[roomIdx];
      onGoingMeetings.push({onGoingMeetingEnd + end - start, roomIdx});
    }
  }

  return std::max_element(rooms.begin(), rooms.end()) - rooms.begin();
}

int main()
{
  // 2402. Meeting Rooms III

  {
    std::vector<std::vector<int>> meetings = {
      {0, 10},
      {1,  5},
      {2,  7},
      {3,  4}
    };
    assert(mostBooked(2, meetings) == 0);
  }

  {
    std::vector<std::vector<int>> meetings = {
      {1, 20},
      {2, 10},
      {3,  5},
      {4,  9},
      {6,  8}
    };
    assert(mostBooked(2, meetings) == 1);
  }

  return 0;
}
