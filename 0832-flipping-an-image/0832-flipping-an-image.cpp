class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
     
       
        for(int row=0;row<image.size();row++)
        {
                int left=0;
                int right=image[0].size()-1;
                while(left<=right)
                {
                     swap(image[row][left],image[row][right]);
                    left++;
                    right--;
                }
               
                
            
        }
        
        for(int row=0;row<image.size();row++)
        {
            for(int col=0;col<image[0].size();col++)
            {
                if(image[row][col]==1)
                {
                    image[row][col]=0;
                }
                else
                {
                     image[row][col]=1;
                }
                // cout<<image[row][col]<<" ";
            }
            // cout<<endl;
        }
        return image;
            
    }
};