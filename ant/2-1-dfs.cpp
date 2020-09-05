#include <iostream>
#include <vector>
#include <chrono>

bool dfs(int i, int sum, std::vector<int> &a, int k) {
  if (i == a.size()) return sum == k;
  
  if (dfs(i+1, sum, a, k)) return true;

  if (dfs(i+1, sum + a.at(i), a, k)) return true;

  return false;
}

int main() {
  int n = 4;
  std::vector<int> a{1, 2, 4, 7};
  int k = 15;

  auto start = std::chrono::system_clock::now();
  if (dfs(0, 0, a, k)) {
    std::cout << "yes" << std::endl;
  } else {
    std::cout << "no" << std::endl;
  }
  auto end = std::chrono::system_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
}