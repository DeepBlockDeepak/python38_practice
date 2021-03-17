#!python3

def pivot_by_three_parts(pivot_val, lst_input):

    lesser_than_list = []
    greater_than_list = []
    equal_to_list = []
    final_list = []

    for item in lst_input:

        if item < pivot_val :
            lesser_than_list.append(item)
        

        elif item > pivot_val:
            greater_than_list.append(item)

        else:
            equal_to_list.append(item)
    
    final_list = lesser_than_list + equal_to_list + greater_than_list
    print (final_list)

val = 10
initial_lst = [9,12,3,5,14,10,10]
pivot_by_three_parts(val, initial_lst)
