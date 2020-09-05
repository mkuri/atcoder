#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>

void dfs(int x, int y, std::vector<std::vector<char>> &field) {
  std::cout << "dfs x: " << x << ", y:" << y << std::endl;
  field.at(y).at(x) = '.';

  int max_x = field.at(0).size();
  int max_y = field.size();
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      int nx = x + dx;
      int ny = y + dy;

      if (0 <= nx && nx < max_x && 0 <= ny && ny < max_y)
      {
        if (field.at(ny).at(nx) == 'W') dfs(nx, ny, field);
      }
    }
  }
}

int main() {
  std::ifstream ifs("2-1-field.txt");
  std::string buf;
  std::vector<std::vector<char>> field;
  while (std::getline(ifs, buf)) {
    std::vector<char> line;
    for (char c : buf) {
      line.push_back(c);
    }
    field.push_back(line);
  }

  auto start = std::chrono::system_clock::now();
  int count = 0;
  for (int y = 0; y < field.size(); y++) {
    for (int x = 0; x< field.at(y).size(); x++) {
      if (field.at(y).at(x) == 'W') {
        count++;
        dfs(x, y, field);
      }
    }
  }
  auto end = std::chrono::system_clock::now();
  std::cout << "count: " << count << std::endl;
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us needed" << std::endl;

  return 0;
}