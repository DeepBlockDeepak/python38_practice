def alpha_encode(input_num):

    print(str(input_num) + " == ", end = "")
    
    #hold the resulting string
    alpha_column_id = ""
    
    #break down input_num if it is greater than 26
    while(input_num//26):
        #fill the string with as many "A"s as can fit wholly into input_num
        alpha_column_id += "A" * (input_num//26)
        #break input_num into the remainder value
        input_num %= 26

    #convert remainder value into a char
    alpha_column_id += chr(ord("A") + (input_num % 27) -1)

    print(alpha_column_id)


def num_to_letters(input_num):
  
  print(str(input_num) + " = ", end = "")
  input_num -= 1
  alpha_column_id = ""
  alphabet = [chr(ord('A') + i) for i in range(26)]

  
  while(input_num >=0):
    alpha_column_id = alphabet[input_num % 26] + alpha_column_id
    input_num = (input_num//26) -1

  print(alpha_column_id)



alpha_encode(1)
alpha_encode(27)
#Multiples of Z don't work :(
alpha_encode(26)

print("---------------------")
num_to_letters(53)

