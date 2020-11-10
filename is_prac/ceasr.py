import string
s1= string.ascii_lowercase
s2= string.ascii_uppercase
s3= ''
s4=string.whitespace
text=str(input("enter the string:"))
k=int(input("enter the key:"))



for l in text:
	if ( l in s1):
		a=text.index(l)
		loc=a+k %26
		#print(loc)
		s3+=s1[loc]
	
	elif(l in s2):
		a=text.index(l)
		loc=a+k %26
		s3+=s2[loc]
	
	elif (l in s4):
		a=s4.index(l)
		s3+=s4[a]
	


print("cipher text is;",s3)












