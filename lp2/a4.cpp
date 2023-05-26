bool isSafe(int i, int j, vector<string>& board) {
        int n = board.size();
        for(int _i = 0; _i < n; _i++) {
            if(_i != i and board[_i][j] == 'Q') return false;
        }
        for(int _j = 0; _j < n; _j++) {
            if(_j != j and board[i][_j] == 'Q') return false;
        }

        int r = i, c = j;
        while(r >=  0 and c >= 0) {
            if(board[r][c] == 'Q') return false;
            r--, c--;
        }

        r = i, c = j;
        while(r < n and c >= 0) {
            if(board[r][c] == 'Q') return false;
            r++, c--;
        }

        return true;
    }
    
    void solve(int j, int placed, vector<string>& board, vector<vector<string>>& ans) {
        if(placed == board.size()) {
            ans.push_back(board);
            return;
        }

        if(j >= board.size()) return;

        for(int i = 0; i < board.size(); i++) {
            if(isSafe(i, j, board)) {
                board[i][j] = 'Q';
                solve(j + 1, placed + 1, board, ans);
                board[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string (n, '.'));

        solve(0, 0, board, ans);
        return ans;
    }
