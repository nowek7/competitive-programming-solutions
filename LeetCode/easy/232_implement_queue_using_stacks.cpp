#include <stack>

class MyQueue
{
private:
  std::stack<int> m_start;
  std::stack<int> m_end;
  int frontElem;

public:
  MyQueue()
  {
  }

  void push(int x)
  {
    if (m_start.empty()) {
      frontElem = x;
    }
    m_start.push(x);
  }

  int pop()
  {
    if (m_end.empty()) {
      while (!m_start.empty()) {
        int x = m_start.top();
        m_start.pop();
        m_end.push(x);
      }
    }

    int x = m_end.top();
    m_end.pop();
    return x;
  }

  int peek()
  {
    if (!m_end.empty()) {
      frontElem = m_end.top();
    }
    return frontElem;
  }

  bool empty()
  {
    return m_start.empty() && m_end.empty();
  }
};

int main()
{
  // 232. Implement Queue using Stacks

  /**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

  return 0;
}
