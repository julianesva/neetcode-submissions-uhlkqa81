class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_s = defaultdict(set)
        col_s = defaultdict(set)
        sub_box_s = defaultdict(set)

        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c] == ".":
                    continue
                if(board[r][c] in row_s[r] or board[r][c] in col_s[c] or board[r][c] in sub_box_s[(r//3,c//3)]):
                    return False
                row_s[r].add(board[r][c])
                col_s[c].add(board[r][c])
                sub_box_s[(r//3,c//3)].add(board[r][c])

        return True
        