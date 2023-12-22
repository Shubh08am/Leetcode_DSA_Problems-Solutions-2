class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    sort(begin(points),end(points));
	int vertical_area=0;
	//depends only on x axis
	for(int i=0;i<points.size()-1;i++){
		int curr_width=points[i+1][0]-points[i][0];
		vertical_area=max(vertical_area,curr_width);
    }
	return vertical_area;
    }
};
