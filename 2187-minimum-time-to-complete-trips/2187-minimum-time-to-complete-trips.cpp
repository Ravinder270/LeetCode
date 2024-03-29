class Solution {
public:
   // this function will count totalTrips for the given time
	// a = [1,2,3] , and at time 3 how many trips we can take? 
	// 3/1 + 3/2 + 3/3 => 3 + 1 + 1 = 5 Trips
    long long int numberOfTripsForGivenTime(vector<int>&a , long long int givenTime)
    {
        long long int totalTrips = 0;
        for(auto x : a)
        {
            // convert it to long long int 
            long long int val = x;
			
            totalTrips += (givenTime / val);
        }
        return totalTrips;
    }
    long long minimumTime(vector<int>& arr ,  int totalTrips) {
        long long int lowestTime = 1;
        long long int highestTime = 1e14;
        while(lowestTime<highestTime)
        {
            long long int mid = lowestTime + (highestTime-lowestTime)/2;
            
            if(numberOfTripsForGivenTime(arr , mid) >= totalTrips)
                highestTime = mid;
            else
                lowestTime = mid+1;
        }
        return lowestTime;
    }
};