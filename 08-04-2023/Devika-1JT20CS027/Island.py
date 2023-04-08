list1 = [2,4,3]
list2 = [5,6,4]

result = [] 
for i in range(len(list1)):
    result.append(list1[i] + list2[i])

print(result)