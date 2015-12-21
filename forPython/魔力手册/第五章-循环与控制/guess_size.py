'''
<<<<< GAME STARTS! >>>>>
Big or Small:Big
<<<<< ROLE THE DICE!>>>>>
The points are [2, 6, 3] You Lose!
'''
import random
def gameplay():
    # print("<<<<< GAME STARTS! >>>>>")
    # print("Small is 1,Big is 2.")
    print("<<<<< 游戏开始 >>>>>")
    print("小输入 1,大输入 2.")
    # result_list=[1, 2]
    # if gus in result_list: 可以用这句话来判断是否正确
    while(1):
        gus = int(input("Big or Small:  "))
        if ((gus != 1)and(gus != 2)):
            print("input error only expected 1 or 2")
            continue
        l1 = []
        for i in range(3):
            l1.append(random.randrange(1, 7))
        result = ""
        if sum(l1) <= 10:
            if gus==1:
                result = "The points are "+str(l1)+" You Win!"
            else:
                result="The points are "+str(l1)+" You Lose!"
        else:
            if gus==2:
                result="The points are "+str(l1)+" You Win!"
            else:
                result="The points are "+str(l1)+" You Lose!"
        # print("<<<<< ROLE THE DICE!>>>>>")
        print("<<<<< 揭晓结果 >>>>>")
        print(result)

#gameplay()

#答案
def roll_dice(numbers=3,points=None):
    print('<<<<< ROLE THE DICE!>>>>>')
    if points is None:
        points = []
    while numbers>0:
        point=random.randrange(1, 7)
        points.append(point)
        numbers=numbers-1
    return points

def roll_result(total):
    isSmall = 3 <= total <= 10
    isBig = 11 <= total <=18
    if isBig:
        return 'Big'
    elif isSmall:
        return 'Small'

def start_game(money=1000):
    print("<<<<< GAME STARTS! >>>>>")
    print("you have", money, "now")
    choices = ['Big', 'Small']
    while(money > 0):
        print("0表示大，1表示小!")
        your_choice = choices[int(input('Big or Small: '))]
        your_bet = int(input('How much you wanna bet ? - '))
        if your_choice in choices:
            points = roll_dice()
            total = sum(points)
            you_win = your_choice == roll_result(total)
            if you_win:
                money += your_bet
                print('The points are',points,'You win !')
                print('You gained ', your_bet, "you have ", money, "now")
            else:
                money -= your_bet
                print('The points are',points,'You lose !')
                print('You lost ', your_bet, "you have ", money, "now")
        else:
            print("Invalid words")
    print("GAME OVER")

start_game()