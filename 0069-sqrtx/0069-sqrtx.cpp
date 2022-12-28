class Solution {
public:
    int mySqrt(int A) {
       
    if(A<=0)
    return 0;
   
    if(A==1)
    return 1;
   
    long  l=1,h=A;
   
    long long res=INT_MIN;
    while(l<h)
    {
        long long mid = (l+h)/2;
       
        if(mid*mid==A)
        return mid;
       
        else if(mid*mid<A)
        {
            res=max(res,mid);
            l=mid+1;
        }
       
        else
        h=mid;
       
    }
   
    return res;
}
    
};