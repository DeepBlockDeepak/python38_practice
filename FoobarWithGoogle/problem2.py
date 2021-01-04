def sweep(spaces, ratio):
    start = ratio[0]/ratio[1]
    for i in range(len(spaces)):
        if (spaces[i] - start) < 1:
            return [-1,-1]
        start = spaces[i] - start
    return ratio

def answer(pegs):
    spaces = [pegs[i+1] - pegs[i] for i in range(len(pegs)-1)]
    #print (spaces)
    f_space  = sum(spaces[::2])- sum(spaces[1::2])
    #print (f_space)
    if f_space <= 2:
        return [-1,-1]
    ratio= 0
    if len(spaces)%2 == 0:
        ratio= [2*f_space, 1]
    else:
        if f_space %3 == 0:
            ratio = [2*f_space/3, 1]
        else: 
            ratio= [2*f_space, 3]
    start = ratio[0]/ratio[1]
    for i in range(len(spaces)):
        if (spaces[i] - start) < 1:
            return [-1,-1]
        start = spaces[i] - start
    return ratio

print(answer([4,32,49]))
print (answer([4,30,50]))
print (answer([6,32,56]), "********")
print(answer([4,18,58,95]))
print("*****")