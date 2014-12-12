class Solution {
public:
    int maxArea(vector<int> &height) {
        int length  = height.size();
        if (length == 0 || length == 1) {
            return 0;
        }

        int** records = new int*[length];
        for (int i = 0; i<length; i++) {
            records[i] = new int[length];
            for(int j = 0; j<length; j++) {
                records[i][j] = -1;
            }
        }
        int max_area = get_max_area(0, length-1, records, height);
        return max_area;
    }

    int get_max_area(int left, int right, int** records, vector<int>& height) {
        if (records[left][right] != -1) {
            return records[left][right];
        }
        if (left >= right) {
            return -1;
        }
        int current_area = (right - left) * min(height[right], height[left]);
        int champion_from_smaller_area =  max(get_max_area(left+1, right, records, height), get_max_area(left, right-1, records, height)); 
        int local_max = max(current_area, champion_from_smaller_area);
        records[left][right] = local_max;
        return local_max;
    }
};
