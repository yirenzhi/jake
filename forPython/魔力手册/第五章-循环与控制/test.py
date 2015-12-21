login_list = ['***', '12345']
def account_login():
    password = input('Password:')
    password_correct = password == login_list[-1]
    password_reset = password == login_list[0]
    if password_correct:
        print('login success')
    elif password_reset:
        new_password = input('input you new password')
        login_list.append(new_password)
        print('you password is changed')
        print(login_list)
        account_login()
    else:
        print('login false')
        account_login()

#account_login()

for x in range(1, 5):
    print(("%d"+"+1="+"%d") % (x, x+1))

for x in range(1, 5):
    print(str(x)+"+1=", x+1)

print (list(map(lambda x:str(x)+"+1="+str(x+1),range(1, 5))))

for i in range(1,10):
    for j in range(1,10):
        print("{}*{}={}".format(j,i,i*j),end='\t')
    print(" ")