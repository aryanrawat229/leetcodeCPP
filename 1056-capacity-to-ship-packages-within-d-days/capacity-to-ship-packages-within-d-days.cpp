class Solution {
public:
    // Helper: can we ship with given capacity in <= days?
    bool canShip(vector<int>& weights, int days, int capacity) {
        int daysUsed = 1;
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w <= capacity) {
                currentLoad += w;
            } else {
                // need a new day
                daysUsed++;
                currentLoad = w;

                // if days exceed limit, not possible
                if (daysUsed > days) return false;
            }
        }
        return true; // we shipped within allowed days
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxWeight = 0;
        int sum = 0;

        for (int w : weights) {
            maxWeight = max(maxWeight, w);
            sum += w;
        }

        int low = maxWeight;  // minimum capacity
        int high = sum;       // maximum capacity
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2; // capacity guess

            if (canShip(weights, days, mid)) {
                ans = mid;        // mid works, try smaller capacity
                high = mid - 1;
            } else {
                low = mid + 1;    // mid too small, increase
            }
        }

        return ans;
    }
};
