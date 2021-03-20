import random
"""
num_of_rolls is the maximum number of dice rolls allowed. Small values should result in no combos, whereas_
large values will guarantee that a combo occurs
"""
def dice_roll_simulation(num_of_rolls):
    # of sides of a die, and a random roll generator
    dice_val = 6
    roll_of_the_dice = lambda x : random.randint(1,x)


    #roll the die twice, and store results in a list, to initialize the first combination
    dice_storage = [roll_of_the_dice(dice_val), roll_of_the_dice(dice_val)]
    #toggles serve as sentinels for terminating the upcoming FOR loop.
    five_six_toggle = False
    five_five_toggle = False

    #counts store the number of rolls it took to hit a combo
    #TODO possible iffy manoeuvre here. In the event that a combo is not rolled, within a trial, _
            #_ give it a "heavy weight". This should make larger the number of rolls required to hit the target
    five_six_count, five_five_count = num_of_rolls, num_of_rolls

    #roll_counter represents the number of times the die was cast
        #initially set to 2 because it was rolled twice already
    roll_counter = 2
    for i in range(num_of_rolls - 2):

        #check the current combination
        if dice_storage == [5,6] and not five_six_toggle:

            five_six_toggle = True
            five_six_count = roll_counter

        if dice_storage == [5,5] and not five_five_toggle:

            five_five_toggle = True
            five_five_count = roll_counter

        #no need to keep rolling once both targets are found
        if five_five_toggle and five_six_toggle:
            break
        

        #keep on rolling
        roll_counter += 1
        dice_storage[0], dice_storage[1] = dice_storage[1], roll_of_the_dice(dice_val)

    return (five_five_count, five_six_count)



"""
num_of_trials is the amount of simulations for a dice rolling session
num_of_rolls is the ceiling on allowed dice rolls for a given session
"""
def trials_of_dice_rolls(num_of_trials, num_of_rolls):
    
    #           [5->5 roll, 5->6 roll]
    total_die_counter = [0,0]
    for i in range(num_of_trials):
        five_five_count, five_six_count = dice_roll_simulation(num_of_rolls)
        total_die_counter[0] += five_five_count
        total_die_counter[1] += five_six_count
    
    print(
        "\nIn {} trials, on average it took:\n\t{} rolls to hit a consecutive 5,5"
        "\n\t{} rolls to hit a consecutive 5,6".format(
            num_of_trials,
            round(total_die_counter[0]/num_of_trials),
            round(total_die_counter[1]/num_of_trials)
        )
    )


trials_of_dice_rolls(100000, 100)


#following was in place before the return of the dice-rolling function
#served to track how long, if at all, it took for each combo to be rolled
"""
    if (five_five_toggle and five_six_toggle):
        print(
            "Consecutive 5's were found in {} rolls\n"
            "5,6 was found in {} rolls".format(
                five_five_count, five_six_count
            )
        )
    
    if(five_five_toggle and not five_six_toggle):
        print(
            "Consecutive 5's were found in {} rolls".format(five_five_count)
        )
    
    if(five_six_toggle and not five_five_toggle):
        print(
            "5,6 was found in {} rolls".format(five_six_count)
        )
    if(not(five_five_toggle or five_six_toggle)):
        print("Neither roll was found in {} rolls".format(num_of_rolls))"""

