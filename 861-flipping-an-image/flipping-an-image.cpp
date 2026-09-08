class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i=0;i<image.size();i++){
            for(int j =0;j<image[i].size()/2;j++){
                swap(image[i][j],image[i][image[i].size()-j-1]);
            }
            for(int k = 0;k<image[i].size();k++){
                if(image[i][k] == 0) image[i][k] = 1 ;
                else if(image[i][k] == 1) image[i][k] = 0 ;
            }
        }
    return image ;}
};