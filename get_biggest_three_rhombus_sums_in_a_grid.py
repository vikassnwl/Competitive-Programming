class Solution:
    def getBiggestThree(self, grid: List[List[int]]) -> List[int]:
        s = set()

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                s.add(grid[i][j])
                k = 1
                while i-k >= 0 and i+k < len(grid) and j-k >= 0 and j+k < len(grid[0]):
                    total = 0
                    for l in range(1, k):
                        total += grid[i-k+l][j-l]+grid[i-k+l][j+l]
                        total += grid[i+k-l][j-l]+grid[i+k-l][j+l]
                    total += grid[i-k][j]+grid[i+k][j]+grid[i][j-k]+grid[i][j+k]

                    s.add(total)

                    k += 1

        return sorted(s)[:-4:-1]
