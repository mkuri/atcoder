#include <iostream>
#include <string>

int main() {
  int N, Q;
  std::cin >> N >> Q;

  std::string s;
  for (int i = 0; i < N; i++) {
    s += (char)('A' + i);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N-1; j++) {
      std::cout << "? " << s.at(j) << " " << s.at(j+1) << std::endl;
      std::fflush(stdout);
      char ans;
      std::cin >> ans;
      if (ans == '>') {
        std::swap(s.at(j), s.at(j+1));
      }
    }
  }

  std::cout << "! " << s << std::endl;
  return 0;
}