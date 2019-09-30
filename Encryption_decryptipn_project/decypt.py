
file1=open("result12.txt","r+")
file2=open("decrypt.txt","w")
text=file1.readlines()
a=[]

for i in text:
    a=i.split("-")

def decrypt(result):
    end_string = ""
    for numbers in result:
        if numbers=="":
            end_string+=""
        else:
            n=int(numbers)
            n=n + 20
            n= chr(n)
            end_string = end_string + n
    file2.write(end_string)

g=int(input("press 1 to start decryption"))
if g==1:
   decrypt(a) 
file2.close()