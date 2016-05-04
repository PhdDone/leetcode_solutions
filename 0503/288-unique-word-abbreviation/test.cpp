#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  std::unordered_map<std::string, vector<string>> mp;
  mp["a"].push_back("b");
  cout <<mp["a"][0] << endl;
  return 0;
}
