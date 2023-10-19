#include <iostream>
#include <cmath>

using namespace std;

int binary_search(int l, int h, int t) {
    if(h >= 1) {
        int mid = l + (h - l) / 2;

        if(mid == t) {
            return 1;
        }
        if(mid > t) {
            return binary_search(l, mid - 1, t) + 1;
        }
        return binary_search(mid + 1, h, t) + 1;
    }
    else {
        return 0;
    }
}

int recursive(int l, int h, int k, int t, int j) {
    if(k == 1) {
        if(l == t) {
            return 1;
        }
        else {
            return recursive(l + 1, h, k, t, j) + 1;
        }
    }
    else {
        j = ceil(-0.5 + sqrt(1 + 8 * j) / 2);

        if(l + j < t) {
            return recursive(l + j + 1, h, k, t, h - j) + 1;
        }
        else {
            return recursive(l, l + j - 1, k - 1, t, j) + 1;
        }
    }
}

int main() {
    int n, k, t;
    cin >> n, k, t;
    if(k >= log2(n)) {
        cout << binary_search(0, n, t);
    }
    else {
        cout << recursive(0, n, k, t, n);
    }
}