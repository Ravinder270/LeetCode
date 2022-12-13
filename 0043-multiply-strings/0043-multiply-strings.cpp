class Solution {
public:
    string multiply(string num1, string num2) {
        int m=num1.size();
        int n=num2.size();
        string product;
        product.resize(n+m,'0');
        
        for(int i=m-1;i>=0;i--)
        {
            int carry=0;
            for(int j=n-1;j>=0;j--)
            {
             int sum=(num1[i] -'0')*(num2[j]-'0')+(product[i+j+1]-'0')+carry;
             int rem=sum%10;
             carry=(sum-rem)/10;
             product[i+j+1]=rem+'0';   
            }
            product[i]=carry+'0';
        }
        int i=0;
        for(;i<product.size()-1 &&product[i]=='0';i++);
        if(i>0)
        {
            product.erase(product.begin(),product.begin()+i);
        }
        
        return product;
    }
};