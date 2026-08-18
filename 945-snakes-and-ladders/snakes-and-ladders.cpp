class Solution {
public:
    // 1. Number se Board ke (Row, Column) nikalne ka function
    pair<int, int> getCoord(int num, int n) {
        int r = (num - 1) / n;
        int c = (num - 1) % n;
        if (r % 2 == 1) {
            c = n - 1 - c;
        }
        return {n - 1 - r, c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        // 2D Visited array size n x n, sabhi initially false
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        queue<int> q;
        q.push(1); // Position 1 se start kiya
        visited[n - 1][0] = true; // Position 1 hamesha bottom-left par hoti hai
        
        int steps = 0;
        
        while (!q.empty()) {
            int N = q.size();
            
            while (N--) {
                int x = q.front();
                q.pop(); // Front element ko remove karna zaroori hai
                
                // Agar target par pahunch gaye
                if (x == n * n) {
                    return steps;
                }
                
                // Dice ke 6 options explore karein
                for (int k = 1; k <= 6; k++) {
                    int next_pos = x + k;
                    if (next_pos > n * n) break; // Board se bahaar nahi ja sakte
                    
                    pair<int, int> coord = getCoord(next_pos, n);
                    int r = coord.first;
                    int c = coord.second;
                    
                    if (visited[r][c] == true) continue;
                    visited[r][c] = true; // Mark as visited
                    
                    // Agar snake ya ladder hai toh uske end point par jao, nahi toh wahi raho
                    if (board[r][c] == -1) {
                        q.push(next_pos);
                    } else {
                        q.push(board[r][c]);
                    }
                }
            }
            steps++; // Ek dice roll poora hua
        }
        
        return -1; // Agar end tak nahi pahunch sakte
    }
};
