#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int Na, Nb, Nc, ta, tb, tc, k;
    cin >> Na >> Nb >> Nc >> ta >> tb >> tc >> k;

    vector<int> a(Na), b(Nb), c(Nc);

    // Nhập thông tin thời điểm xuất phát của các chuyến xe
    for (int i = 0; i < Na; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < Nb; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < Nc; i++) {
        cin >> c[i];
    }

    // Sắp xếp các mảng thời điểm xuất phát theo thứ tự tăng dần
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    int result = -1;

    // Duyệt qua các khả năng phá hủy k chuyến xe
    for (int i = 0; i <= min(k, Na); i++) {
        // Kiểm tra xem có đủ số chuyến xe từ A đến B và từ C đến D sau khi Bob phá hủy k chuyến xe không
        if (k - i <= Nb && k - i <= Nc) {
            // Tính thời điểm mà Alice có thể tới D
            int arrival_time = max({a[i] + ta, b[k - i - 1] + tb, c[Nc - (k - i) - 1] + tc});

            // Cập nhật thời điểm sớm nhất nếu là lựa chọn tối ưu
            if (result == -1 || arrival_time < result) {
                result = arrival_time;
            }
        }
    }

    cout << result << endl;

    return 0;
}
