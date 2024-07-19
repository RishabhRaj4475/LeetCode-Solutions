class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int N = seats.size();
        int K = 0;
        int ans = 0;

        for (int i = 0; i < N; ++i) {
            if (seats[i] == 1) {
                K = 0;
            } else {
                K++;
                ans = max(ans, (K + 1) / 2);
            }
        }

        for (int i = 0; i < N; ++i)  if (seats[i] == 1) {
            ans = max(ans, i);
            break;
        }

        for (int i = N-1; i >= 0; --i)  if (seats[i] == 1) {
            ans = max(ans, N - 1 - i);
            break;
        }

        return ans;
    }
};