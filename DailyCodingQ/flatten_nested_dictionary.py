"""
Write a function to flatten a nested dictionary. Namespace
the keys with a period.

Ex:

given:
{
    'key': 3,
    'foo': {
        'a': 5,
        'bar': {
            'baz': 8
        }
    }
}

it should become:
{
    'key': 3,
    'foo.a': 5,
    'foo.bar.baz': 8
}
"""
import pprint

#This is the most realistic algorith, for my current skillset- 3/15/2021
#key insight is to utilize the second parameter; .update() is also new, and crticial for this loop
def flatten_dict(input_dict, prefix_key = ''):

    if type(input_dict) != dict:
        return "Input must be a dictionary."

    new_dict = {}
    for current_key, value in input_dict.items():
        new_key = prefix_key + current_key
        if type(value) == dict:
            new_dict.update(flatten_dict(value, new_key + '.'))                
        
        else:
            new_dict[new_key] = value

    return new_dict

def flatten(dd, separator='_', prefix=''):
    return { prefix + separator + k if prefix else k : v
             for kk, vv in dd.items()
             for k, v in flatten(vv, separator, kk).items()
             } if isinstance(dd, dict) else { prefix : dd }

test = {
    'key': 3,
    'foo': {
        'a': 5,
        'bar': {
            'baz': 8
        }
    }
}


print("{")
for index, item in enumerate(flatten_dict(test)):
    if index == len(flatten_dict(test))- 1:
        print(item, "\n}")
    else:
        print(item, ",")   