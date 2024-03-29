class Solution {
public:
     int maximumUnits(vector<vector<int>>& boxes, int truckSize) {
        // support variables
        int res = 0, sizeBucket[1001] = {}, maxBucket = INT_MIN, minBucket = INT_MAX;
        // bucket sorting tthe boxes and recording the bucket range
        for (auto &boxType: boxes) {
            maxBucket = max(maxBucket, boxType[1]);
            minBucket = min(minBucket, boxType[1]);
            sizeBucket[boxType[1]] += boxType[0];
        }
		// carrying as many larger sized boxes as we can first
        for (int i = maxBucket, size, currBatch; i >= minBucket; i--) {
            size = sizeBucket[i];
            if (!size) continue;
            currBatch = min(size, truckSize);
            truckSize -= currBatch;
            res += currBatch * i;
            if (!truckSize) break;
        }
        return res;
    }
};