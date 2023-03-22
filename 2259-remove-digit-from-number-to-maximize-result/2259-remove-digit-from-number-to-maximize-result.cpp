class Solution {
public:
    string removeDigit(string number, char digit) {
     bool flag=false;
    int n=number.size();
    
    for(int i=0;i<n-1;i++){
        
        if(number[i]==digit&&i<n-1&&number[i+1]>number[i]){
            flag=true;
            number.erase(number.begin()+i);
            return number;}    
    }
    
    if(flag==false)
    {
        for(int i=n-1;i>=0;i--){
            if(number[i]==digit){
              number.erase(number.begin()+i);
            return number;  
            }
        }
    }return number;
    }
};