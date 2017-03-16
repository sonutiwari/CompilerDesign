fileReader = open("main.cpp","r").read()
fileReader = fileReader.split()
keyworArray = {
    'auto','break','case','char','const','enum',
    'continue','default','do','double','else',
    'enum','extern','float','for','goto','if',
    'int','long','register','return','short','signed',
    'sizeof','static','struct','switch','typedef','union',
    'unsigned','void','volatile','while'    
    }
for word in fileReader:
    
print fileReader
