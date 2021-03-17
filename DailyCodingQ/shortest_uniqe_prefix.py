"""
Given a list of words, return the shortest unique prefix
of each word. 
Ex: 
given: ['dog', 'cat', 'apple', 'apricot', 'fish']
return ['d', 'c', 'app', 'apr', 'f']
"""

#BUG Elements aren't able to compare to previously encountered elements. 

holder = []
list_of_words = ["dog", "cat", "apple", "apricot", "fish"]

for word_index, word in enumerate(list_of_words):

    #j is for looking ahead of the current word being assessed
    j = word_index + 1
    #char_crawler is for list slicing the current word, and the compared words down the line
    char_crawler = 1

    for next_word in list_of_words[j:]:

        #case where current list slice is good, so far, so skip to the next next_word
        if word[:char_crawler] not in next_word[:char_crawler]:
            continue
        
        #need to stay on current next_word, and compare further slices of it
        else: 
            char_crawler += 1
            #keep on comparing the list slices of the matched words until a difference appears
            for i in range(char_crawler, min(len(word), len(next_word))):
                if word[:i] not in next_word[:i]: #and word[:i] not in holder
                    #retain the slice of char_crawler, because word[:i] is now a unique prefix
                    char_crawler = i
                    break
    
    #the word slice should be valid
    holder.append(word[:char_crawler]) if word[:char_crawler] not in holder else None

print(holder)