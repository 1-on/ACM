#include "bits/stdc++.h"

using namespace std;

int n, b;
vector <string> leibie;
map<string, int> map1;
struct node {
    string type, name;
    int price, quality;
} a[1005];

int check(long long x) {
    int sum = 0;
    for (int i = 0; i < leibie.size(); i++) {
        int qua = 1000000005, pri = 1000000005;
        for (int j = 0; j < n; j++) {
            if (a[j].type == leibie[i]) {
                //cout<<a[j].type<<" "<<a[j].name<<" "<<a[j].price<<" "<<a[j].quality<<" "<<x<<" "<<qua<<endl;
                if (a[j].quality >= x && a[j].price <= pri) {
                    qua = a[j].quality;
                    pri = a[j].price;
                }
            }
        }
        if (qua == 1000000005) return 0;
        sum += pri;
        //cout<<"sum="<<sum<<endl;
        if (sum > b) return 0;
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        leibie.clear();
        map1.clear();
        cin >> n >> b;
        long long minq = 1000000005, maxq = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i].type >> a[i].name >> a[i].price >> a[i].quality;
            if (map1.count(a[i].type) == 0) {
                leibie.push_back(a[i].type);
                map1[a[i].type] = 1;
            }
            if (a[i].quality < minq) minq = a[i].quality;
            if (a[i].quality > maxq) maxq = a[i].quality;
        }
        long long l = minq, r = maxq;
        long long ans = 0;
        while (l <= r) {

            long long mid = (l + r) / 2;
            //cout<<l<<" "<<r<<" "<<mid<<endl;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << endl;
    }
}
/*
Sample Input
1
18 800
processor 3500_MHz 66 5
processor 4200_MHz 103 7
processor 5000_MHz 156 9
processor 6000_MHz 219 12
memory 1_GB 35 3
memory 2_GB 88 6
memory 4_GB 170 12
mainbord all_onboard 52 10
harddisk 250_GB 54 10
harddisk 500_FB 99 12
casing midi 36 10
monitor 17_inch 157 5
monitor 19_inch 175 7
monitor 20_inch 210 9
monitor 22_inch 293 12
mouse cordless_optical 18 12
mouse microsoft 30 9
keyboard office 4 10
 */
/*
Sample Output
9
 */