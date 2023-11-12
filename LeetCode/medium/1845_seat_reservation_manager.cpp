class SeatManager
{
private:
  std::priority_queue<int, std::vector<int>, std::greater<int>> m_reservedSeats;
  int smallestNumSeat = 0;

public:
  SeatManager(int n)
  {
  }

  int reserve()
  {
    if (m_reservedSeats.empty()) {
      return ++smallestNumSeat;
    }
    const int reservedNum = m_reservedSeats.top();
    m_reservedSeats.pop();
    return reservedNum;
  }

  void unreserve(int seatNumber)
  {
    m_reservedSeats.push(seatNumber);
  }
};

int main()
{
  // 1845. Seat Reservation Manager
  return 0;
}