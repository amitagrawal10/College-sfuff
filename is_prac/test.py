import string
text=str(input("enter the string:"))
k=int(input("enter the key:"))
s=""
alphabets=string.ascii_lowercase
print(alphabets)



for l in text:
    a=text.index(l)
    print(a)
    loc=a+k %26
    print(loc)
    s+=alphabets[a+k]

print(s)