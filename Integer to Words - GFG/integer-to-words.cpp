//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
   string convertToWords(long n) {
        // code here
        map<int,string>p;
        p[1]="1";
        p[2]=" 2";
        p[3]="hundred ";
        p[4]="thousand ";
        p[5]="thousand 0";
        p[6]="lakh ";
        p[7]="lakh 0";
        p[8]="crore ";
        p[9]="crore 0";
        
        string ones[20] = {"","one ", "two ","three ","four ", "five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ","thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "};
string tens[10] = {"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};
        string s=to_string(n);
        int k=s.length();
        string ans="";
        int i=0;
        while(k>0){
            if(p[k][p[k].length()-1]=='0'||p[k][p[k].length()-1]=='2'){
                int l=(int(s[i]-'0')*10)+int(s[i+1]-'0');
                
                if(l<20 && l!= 0 && s[i]!='0'){
                     if(p[k][p[k].length()-1]=='2' && s.length()>2&s[i]!='0'){
                     ans+="and ";
                    
                }
                     ans+=ones[l];
                     ans+=p[k];
                     ans.pop_back();
                     i+=2; k-=2;
                }else if(l>=20 && l!= 0 && s[i]!='0'){
                      if(p[k][p[k].length()-1]=='2' && s.length()>2 && s[i]!='0'){
                     ans+="and ";
                    
                }
                    
                ans+=tens[int(s[i]-'0')];
            
                ans+=ones[int(s[i+1]-'0')];
                     ans+=p[k];
                ans.pop_back();
                i+=2;
                k-=2;
              
                }else{
                    i++;
                    k--;
                }
                }else if(p[k][p[k].length()-1]!='1' ){
                    int l=int(s[i]-'0');
                    if(l!=0 && s[i]!='0'){
                        
                    ans+=ones[int(s[i]-'0')];
                
                    ans+=p[k];
                   }
                    
                    i++;
                    k--;
            }
            else if (p[k][0]=='1'){
                char ch=s[i];
                
                if(s.length()>2 & s[i]!='0'){
                 ans+="and ";}
                
                int l=int(ch-'0');
                ans+=ones[l];
                k--;
               
            }
        }
        ans.pop_back();
   return ans; }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends