
file1=open("result1.txt","r+")
file2=open("result12.txt","w")
text=file1.readlines()

a=[]
for i in text:
    for j in i:
        a.append(j)

def encrypt(t):
    result = []
    for j in t:
        result.append(j)
        
    for letter in result:
        n = ord(letter) - 20
        file2.write(str(n))
        file2.write("-")






g=int(input("press 1 to start encyption"))
if g==1:
   encrypt(a) 

file2.close()
