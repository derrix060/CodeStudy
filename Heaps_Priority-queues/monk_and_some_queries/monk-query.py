import queue

t = int(input())
maxPq = queue.PriorityQueue()
minPq = queue.PriorityQueue()
aux = {}

for i in range(t):
    enter = list(map(int, input().split()))

    if enter[0] == 1:
        # insert element
        num = enter[1]
        maxPq.put(-num)
        minPq.put(num)

        if num not in aux:
            aux[num] = 1
        else:
            aux[num] += 1
    
    elif enter[0] == 2:
        # remove element
        num = enter[1]

        if num not in aux:
            print('-1')
        elif aux[num] == 1:
            aux.pop(num)
        else:
            aux[num] -= 1

    elif enter[0] == 3:
        # max element
        tmp = maxPq.get()
        while(-tmp not in aux and not maxPq.empty()):
            tmp = maxPq.get()
        
        if maxPq.empty():
            print('-1')
        else:
            print(-tmp)
            maxPq.put(tmp)

    
    else:
        # min element
        tmp = minPq.get()
        while(tmp not in aux and not minPq.empty()):
            tmp = minPq.get()
        
        if minPq.empty():
            print('-1')
        else:
            print(tmp)
            minPq.put(tmp)
            

        
