def fix_machine(debris, product):
    i = 0
    length = len(product)
    while i < length:
        if debris.find(product[i]) == -1:
            return "Give me something that's not useless next time."
        else:
            i = i + 1
    return product
print(fix_machine('1234','12'))
print ("Test case 1: ", fix_machine('UdaciousUdacitee', 'Udacity') == "Give me something that's not useless next time.")
print ("Test case 2: ", fix_machine('buy me dat Unicorn', 'Udacity') == 'Udacity')
print ("Test case 3: ", fix_machine('AEIOU and sometimes y... c', 'Udacity') == 'Udacity')
print ("Test case 4: ", fix_machine('wsx0-=mttrhix', 't-shirt') == 't-shirt')