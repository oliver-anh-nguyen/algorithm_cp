//
//  main.cpp
//  TrainTimetable
//
//  Created by AnhNguyen on 22/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Train {
    int start, finish, id;
};

int convert(string s) {
    return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + s[4] - '0';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int k = 1; k <= tc; k++) {
        int t;
        cin >> t;
        int na, nb;
        cin >> na >> nb;
        string start, finish;
        vector<Train> trains;
        for (int i = 0; i < na; i++) {
            cin >> start >> finish;
            trains.push_back({convert(start), convert(finish), 0});
        }
        
        for (int i = 0; i < nb; i++) {
            cin >> start >> finish;
            trains.push_back({convert(start), convert(finish), 1});
        }
        
        sort(trains.begin(), trains.end(), [](const Train &a, const Train &b) {
            return a.start < b.start;
        });
        
        int cnt[2] = {0};
        priority_queue<int, vector<int>, greater<int>> heap[2];
        for (int i = 0; i < trains.size(); i++) {
            int id = trains[i].id;
            if (!heap[id].empty() && heap[id].top() <= trains[i].start) {
                heap[id].pop();
            } else {
                cnt[id] += 1;
            }
            heap[1 - id].push(trains[i].finish + t);
        }
        cout << "Case #" << k << ": " << cnt[0] << ' ' << cnt[1] << '\n';
    }
    return 0;
}
