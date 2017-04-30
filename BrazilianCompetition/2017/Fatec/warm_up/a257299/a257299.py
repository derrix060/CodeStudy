

def isA257299(numb_s):
    digits = [int('0')]*10
    actual_numb = numb_s

    while (actual_numb != '0'):
        first_num = int(actual_numb[0])
        num = int(actual_numb[1:])
        actual_numb = str(first_num * num)

        if (digits[first_num] == 1):
            return False
        digits[first_num]+=1
    
    return True


times = int(input())

for t in range(times):
    numb_s = input()
    
    if isA257299(numb_s):
        print('T')
    else:
        print('F')