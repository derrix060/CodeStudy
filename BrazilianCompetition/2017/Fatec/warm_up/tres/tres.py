

def next_tres(numb):
    if '3' in str(numb):
        return numb

    while(numb%10 == 3):
        numb += 1

    return numb

while(True):
    num_tres = []
    num_max = 0
    qtde = 0
    try:
        numb = int(input())
        
        if (numb > num_max):
            for i in range(numb):
                if '3' in str(i):
                    num_tres.append(i)
            qtde = len(num_tres)
            num_max = numb
        else:
            tres = next_tres(numb)
            qtde = num_tres.index(tres) - 1

        print(numb-qtde)

    except EOFError:
        break
