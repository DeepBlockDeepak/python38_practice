import os, sys

#"some_file_path" is the user's file path leading to a .txt file basename
#"number_of_chars" is the number of characters the user wants printed
def char_extractor(some_file_path, number_of_chars):

    try:
        #Two File Objects were used because stuff got weird
        with open(some_file_path, 'r') as userFile:            
            file_string = userFile.read()           #read the text into a string variable
            print(file_string[:number_of_chars])    #print the first 'num_of_chars' characters

        with open(some_file_path, 'w') as userFile: #creates new file at the same user-inputted filepath
            userFile.write(file_string[number_of_chars:])   #writes in the second half of the original text file

    except FileNotFoundError:#error-checking idea for weird user input
        sys.exit("That filepath doesn't exist bubba.")


results = [
    char_extractor('C:\\dingus\\stinkus.txt', 7) for x in range(3)
]
#stinkus.txt has "Hello World" in it





