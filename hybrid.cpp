/*
function solveKT():
    Initialize board[N][N] with -1
    Set board[0][0] = 0  // Start from top-left corner
    Define moveX[8] = {2, 1, -1, -2, -2, -1, 1, 2}
    Define moveY[8] = {1, 2, 2, 1, -1, -2, -2, -1}
    if solveKTUtil(0, 0, 1, 0, 0, board, moveX, moveY) is true:
        print board
    else:
        print "No solution"
function solveKTUtil(x, y, movei, startX, startY, board, moveX, moveY):
    if movei == N * N:
        if isNeighbor(x, y, startX, startY):
            return true
        else:
            return false
    for k = 0 to 7:
        next_x = x + moveX[k]
        next_y = y + moveY[k]
        if isSafe(next_x, next_y, board):
            board[next_x][next_y] = movei
            if solveKTUtil(next_x, next_y, movei + 1, startX, startY, board, moveX, moveY):
                return true
            board[next_x][next_y] = -1  // Backtrack

    return false
*/