#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


class Solution {
public:
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

	bool get_value(vector<int> &a, int iofk, int value) {
		int v1 = value, v2 = value, cur_k;
		if (iofk < 0) return true;

		cur_k = 1 << iofk;
		for (int i = 0; i < a.size(); ++i) {
			if ((cur_k & a[i]) == 0) v1 += cur_k;
			else v2 += cur_k;
		}

		if (v1 <= m) {
			k |= cur_k;
			if (get_value(a, iofk - 1, v1)) return true;
		}
		if (v2 <= m) {
			k = (k >> (iofk + 1)) << iofk + 1;
			if (get_value(a, iofk - 1, v2)) return true;
		}
		return false;
	}

	int get_max_k(int max, vector<int> &a) {
		int len = get_size(a, max);
		k = 0;
		m = max;
		if (get_value(a, len, 0)) return k;
		else return -1;
	}
};

/*
int get_max_k(int m, vector<int> &a) {
    int k = 0, value = 0, temp_value1, temp_value2, 
        cur_k, len = get_size(a, m), flag;

    for (int i = len; i >= 0; --i) {
        cur_k = 1 << i;
        temp_value1 = value;
        temp_value2 = value;
		flag = 0;
        for (int j = 0; j < a.size(); ++j) {
            if ((cur_k & a[j]) == 0) temp_value1 += cur_k;
			else {
				temp_value2 += cur_k;
				++flag;
			}
        }
		if (flag <= a.size() - flag) {
			if (temp_value1 <= m) {
				k |= cur_k;
				value = temp_value1;
			} else if (temp_value2 <= m) {
				value = temp_value2;
			} else {
				return -1;
			}
		} else {
			if (temp_value2 <= m) {
				value = temp_value2;
			}else if (temp_value1 <= m) {
				k |= cur_k;
				value = temp_value1;
			} else {
				return -1;
			}
		}
    }
    return k;
}
*/

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
