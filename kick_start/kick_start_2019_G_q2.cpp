#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


class Solution {
public:
	int *zeros, *ones;
	int k;
	int m;

	int get_size(vector<int> &a, int max) {
		int n = 1;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] > max) max = a[i];
		}
		while (max >> n != 0) ++n;
		return n - 1;
	}

	void init_elems(vector<int> &a, int size) {
		zeros = new int[size];
		ones = new int[size];

		--size;
		while (size >= 0) {
			zeros[size] = 0;
			ones[size] = 0;
			int cur_k = 1 << size;
			for (int i = 0; i < a.size(); ++i) {
				if ((a[i] & cur_k) == 0) zeros[size] += cur_k;
				else ones[size] += cur_k;
			}
			--size;
		}
	}

	bool get_value(vector<int> &a, int iofk, int value) {
		if (iofk < 0) return true;

		if (value + zeros[iofk] <= m) {
			k |= (1 << iofk);
			if (get_value(a, iofk - 1, value + zeros[iofk])) return true;
		}
		if (value + ones[iofk] <= m) {
			k = (k >> (iofk + 1)) << (iofk + 1);
			if (get_value(a, iofk - 1, value + ones[iofk])) return true;
		}
		return false;
	}

	int get_max_k(int max, vector<int> &a) {
		int len = get_size(a, max);
		k = 0;
		m = max;
		init_elems(a, len + 1);
		if (get_value(a, len, 0)) return k;
		else return -1;
	}
};


int main(int argc, char **argv) {
	Solution s;
    int at, t = 1, n, m, value;

    scanf("%d", &at);
    while (t <= at) {
        vector<int> A;
        scanf("%d %d", &n, &m);
        while (n) {
            scanf("%d", &value);
            A.push_back(value);
            --n;
        }
        value = s.get_max_k(m, A);
        printf("Case #%d: %d\n", t, value);
        ++t;
    }
}
