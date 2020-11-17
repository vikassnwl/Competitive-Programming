class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        result = []
        for i in range(rowIndex+1):
            result.insert(0, 1)
            for j in range(1, len(result)-1):
                result[j] += result[j+1]
        return result
