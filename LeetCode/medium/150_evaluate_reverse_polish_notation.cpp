#include <cassert>
#include <climits>
#include <stack>
#include <string>
#include <vector>

int evalRPN(std::vector<std::string>& tokens)
{
  auto isAdd = [](const std::string& token) {
    return token == "+";
  };
  auto isSub = [](const std::string& token) {
    return token == "-";
  };
  auto isMul = [](const std::string& token) {
    return token == "*";
  };
  auto isDiv = [](const std::string& token) {
    return token == "/";
  };
  auto isOperator = [&](const std::string& token) {
    return isAdd(token) || isSub(token) || isMul(token) || isDiv(token);
  };

  std::stack<int> heap;
  for (int i = 0; i < tokens.size(); ++i) {
    if (isOperator(tokens[i])) {
      int right = heap.top();
      heap.pop();
      int left = heap.top();
      heap.pop();

      if (isMul(tokens[i])) {
        heap.push(left * right);
      }
      if (isDiv(tokens[i])) {
        heap.push(left / right);
      }
      if (isAdd(tokens[i])) {
        heap.push(left + right);
      }
      if (isSub(tokens[i])) {
        heap.push(left - right);
      }
    } else {
      heap.push(std::atoi(tokens[i].c_str()));
    }
  }

  assert(heap.size() == 1);

  return heap.top();
}

int main()
{
  // 150. Evaluate Reverse Polish Notation

  {
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    assert(evalRPN(tokens) == 9);
  }

  {
    std::vector<std::string> tokens = {"4", "13", "5", "/", "+"};
    assert(evalRPN(tokens) == 6);
  }

  return 0;
}
