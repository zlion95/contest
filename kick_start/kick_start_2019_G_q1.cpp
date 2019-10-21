#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int get_totla(int n, vector<int> r) {
    int result = 0;
    for (int i = 0; i < r.size(); ++i) result += n / r[i];
    return result;
}

int main(int argc, char **argv) {
    string str;
    int n, m, q, t, value, c_all, c = 1;
    vector<int> p, r;
    
    cin >> c_all;
    while (scanf("%d %d %d", &n, &m, &q) != EOF) {
        p.clear();
        r.clear();
        while (m) {
            scanf("%d", &value);
            p.push_back(value);
            --m;
        }

        while (q) {
            scanf("%d", &value);
            r.push_back(value);
            --q;
        }
        value = 0;

        for (int i = 0; i < r.size(); ++i) value += n / r[i];
        for (int i = 0; i < p.size(); ++i) {
            for (int j = 0; j < r.size(); ++j) {
                if (p[i] % r[j] == 0) --value;
            }
        }
        printf("Case #%d: %d\n", c++, value);
    }
}
