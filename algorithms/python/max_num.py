a = input("a= ")
b = input("b= ")
c = input("c= ")

max = a

if b > a:
    max = b

if c > max:
    max = c

print('Max number is %s ' %max)
