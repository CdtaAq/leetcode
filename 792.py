class Solution(object):
    def minFallingPathSum(self, matrix):
        M = len(matrix)
        N = len(matrix[0])
    
        prevRow = matrix[0][:]  # Initialize with the first row
    
        for r in range(1, M):
            currRow = [0] * N
            for c in range(N):
                curr = matrix[r][c]
                top = curr + prevRow[c]
                topL = curr + prevRow[c - 1] if c > 0 else float('inf')
                topR = curr + prevRow[c + 1] if c < N - 1 else float('inf')
                currRow[c] = min(top, topL, topR)
        
            prevRow = currRow  # Update the previous row with the current row
    
        return min(prevRow)
