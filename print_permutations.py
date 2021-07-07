# print permutations using recursion

def printPermutations(s, ans):
    if len(s) == 0:
        print(ans)
        return

    for i in range(len(s)):
        ch = s[i]
        l_str = s[:i]
        r_str = s[i+1:]
        str_without_ch = l_str+r_str

        printPermutations(str_without_ch, ans+ch)

printPermutations('abc', '')

