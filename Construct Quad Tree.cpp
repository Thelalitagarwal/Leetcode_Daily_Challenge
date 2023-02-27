class Solution {
private:
    Node *dfs(vector<vector<int>> &grid, int rows, int cols, int i, int j) {
        Node *node = new Node();

        int isLeaf = 1;
        int val = grid[i][j];

        for (int k = i; k < rows + i && isLeaf; ++k) {
            for (int l = j; l < cols + j && isLeaf; ++l) {
                if (grid[k][l] != val) isLeaf = 0;
            }
        }

        node->isLeaf = isLeaf;
        node->val = val;

        if (!isLeaf) {
            node->topLeft = dfs(grid, rows / 2, cols / 2, i, j);
            node->topRight = dfs(grid, rows / 2, cols / 2, i, j + cols / 2);
            node->bottomLeft = dfs(grid, rows / 2, cols / 2, i + rows / 2, j);
            node->bottomRight = dfs(grid, rows / 2, cols / 2, i + rows / 2, j + cols / 2);
        }

        return node;
    }

public:
    Node *construct(vector<vector<int>> &grid) {
        int n = grid.size();
        return dfs(grid, n, n, 0, 0);
    }
};