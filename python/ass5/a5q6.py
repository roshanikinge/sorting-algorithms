source_file=input("enter the file name.txt\n")
destination_file=input("enter your destination file.txt\n")
with open(sfname,'r')as src,open(dfname,'w')as dst:
    content=src.read()
    dst.write(content)
    print("file copied successfully")