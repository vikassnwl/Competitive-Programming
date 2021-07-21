#B = ['X.....>', '..v..X.', '.>..X..', 'A......']
B = ['...Xv', 'AX..^', '.XX..']

n_rows = len(B)
n_cols = len(B[0])
ai = 0
aj = 0
#   X . . . . . >
#   . . V . . X .
#   . > . . X . .
#   A . . . . . .

#   X . . . . . X
#   . . X . . X .
#   . X X X X . .
#   A . X . . . .

#   . . . X X
#   A X . . X
#   . X X . .

# recursion
# choices -> assasin has four choices he can move top, left, bottom or right
def handle_horizontal_guards():
     global ai, aj

     for i in range(n_rows):
        l = 0
        for j in range(n_cols):
           
            # storing position of assasin
            if B[i][j] == 'A':
                ai = i
                aj = j

            # handling left facing guard
            if B[i][j] == '<':
                for j2 in range(l, j+1):
                    processed_input[i][j2] = 'X'

                l = j
            
            # handling obstacle
            elif B[i][j] == 'X':
                if B[i][l] == '>':

                    for j2 in range(l, j+1):
                        processed_input[i][j2] = 'X'
                    
                else:
                    processed_input[i][j] = 'X'
                l = j

            elif B[i][j] == '^':
                if B[i][l] == '>':

                    for j2 in range(l, j+1):
                        processed_input[i][j2] = 'X'
                    
                else:
                    processed_input[i][j] = 'X'
                l = j

            elif B[i][j] == 'v':
                if B[i][l] == '>':

                    for j2 in range(l, j+1):
                        processed_input[i][j2] = 'X'
                    
                else:
                    processed_input[i][j] = 'X'
                l = j
            # handling right facing guard
            elif B[i][j] == '>':
                if B[i][l] != '>':
                    l = j

        if B[i][l] == '>':
            for j2 in range(l, j+1):
                processed_input[i][j2] = 'X'
             
def handle_vertical_guards():
     for j in range(n_cols):
        l = 0
        for i in range(n_rows):

            # handling up facing guard
            if B[i][j] == '^':
                for i2 in range(l, i+1):
                    processed_input[i2][j] = 'X'

                l = i
            
            # handling obstacle
            elif B[i][j] == 'X':
                if B[l][j] == 'v':
                    for i2 in range(l, i+1):
                        processed_input[i2][j] = 'X'
                else:
                    processed_input[i][j] = 'X'
                l = i
                
            elif B[i][j] == '>':
                if B[l][j] == 'v':
                    for i2 in range(l, i+1):
                        processed_input[i2][j] = 'X'
                    l = i
                else:
                    processed_input[i][j] = 'X'

            elif B[i][j] == '<':
                if B[l][j] == 'v':
                    for i2 in range(l, i+1):
                        processed_input[i2][j] = 'X'
                    l = i
                else:
                    processed_input[i][j] = 'X'

            # handling down facing guard
            elif B[i][j] == 'v':
                if B[l][j] != 'v':
                    l = i

        if B[l][j] == 'v':
            for i2 in range(l, i+1):
                processed_input[i2][j] = 'X'


processed_input = [['.']*n_cols for _ in range(n_rows)]
def process_input(B, n_rows, n_cols):
    handle_horizontal_guards()
    handle_vertical_guards()
    return processed_input

process_input(B, n_rows, n_cols)
vis = [[0]*n_cols for _ in range(n_rows)]

def bfs(i, j):
    if i-1 >= 0 and processed_input[i-1][j] != 'X' and not vis[i-1][j]:
        vis[i-1][j] = 1
        bfs(i-1, j)
    if i+1 < n_rows and processed_input[i+1][j] != 'X' and not vis[i+1][j]:
        vis[i+1][j] = 1
        bfs(i+1, j)
    if j-1 >= 0 and processed_input[i][j-1] != 'X' and not vis[i][j-1]:
        vis[i][j-1] = 1
        bfs(i, j-1)
    if j+1 < n_cols and processed_input[i][j+1] != 'X' and not vis[i][j+1]:
        vis[i][j+1] = 1
        bfs(i, j+1)

bfs(ai, aj)
print(bool(vis[-1][-1]))

