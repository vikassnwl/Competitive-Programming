board_dim, num_obstacles = map(int, input().split())
queen_x, queen_y = map(int, input().split())
obstacles_pos = set()
for _ in range(num_obstacles):
    obstacles_pos.add(tuple(map(int, input().split())))


result = 0
    
# top positions
row = queen_x+1
while row <= board_dim:
    if (row, queen_y) in obstacles_pos:
        break
    result += 1
    row += 1

# bottom positions
row = queen_x-1
while row >= 1:
    if (row, queen_y) in obstacles_pos:
        break
    result += 1    
    row -= 1

# left positions
col = queen_y-1
while col >= 1:
    if (queen_x, col) in obstacles_pos:
        break
    result += 1    
    col -= 1

# right positions
col = queen_y+1
while col <= board_dim:
    if (queen_x, col) in obstacles_pos:
        break
    result += 1    
    col += 1

# top-left
row = queen_x+1
col = queen_y-1

while row <= board_dim and col >= 1:
    if (row, col) in obstacles_pos:
        break
    result += 1    
    row += 1
    col -= 1

# top-right
row = queen_x+1
col = queen_y+1

while row <= board_dim and col <= board_dim:
    if (row, col) in obstacles_pos:
        break
    result += 1    
    row += 1
    col += 1

# bottom-left
row = queen_x-1
col = queen_y-1

while row >= 1 and col >= 1:
    if (row, col) in obstacles_pos:
        break
    result += 1    
    row -= 1
    col -= 1

# bottom-right
row = queen_x-1
col = queen_y+1

while row >= 1 and col <= board_dim:
    if (row, col) in obstacles_pos:
        break
    result += 1    
    row -= 1
    col += 1

print(result)
