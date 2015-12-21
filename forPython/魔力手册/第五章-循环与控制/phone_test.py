CN_mobile = [134,135,136,137,138,139,150,151,152,157,158,159,182,183,184,187,188,147,178,1705]
CN_union = [130,131,132,155,156,185,186,145,176,1709]
CN_telecom = [133,153,180,181,189,177,1700]

def head_test(number):
    if number in CN_mobile:
        return "China mobile"
    elif number in CN_telecom:
        return "China telecom"
    elif number in CN_union:
        return "China union"
    else:
        return False
def phone_test():
    while(1):
        number = input("Enter Your number :")
        if len(number) < 11:
            print("Invalid length, your number should be in 11 digits")
        elif not head_test(int(number[:3])):
            print("No such a operator")
        else:
            print("Operator : ", head_test(int(number[:3])))
            print("We're sending verification code via text to your phone: ", number)
            break

phone_test()