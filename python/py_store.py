#diffrentiation 
n=input("Enter the string: ")
a=[]
b=[]
for i in n:
    if(i.isdigit()):
        b.append(i)
    else:
        if(len(b)):
            s=""
            for i in b:
                s+=i
            s=int(s)
            a.append(s)
            b.clear()
s=""
for i in b:
    s+=i
s=int(s)
a.append(s)
c=len(a)
if(c%2!=0):
    c=c-1
c=int(c/2)
for z in range(0,c):
    i=int(2*z)
    j=int(2*z+1)
    a[i]=a[i]*a[j]
    a[j]=a[j]-1
for z in range(0,c):
    i=int(2*z)
    j=int(2*z+1)
    if(c==1):
        print(a[i],"*x^",a[j],sep="")
    else:
        if(z==c-1):
            print(a[i],"*x^",a[j],sep="")
            break
        print(a[i],"*x^",a[j],"+",sep="",end='')


#integration

n=input("Enter the string: ")
a=[]
b=[]
for i in n:
    if(i.isdigit()):
        b.append(i)
    else:
        if(len(b)):
            s=""
            for i in b:
                s+=i
            s=int(s)
            a.append(s)
            b.clear()
s=""
for i in b:
    s+=i
s=int(s)
a.append(s)
r=0
if(len(a)%2!=0):
    r=1
    a.append(0)
c=int(len(a)/2)
for z in range(0,c):
    i=2*z
    j=2*z+1
    a[i]=a[i]/(a[j]+1)
    a[j]=a[j]+1
for z in range(0,int(len(a)/2)):
    i=2*z
    j=2*z+1
    if(int(len(a)/2)==1):
        print("{0:.3f}".format(a[i]),"*x^",a[j])
        break
    else:
        if(z==(int(len(a)/2)-1)):
            print("{0:.3f}".format(a[i]),"*x^",a[j],sep='')
            break
        else:
            print("{0:.3f}".format(a[i]),"*x^",a[j]," + ",end='',sep='')

#random program

n=int(input("Enter the number: "))
m=0
for i in range(1,n):
    if((n>=pow(2,i))and(m<=pow(2,i))):
        m=i
s=""
for i in range(0,m):
    s+="2"
s+="1"
print(s)

#gcd of numbers in a array

print("Enter the elements and Enter 'stop' to stop")
a=[]
while(0<1):
    n=input("Enter: ")
    if(n=="stop"):
        break
    elif(n.isdigit()):
        a.append(int(n))
    else:
        print("invalid")
        break
def gcd(a):
    g=1
    for i in range(1,min(a)+1):
        p=1
        for j in a:
            if(j%i!=0):
                p=0
                break
        if(p==1):
            g=i
    return g
print(gcd(a))
