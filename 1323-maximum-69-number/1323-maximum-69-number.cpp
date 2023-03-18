class Solution {
public:
    int maximum69Number (int num) {
     string helper=to_string(num);
     
     for(int i=0;i<helper.length();i++)
     {
         if(helper[i]=='6')
         {
             helper[i]='9';
             break;
         }
     }
        
      return stoi(helper);  
    }
};