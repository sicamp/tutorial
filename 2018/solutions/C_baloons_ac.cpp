#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

int main() {

    freopen("baloons.in", "r", stdin);
    freopen("baloons.out", "w", stdout);

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> ans(1 << 16, -1);
	for (int i = 1; i < (1 << 16); i++) {
		if ((i ^ (i * 2)) > ((1 << 16) - 1)) {
			continue;
		}
		ans[i ^ (i * 2)] = ans[i ^ (i * 2)] == -1 ? i : ans[i ^ (i * 2)];
	}

	for (int i = 0; i < n; i++) {
		int cur;
		std::cin >> cur;
		std::cout << ans[cur] << ' ';
	}
}
