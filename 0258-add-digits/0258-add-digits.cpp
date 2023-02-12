class Solution {
public:
    
    int digsum(int num)
    {
        int res=0;
        while(num!=0)
        {
            res+=num%10;
            num=num/10;
        }
        return res;
    }
    
    int addDigits(int num) {
       
        if(digsum(num)<10)return digsum(num);
        
        while(digsum(num)>=10)
        {
            num=digsum(num);
        }
        return digsum(num);
    }
};