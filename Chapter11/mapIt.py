import sys, pyperclip, webbrowser

if len(sys.argv) <= 1:
    address = pyperclip.paste()
    #address should be a string who's items are separated by spaces
    address = "+".join(address.split(" "))
    url = "www.google.com/maps/place/" + address


else:

    address = "+".join(sys.argv[1:]) #for the Google Map URL

    url = "www.google.com/maps/place/" + address


webbrowser.open(url)
