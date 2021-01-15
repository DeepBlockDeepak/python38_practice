#!python3

def string_reverser2(input_string):

    d_list = []
    w_list = []

    delim_string = ''
    word_string = ''

    set_of_delimeters = ["/", ";", ":", "//", "\\", "-"]

    for char in input_string:

        if char in set_of_delimeters:
            if delim_string == '':
                w_list.append(word_string)
                word_string = ''
            delim_string = delim_string + char
            
        else:
            if word_string == '':
                d_list.append(delim_string)
                delim_string = ''
            word_string = word_string + char
            
    if delim_string != '':
        d_list.append(delim_string)
    if word_string != '':
        w_list.append(word_string)

    w_list = list(reversed(w_list))

    final = ''

    for i in range(max(len(w_list), len(d_list))):
        
        word_string = w_list[i] if i < len(w_list) else ''
        delim_string = d_list[i] if i < len(d_list) else ''
        final += delim_string + word_string
    
    return final

test1 = 'hello/world:here'  #here/world:hello
test2 = 'hello/world:here/' #here/world:hello/
test3 = 'hello//world:here' #here//world:hello

for test in [test1, test2, test3]:
    print("\t/ " + "-"*len(test) + " \\")
    print("\t| {} |\n\t| {} |".format(test, string_reverser2(test)))
    print("\t\ " + "-"*len(test) + " /\n")



