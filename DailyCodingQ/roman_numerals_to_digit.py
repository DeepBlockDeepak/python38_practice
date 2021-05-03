spqr_dict = {'M':1000, 'D': 500, 'C': 100, 'L': 50, 'X':10, 'V':5, 'I':1}

#14
numeral = 'XIV'
'''
#"MMCMXIV"

total = 0
tmp = 0
numeral = numeral[::-1]

for cur_letter_ind in range(len(numeral)):
    #print(numeral[cur_letter_ind], cur_letter_ind)
    cur_letter_ind += tmp

    if cur_letter_ind == len(numeral) -1 :
        if spqr_dict[numeral[cur_letter_ind]] < spqr_dict[numeral[cur_letter_ind -1]]:
            total -= spqr_dict[numeral][cur_letter_ind]
        
        break
    

    total += spqr_dict[numeral[cur_letter_ind]]

    if spqr_dict[numeral[cur_letter_ind]] > spqr_dict[numeral[cur_letter_ind + 1]]:
        
        total -= spqr_dict[numeral[cur_letter_ind + 1]]
        tmp += 1

    

print(numeral + " = " + str(total))  
'''

def from_roman(num):
    total = 0
    for i,c in enumerate(num):
        if (i+1) == len(num) or spqr_dict[c] >= spqr_dict[num[i+1]]:
            total += spqr_dict[c]
        
        else:
            total -= spqr_dict[c]

    print(total)

from_roman(numeral)