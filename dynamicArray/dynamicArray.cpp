#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  cout << v.at(0);
}
