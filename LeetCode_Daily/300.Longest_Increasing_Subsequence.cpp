//
//  main.cpp
//  2125.LaserBeams
//
//  Created by AnhNguyen on 02/01/2024.
//

#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> a(nums.size(), 0);
    int res = 0;
    for (int n : nums) {
        int l = 0;
        int r = res;
        while (l != r) {
            int m = (l + r)/2;
            if (a[m] < n) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        a[l] = n;
        if (l == res) {
            res++;
        }
    }
    return res;
}

        
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    lengthOfLIS(a);
    return 0;
}
