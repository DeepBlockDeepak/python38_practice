#!python3
import re
def string_reverser(input_string):

    #use a RegEx object to pattern match. 
    # The '[^] is 'negative character class' symbol
    #       ? is the optional group symbol
    #       + is the 'one or more' symbol
    passwordRegEx = re.compile(r"""(   

        ([/.-:;\\]+)?   #optional initial delimeter.
        ([^/.-:;\\]+)   #negative character class, i.e. anything that isn't a delimeter
        ([/.-:;\\]+)    #delimeter
        ([^/.-:;\\]+)   #negative character class, i.e. anything that isn't a delimeter
        ([/.-:;\\]+)    #delimeter
        ([^/.-:;\\]+)   #negative character class, i.e. anything that isn't a delimeter
        ([/.-:;\\]+)?   #optional final delimeter.

    )""", re.VERBOSE)   #Verbose used to package all the RegEx groups in this manner of syntax

    match_list = passwordRegEx.findall(input_string)    #match_list is every matched object in the input string

    match_list = list(match_list[0])        #turn the internal tuple into a list
    match_list[0] = ""                      #ignore the giant matched object in the first element by replacing with ""

    words = match_list[::2]                 #'words' contains the words from the RegEx
    words = words[::-1]                     #reverse the words, according to the coding problem

    delimeters = match_list[1::2]           #obtained the delimeters from the RegEx matching object

    #final_string = "".join([i + j for i,j in zip(words, delimeters) if i != "" or j != ""])
    
    i,j = 0,0
    final_string = ""
    
    while(i < len(words) and j < len(delimeters)):  #'words' and 'delimeters' will always be equally lengthed

        if words[i] == "":      #skip the blank string element by incrementing the index
            i += 1
        if delimeters[j] == "": #ditto
            j += 1
        
        if j >= len(match_list)//2: #if you're at the last index and overshoot, back it on up Terry put it in reverse
            j -=1
        if i >= len(match_list)//2: #ditto
            i -=1
        
        final_string += words[i] + delimeters[j]    #concatenate to a string
        i +=1
        j +=1

    return final_string

print(string_reverser('hello/world:here')) #here/world:hello
print(string_reverser('hello/world:here/')) #here/world:hello/
print(string_reverser('hello//world:here')) #here//world:hello
