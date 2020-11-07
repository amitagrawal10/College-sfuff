import string
text=str(input("enter the string:"))
k=int(input("enter the key:"))
s=""
alphabets=string.ascii_lowercase


for l in text:
    a=text.index(l)
    loc=a+k %26
    s+=alphabets[a+k]

print(s)
