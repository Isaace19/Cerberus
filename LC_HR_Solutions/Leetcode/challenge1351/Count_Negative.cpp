class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
		int total = 0;
		int n = grid.size();
		for(int i = 0; i<n; i++){
			int l1 = upper_bound(grid[i].rbegin(), grid[i], grid[i].rend(), -1) - grid[i].rbegin();
			total+=l1;
		}		
		return total;
	}+
};


