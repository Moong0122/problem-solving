croatia = ['c=','c-','dz=','d-','lj','nj','s=','z=']

a= input()
for i in range(len(croatia)):
	a = a.replace(croatia[i],'*')

print(len(a))