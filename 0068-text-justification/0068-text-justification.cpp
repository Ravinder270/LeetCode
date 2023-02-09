class Solution {
public:
    vector<string> fullJustify(vector<string>& a, int l) {
   int i=0,n=a.size();
   vector<string> ansstring; 
   while(i<n)
   {
        vector<string> v;
        int count=0;
        // calculating the number of words in particular wigth
        while(i<n && count+a[i].size() <=l) 
        {
            count+=a[i].size()+1; //+1 for extra spacing in each word 
            v.push_back(a[i]); // push the words into a vector of string
            i++;
        }
        // check if only one word or end line i.e spacing is add only in the end
        if(i==n || v.size()==1) 
        {
            string ansinn="";
            // conversion of vector of string into single string
            for(int j=0;j<v.size();j++)
            {
                  ansinn+=v[j];
                  ansinn+=" ";
            }
            // if word size is of width size extra spacing is added in the end
            ansinn.pop_back();
            // to add extra spacing in the end
            while(ansinn.size()!=l) ansinn+=" ";
            
            ansstring.push_back(ansinn); 
        }
        else 
        {
            // find the total number of spaces in the line
            int space=l-count+v.size(),len=v.size(), avg=space/(len-1);
            vector<int> tmp;
            if(avg*(len-1)!=space) avg++;
            // convert the spaces into a vector prefering extra space in left side using some calculations
            for(int j=1;j<v.size();j++)
            {
                 if((avg-1)*(len-j)==space) avg--;
                 space-=avg;
                 tmp.push_back(avg);
            }
            
            //now convert the vector into final string
            string ans=v[0];
            int k=0;
            while(k+1<len)
            {
                int j=tmp[k];
                while(j--) ans+=" ";
                ans+=v[k+1];
                k++;
            }
            
            ansstring.push_back(ans);   
        }
   }
    return ansstring;
    
}

   
};