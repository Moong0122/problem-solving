arr = list()
total = 0
n,c = input().split() 
c = int(c)
a = input().split() 
arr = list(map(int,a)) 

while(True):
	arr.sort()
	answer = arr[0] + arr[1]
	arr[0] = answer
	arr[1] = answer
	c -= 1
	if(c == 0):
		break

for i in arr:
	total += i

print(total)

# 파이썬 sort함수를 써서 구했는데 시간초과가 났다