class Solution {
public:
    vector<int> majorityElement(vector<int>& A) {
          int n=A.size();
    int m=n/3;
    int count1=0;
    int count2=0;
    int a=INT_MAX,b=INT_MAX;
    vector<int>ans;
        unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        if(a==A[i])
        count1++;
        else if(b==A[i])
        count2++;
        else if(count1==0)
        {
            a=A[i];
            count1++;
        }
        else if(count2==0)
        {
            b=A[i];
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    
    count1=0;
    count2=0;
    
    for(int i=0;i<n;i++)
    {
        if(a==A[i])
        count1++;
        
        else if(b==A[i])
        count2++;
        
       if(count1>m)
        {
            s.insert(a);
        }
      if (count2>m)
        {
           s.insert(b);
        }
    }
    for(auto i:s)
    {
        ans.push_back(i);
    }
    return ans;
    }
};