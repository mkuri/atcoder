#include <iostream>
#include <string>

int main() {
  int a, b, c;
  std::string s;

  std::cin >> a >> b >> c >> s;

  int sum = a + b + c;
  std::cout << sum << " " << s << std::endl;

  return 0;
}