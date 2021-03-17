#!python3

def string_reverser2(input_string):

    d_list = []     #holds delim_string elements
    w_list = []     #holds word_string elements

    delim_string = ''   #container for consecutive delimeters, encountered in the input_string
    word_string = ''    #container for consecutively encountered non-delimeters, encountered in input_string

    set_of_delimeters = ["/", ";", ":", "//", "\\", "-"]    #list of possible delimeters

    for char in input_string:   
        """
        loop over each char of the input string. 
        Logic will be broken into consecutively encountered delimeters and consecutively encountered non-delimeters
        """

        if char in set_of_delimeters:   #delimeter encountered
            if delim_string == '':      #when the current char is the first delimeter of the current pass
                w_list.append(word_string)  #because the current char is the first delimeter of the new interval, 
                word_string = ''            #that means we finished processing all the 'word' chars of the previous interval.
                                            #Append the word_string to the word_list and reset word_string for the next batch. 
            
            delim_string = delim_string + char  #add the delimeter to the delim_string
            
        else:   #non-delimeter encountered
            if word_string == '':       #when the current char is the first non-delimeter of the current pass
                d_list.append(delim_string)
                delim_string = ''
            word_string = word_string + char
    
    #Catch any leftover delimeters or words... This will occur for whomever comprises the last interval of the input_string
    if delim_string != '':  #when a delimeter is the last interval
        d_list.append(delim_string)
    if word_string != '':
        w_list.append(word_string)

    w_list.reverse()    #necessary reversal of the words_list

    final = ''          #final string to contain the correctly ordered result of delimeters and words

    """
    Words_list and Delimter_list will often not be the same length. 
    It is necessary to loop over the range of the longest length, ignoring when an out-of-bounds loop is 
    encountered in the shorter list by appending a blank string element to the appropriate string
    """
    for i in range(max(len(w_list), len(d_list))):
        
        word_string = w_list[i] if i < len(w_list) else ''

        delim_string = d_list[i] if i < len(d_list) else ''

        final += delim_string + word_string        

    
    return final

test1 = 'hello/world:here'  #here/world:hello
test2 = 'hello/world:here//;;' #here/world:hello/
test3 = ':hello//world:here;' #:here//world:hello;;

for test in [test1, test2, test3]:
    print("\t/ " + "-"*len(test) + " \\")
    print("\t| {} |\n\t| {} |".format(test, string_reverser2(test)))
    print("\t\ " + "-"*len(test) + " /\n")



