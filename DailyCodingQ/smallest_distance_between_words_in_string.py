"""
Find an efficient algorithm to find the smallest distance 
(measured in number of words) between any two given words in a string.

Ex: given words "hello" and "world", and a text of
'dog cat hello cat dog dog hello cat world', return 1 because
there's only one word, 'cat', in between the two words.
"""


def words_between(tester):
	#split the inputted string into a string array
	#use the space," ", as a delimeter
	tester = tester.split(' ')

	sweeper = 0 #marks the start of a new interval
	counter_dict = {}   #sorta hash_table thing for storing the distances

    #loop through the string array, reseting 'sweeper' everytime "hello" is found_
    #when "world" is found, store the distance between the words into the dictionary.
	for word in tester:
		sweeper += 1
		if word == "hello":
			sweeper = 0
		if word == "world":
            #setdefault feels arbitrary. The second parameter doesn't matter at all. Only the key matters
			counter_dict.setdefault(sweeper -1, 1)

    #return the smallest traversed distance, stored in keys
	return (min(counter_dict.keys()))



def find_between(string_thing):
	string_thing = string_thing.split(' ')
	sweeper = 0
    #this is the largest case where "hello" is the first word, and "world" the last
	smallest_distance = len(string_thing) - 2
    #loop across the indecex,item pairs using enumerate()
	for index, word in enumerate(string_thing):
		if word.lower() == "hello":
            #store the index of this 'hello'
			sweeper = index
		if word.lower() == "world":
            #distance between 'hello' and 'world'
			new_distance = index - sweeper - 1

			if new_distance < smallest_distance:
				smallest_distance = new_distance

	return smallest_distance

tester = "dog cat hello cat dog dog hello cat world"
print(words_between(tester))
print(find_between(tester))
