#include <iostream>
#include <vector>
#include <chrono>

std::vector<int> a{1, 2, 4, 7};
int k = 15;

bool dfs(int i, int sum) {
  if (i == a.size()) return sum == k;
  
  if (dfs(i+1, sum)) return true;

  if (dfs(i+1, sum + a.at(i))) return true;

  return false;
}

int main() {
  auto start = std::chrono::system_clock::now();
  if (dfs(0, 0)) {
    std::cout << "yes" << std::endl;
  } else {
    std::cout << "no" << std::endl;
  }
  auto end = std::chrono::system_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us" << std::endl;
}