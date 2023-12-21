//
//  main.cpp
//  SaftyTheNumber
//
//  Created by AnhNguyen on 02/12/2023.
//

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int s[205];

bool check(double mid, int n, int sum){
    double sumProb = 0;
    for(int i = 1; i <= n; i++)
        sumProb += (double)(max(0.0, mid - s[i]))/sum;
    return (sumProb >= 1.0);
}

double getThreshold(int n, int sum){
    double l = 0.0, r = sum;
    for(int i = 1; i <= 100; i++){
        double mid = (l+r)/2.0;
        if(check(mid, n, sum)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int main(){
    int nTest;
    cin >> nTest;
    for(int iTest = 1; iTest <= nTest; iTest++){
        int n; 
        cin >> n;
        int sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> s[i];
            sum += s[i];
        }
        double threshold = getThreshold(n, sum);
        cout << "Case #" << iTest << ": ";
        for(int i = 1; i <= n; i++){
            double percent;
            percent = (double)(threshold - s[i])/sum*100;
            if(percent < 0)
                cout << fixed << setprecision(6) << 0.0 << ' ';
            else cout << fixed << setprecision(6) << percent << ' ';
        }
        cout << '\n';
    }
}
