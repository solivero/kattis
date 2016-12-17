simonsays = "Simon says"
simonsays_len = len(simonsays)
for _ in range(int(input())):
    line = input()
    if line.startswith(simonsays):
        print(line[simonsays_len:])
