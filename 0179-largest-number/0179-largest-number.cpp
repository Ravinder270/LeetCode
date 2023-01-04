class Solution {
public:
    static bool comp(string a,string b)
{
    return((a+b)>(b+a));
}
    string largestNumber(vector<int>& A) {
        vector<string> v;
    for(auto i:A)
    {
        v.push_back(to_string(i));
    }
    
    sort(v.begin(),v.end(),comp);
    string res="";
    
    for(int i=0;i<v.size();i++)
    {
        res+=v[i];
    }
    
    if(res[0]=='0' && res[res.size()-1]=='0')return "0";
    return res;
    }
};