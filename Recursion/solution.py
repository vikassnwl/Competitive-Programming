arr = ["OR", ["<", "a", "b"], ["AND", ["==", "c", "d"], ["!=", "e", "f"]]]

def rec(arr):
    m = arr[0]
    if type(arr[1]) == list:
        l = rec(arr[1])
        if type(arr[1][1]) == list:
            l = '('+l+')'
    else:
        l = arr[1]
    if type(arr[2]) == list:
        r = rec(arr[2])
        if type(arr[2][1]) == list:
            r = '('+r+')'
    else:
        r = arr[2]

    return f'{l} {m} {r}'

print(rec(arr))
