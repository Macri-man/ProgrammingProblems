class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        
        while (head != nullptr && top <= bottom && left <= right) {
            for (int j = left; j <= right && head != nullptr; ++j) {
                matrix[top][j] = head->val;
                head = head->next;
            }
            top++;
            
            for (int i = top; i <= bottom && head != nullptr; ++i) {
                matrix[i][right] = head->val;
                head = head->next;
            }
            right--;
            
            for (int j = right; j >= left && head != nullptr; --j) {
                matrix[bottom][j] = head->val;
                head = head->next;
            }
            bottom--;
            
            for (int i = bottom; i >= top && head != nullptr; --i) {
                matrix[i][left] = head->val;
                head = head->next;
            }
            left++;
        }
        
        return matrix;
    }
};