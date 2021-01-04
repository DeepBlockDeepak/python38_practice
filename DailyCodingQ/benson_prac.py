
#given list 
spam = [13, 19, 13, 13]

#holds the spam items and their count within the spam list
bologna = {}

#count unique items
for item in spam:
	bologna.setdefault(item, 0)
	bologna[item] +=1

#find the item is a count of 1
for key in bologna.keys():
    if bologna[key] == 1:
        print(key)

