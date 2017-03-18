file1 = open("ren.txt","r")
file2 = open("hhh.txt","w")

for i in file1.readlines():
    file2.write(i)


file1.close()
file2.close()
