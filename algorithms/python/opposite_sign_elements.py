numbers = [1, -2, 3, 4, 5, -6]
countOppositeSignElements = 0

i = 0
j = 1
while i < len(numbers)-1:
    if (numbers[i] > 0 and numbers[j] < 0) or (numbers[i] < 0 and numbers[j] > 0):
        countOppositeSignElements += 1
    
    i += 1
    j += 1

print("Count of opposite sign elements:", countOppositeSignElements)
