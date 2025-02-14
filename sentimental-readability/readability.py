import math

alpha = "abcdefghijklmnopqrstuvwxyzABCDEFJHIJKLMNOPQRSTUVWXYZ"


def main():
    text = input("please write your text here ...")

    calculate(text)


def calculate(text):
    letter_Num = 0
    word_Num = 1
    sentence_Num = 0
    grade = 0

    for i in text:
        if i == ' ':
            word_Num += 1

        if i == '.' or i == '!' or i == '?':
            sentence_Num += 1

        if i in alpha:
            letter_Num += 1

    av_L = letter_Num * 100.0 / word_Num
    av_S = sentence_Num * 100.0 / word_Num
    grade = round(0.0588 * av_L - 0.296 * av_S - 15.8)

    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


main()
