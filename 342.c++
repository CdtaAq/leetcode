struct RowInfo {
    int index;
    int count;
};
bool compare(const RowInfo &a, const RowInfo &b) {
    if (a.count != b.count) {
        return a.count < b.count;
    }
    return a.index < b.index;
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int matSize = mat.size();
        int matColSize = mat[0].size();
        
        vector<RowInfo> rows(matSize);
        for (int i = 0; i < matSize; i++) {
            rows[i].index = i;
            rows[i].count = 0;
            for (int j = 0; j < matColSize; j++) {
                rows[i].count += mat[i][j];
            }
        }

        sort(rows.begin(), rows.end(), compare);

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = rows[i].index;
        }

        return result;
    }
};
