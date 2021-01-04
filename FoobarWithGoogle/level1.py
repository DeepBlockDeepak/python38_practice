#solution() should search within range(0,s) for which s is in range(1,1000001) for largest value
# n for which n^2 < s. Then, appending to a list, find the remaining squares until the sum of the squares matches 'area'
def solution(area):
    possible_sqrts = []
    panel = []
    '''
    loop through values that go up to and include the sqrt(area), because sqrt(area) is 
    the biggest number that is allowable in the solution list
    '''
    for i in range(1,int(area**0.5) +1):
        possible_sqrts.append(i**2)
    '''
    at this point, possible_sqrts is now a list of 
    squared values. Working backwards, through this list,
    panel must .append() values up until the sums match area
    '''
    
    counter = len(possible_sqrts)-1 
    while counter >=0:
        if area - possible_sqrts[counter]>= 0: #if the total panel area still has room after subtracting away the largest sqrt panel
            panel.append(possible_sqrts[counter]) #add this sqrt panel size to the solution list
            area -= possible_sqrts[counter] #decrement area by the added panel size
        counter -= 1 #next
    '''
    now that area has shrunk, it may not be == 0.
    Because it is a minimum, we should have only the "1"
    squares leftover. 
    '''
    for i in range(area):
        panel.append(1)

    return panel

test_val = 100006
print (test_val, "****", solution(test_val), "****", sum(solution(test_val)))
