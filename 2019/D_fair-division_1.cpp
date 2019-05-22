#include <cstdlib>
#include <iostream>
#include <regex>

using namespace std;

long long CountMinBasketNum(long long basket_size, long long student_count) {
  long long d = __gcd(basket_size, student_count);

//  cerr << basket_size << ", delitsya na " << student_count
//       << ", nuzhno " << (basket_size / d) * student_count << " vyoder" << endl;

  return student_count / d;
}

int main() {
  freopen("fair-division.in", "r", stdin);
  freopen("fair-division.out", "w", stdout);

  int student_count, basket_count;
  cin >> student_count >> basket_count;

  vector<int> basket_sizes(basket_count);
  for (int i = 0; i < basket_count; ++i) {
    cin >> basket_sizes[i];
  }

  vector<int> basket_costs(basket_count);
  for (int i = 0; i < basket_count; ++i) {
    cin >> basket_costs[i];
  }

  long long min_cost = 1e18;
  for (int i = 0; i < basket_count; ++i) {
    long long basket_size = basket_sizes[i];
    long long basket_cost = basket_costs[i];
    min_cost = min(min_cost,
        basket_cost * CountMinBasketNum(basket_size, student_count));
  }

  cout << min_cost << endl;
}