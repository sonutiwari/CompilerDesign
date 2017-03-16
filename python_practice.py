##try:
##    num_hours = int(raw_input("Enter Hours"))
##except:
##    print "Enter valid number!"
##    assert False
##try:
##    rate = int(raw_input("Enter Rate"))
##except:
##    print "Enter valid number"
##    assert False
##if(num_hours > 40):
##    pay = 40 * rate + (num_hours - 40) * rate * 1.5
##else:
##    pay = rate * num_hours
##print pay

##response = 'y'
##while(response == 'y' or response ==  'Y'):
##    try:
##        score = raw_input('Enter score:\t')
##        score = float(score)
##        if(score >= 0.9):
##            print 'A'
##        elif(score >= 0.8):
##            print 'B'
##        elif(score >= 0.7):
##            print 'C'
##        elif(score >= 0.6):
##            print 'D'
##        else:
##            print 'F'
##    except:
##        print "Bad score"
##    response = raw_input("Do you eant to continue?y/n:\t")
            
##response = 'not'
##sum = 0
##count = 0
##while(response != 'done'):
##    num = ' '
##    try:
##        num = raw_input('Enter a number')
##        num = int(num)
##        sum += num
##        count += 1
##    except:
##        if(num =='done'):
##            break
##        print 'Invalid Input'
##print sum,'\t',count,'\t',float(sum)/count

##response = 'not'
##number_list = []
##while(response != 'done'):
##    try:
##        num = raw_input('Enter a number')
##        num = int(num)
##        number_list.append(num)        
##    except:
##        if(num =='done'):
##            break
##        print 'Invalid Input'
##print 'Maximum:\t',max(number_list),'\tMinimum:\t',min(number_list)

##str = 'X-DSPAM-Confidence: 0.8475'
##num = str.find('0')
##print float(str[num:])

##filename = raw_input('Enter a file name')
##fileContent = open(filename,'r').read()
##print fileContent.upper()



