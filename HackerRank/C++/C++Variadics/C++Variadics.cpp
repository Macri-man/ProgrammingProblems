#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template <bool... bits>
int reversed_binary_value() {
    bool values[] = {bits...};
    int result = 0;
    for (size_t i = 0; i < sizeof...(bits); ++i) {
        if (values[i]) {
            result += (1 << i); 
        }
    }
    return result;
}

template <int N = 0, bool... bits>
typename enable_if<N == 6>::type
generate(string& output, int x, int y) {
    int val = reversed_binary_value<bits...>();
    int range_val = 64 * y + val;
    output += (range_val == x ? '1' : '0');
}

template <int N = 0, bool... bits>
typename enable_if<N < 6>::type
generate(string& output, int x, int y) {
    generate<N + 1, 0, bits...>(output, x, y); 
    generate<N + 1, 1, bits...>(output, x, y);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y; 
        string output;
        generate(output, x, y);
        cout << output << '\n';
    }
    return 0;
}