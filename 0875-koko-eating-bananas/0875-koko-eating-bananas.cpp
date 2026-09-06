class Solution {
private:
    bool testSpeed(vector<int>& piles, int speed, int h) {
        // FIX 1: Use long long instead of int to prevent integer overflow.
        // Summing (bananas / speed) across multiple piles can exceed 2^31 - 1,
        // which causes negative wrap-around and leads to false positives/wrong answers.
        long long hoursPassed = 0;
        int noPiles = piles.size();

        for (int i = 0; i < noPiles; i++) {
            int bananas = piles[i];
            if (bananas > speed) {
                int rem = bananas % speed;
                if (rem == 0) {
                    hoursPassed += bananas / speed;
                } else {
                    // FIX 2: Add 1 hour for the remaining bananas, NOT 'rem'.
                    // Eating remaining bananas (rem < speed) takes exactly 1 extra hour,
                    // not 'rem' hours (e.g., if bananas=7 and speed=4, rem=3 -> 1 hr + 1 hr = 2 hrs,
                    // whereas 1 + 3 = 4 hrs would be incorrect).
                    hoursPassed += (bananas / speed) + 1;
                }
            } else {
                hoursPassed++;
            }
            
            // Early exit optimization: stop evaluating as soon as hours exceed limit
            if (hoursPassed > h) return false;
        }
        return true;
    }

    int findKBinary(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int minK = high;

        while (low <= high) {
            // Correct midpoint calculation avoids both overflow and zero/negative bounds
            int mid = low + (high - low) / 2;

            if (testSpeed(piles, mid, h)) {
                minK = mid;
                high = mid - 1; // Try to find a smaller valid eating speed
            } else {
                low = mid + 1;  // Speed too slow, search higher
            }
        }
        return minK;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        return findKBinary(piles, h);
    }
};