t=0
p=[]
i=input
r=range
l=len
n=int
for x in r(n(i())):
 p.append(n(i()))
p.sort(reverse=True)
for y in r(l(p)%3):
 t += p.pop()
for j in r(n(l(p)/3)):
 o=j*3
 t+=p[o]+p[o+1]
print(t)
