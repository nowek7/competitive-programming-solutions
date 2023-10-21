#include <cassert>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool validateBinaryTreeNodes(int n, std::vector<int>& leftChild, std::vector<int>& rightChild)
{
  const int len = leftChild.size();
  std::unordered_map<int, std::vector<int>> graph;
  std::vector<int> degree(len, 0);

  for (int node = 0; node < len; ++node) {
    int left = leftChild[node];
    int right = rightChild[node];
    if (left != -1) {
      graph[node].push_back(left);
      degree[left]++;
    }
    if (right != -1) {
      graph[node].push_back(right);
      degree[right]++;
    }
  }

  std::vector<int> rootCandidates;
  for (int node = 0; node < len; ++node) {
    if (degree[node] == 0) {
      rootCandidates.push_back(node);
    }
  }

  if (rootCandidates.size() != 1) {
    return false;
  }

  const int root = rootCandidates.front();
  std::queue<int> line;
  line.push(root);
  std::unordered_set<int> visited;
  visited.insert(root);

  while (!line.empty()) {
    int node = line.front();
    line.pop();

    if (graph.find(node) != graph.end()) {
      for (int child: graph[node]) {
        if (visited.find(child) != visited.end()) {
          return false;
        }
        visited.insert(child);
        line.push(child);
      }
    }
  }

  return visited.size() == len;
}

int main()
{
  // 1361. Validate Binary Tree Nodes

  {
    std::vector<int> leftChild = {1, -1, 3, -1};
    std::vector<int> rightChild = {2, -1, -1, -1};
    assert(validateBinaryTreeNodes(4, leftChild, rightChild) == true);
  }

  {
    std::vector<int> leftChild = {1, -1, 3, -1};
    std::vector<int> rightChild = {2, 3, -1, -1};
    assert(validateBinaryTreeNodes(4, leftChild, rightChild) == false);
  }

  {
    std::vector<int> leftChild = {1, 0};
    std::vector<int> rightChild = {-1, -1};
    assert(validateBinaryTreeNodes(2, leftChild, rightChild) == false);
  }

  return 0;
}
