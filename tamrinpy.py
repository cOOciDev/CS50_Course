import sys

m = 0

def main():
    while True:
        x = int(input("x : "))
        if x > 0 :
            break

    while True:
        y = int(input("y : "))
        if y > 0 :
            break



    while True:
        print("what do you want ?")
        answer = input(" + => A \n - => B \n * => C \n / => D \n =>>>>>>>>>>>>>>>>  ")
        if answer in ["A" , "B" , "C" , "D"]:
            if answer.upper == "A":
                sum_cal(x, y)
            elif answer.upper == "B":
                m = mines_cal(x, y)
            elif answer.upper == "C":
                zarb_cal(x, y)
            elif answer.upper == "D":
                device_cal(x, y)
            break





    print (m)
    print(x)
    print (y)


def sum_cal(x, y):
    z = x + y
    print(z)


def mines_cal(x, y):
    return x - y



def zarb_cal(x, y):
    z = x * y
    print(z)


def device_cal(x, y):
    z = x / y
    print(z)

main()