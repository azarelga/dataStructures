#include <iostream>
#include <list>
using namespace std;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  list<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.pop_front();
  cout << l.front();
}
