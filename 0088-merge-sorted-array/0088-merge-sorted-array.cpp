class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
         
        int x=m+n;
        for(int i=0;i<nums2.size();i++)
         {
            if(m<x)
            {
                nums1[m]=nums2[i];
                m++;
            } 
            
         }
         n=nums1.size()+nums2.size();
        sort(nums1.begin(),nums1.end());
        
    }
};