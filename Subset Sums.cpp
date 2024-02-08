#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int ans = 0;
    int totalSubsets = 1 << N; // total number of subsets

    for (int mask = 0; mask < totalSubsets; mask++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                sum += S[i];
            }
        }
        if (sum >= A && sum <= B) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
