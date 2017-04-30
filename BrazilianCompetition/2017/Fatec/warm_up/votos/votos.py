
cities = int(input())

for c in range(cities):
    ign = input()
    votos = list(map(int, input().split()))
    votos = sorted(votos, reverse=True)
    print(str(votos[0]) + ' ' + str(votos[1]) + ' ' + str(votos[2]))