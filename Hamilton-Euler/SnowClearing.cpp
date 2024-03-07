#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int t = stoi(s);
    getline(cin, s);
    while (t--) {
        getline(cin, s);
        double sum = 0;
        while (1) {
            getline(cin, s);
            if (s == "") break;
            s += " ";
            vector<int> v;
            string tmp = "";
            for (auto c : s) {
                if (c == ' ') {
                    v.push_back(stoi(tmp));
                    tmp = "";
                }
                else tmp += c;
            }
            sum += sqrt((v[0] - v[2]) * (v[0] - v[2]) + (v[1] - v[3]) * (v[1] - v[3]));
        }
        sum = sum * 6 / 1000;
        if ((int)sum + 0.5 <= sum) sum++;
        int h = (int)sum / 60;
        int m = (int)sum % 60;
        cout << h << ":" << (m < 10 ? "0" : "") << m << '\n';
    }
    return 0;
}
