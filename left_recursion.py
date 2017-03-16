'''
This program will check if there is left recursion in grammer and will
remove if any.
file name is case sensitive in linux not in windows b/c windows is case insensitive
linux is not.
'''

for line in open("input.txt").readlines():
    right_terminal = line[0]
    #print right_terminal
    line = line.replace('\n','')
    string = ""
    for i in range(3,len(line)):
        string = string + line[i]
    string = string.split('|')
    #print string
    #print string
    alpha = []
    beta = []
    for items in string:
        if(items[0] == right_terminal):
            print 'Grammer is Left Recursive:\n'
            alpha.append(items[1:])
            #print alpha
        else:
            beta.append(items)
            #print 'beta is: ',beta
    if(len(alpha) != 0):
        print right_terminal,"->"
        for items in beta:
            print items,right_terminal,"'"
        print "\n",right_terminal,"'->"
        for items in alpha:
            print items,right_terminal,"'|"
        print "Epsilon"
    else:
        print line


'''
This program will recursively check left factoring and will remove
if found any.
'''








    
    
