#python project AAT2 made by Ayush Goyal and Bipin D R
#Under Guidance of Mrs. Bhanupriya Ma'am
#Word game

from tkinter import *
import time
import itertools

root = Tk()

root.geometry("500x400+0+0")
root.title("Word game")
counter = 10

userlist = []
wordslist=[]
dictionarylist=[]

letterlist=['a','g','o','d','h']

legitlist=[]

correctlist=[]

highestscore=0
myscore=0

def generatelist():
    for i in range(2, len(letterlist) + 1):
        for word in itertools.permutations(letterlist, i):
            wordslist.append(''.join(word))

def readfile():
    file1= open("small.txt","r",encoding="utf8")
    for i in file1.readlines():
        dictionarylist.append(i)
    file1.close()

def findletters():
    for i in wordslist:
        if dictionarylist.count(i+"\n") == 1:
            legitlist.append(i)
    print(legitlist)

def score():
    for i in userlist:
        if legitlist.count(i) == 1:
            correctlist.append(i)
    print(correctlist)
    highestscore = len(legitlist)
    myscore = len(correctlist)
    print(highestscore)
    print(myscore)    


def buttoncalled(labl):
    def countit():
        global counter
        counter = counter-1
        labl.config(text=" Time remaining: " + str(counter), padx=10, pady=10)
        if counter!=0:
            labl.after(1000, countit)
            print(userlist)
        else:
            score()

    def enterit():
        l3.grid(row=2, column=0, pady=10, padx=15)
        e1.grid(row=3, column=0, pady=10, padx=15)
        b2.grid(row=3, column=1, pady=10, padx=10)
    countit()
    enterit()

def gettingtext():
    userlist.append(e1.get())
    l5 = Label(gg, text="entered words are " + str(userlist)).grid(row=5, column=0)

generatelist()
a = StringVar()

w = Frame(root, relief=SUNKEN, width=750, height=450,bg="red")
w.pack(side=TOP, anchor=CENTER)
gg = Frame(root, relief=SUNKEN, width=750, height=450)
gg.pack(anchor=W)
l1 = Label(w, text=" WORD GAME ", font=("Helvetica", 20)).grid(padx=5, pady=20)
l2 = Label(gg,text="what")
b1 = Button(w, text=" Start Game ", width=20, height=3, command=lambda: buttoncalled(l2)).grid(padx=5, pady=10)
l2.grid(row=0, column=0)
l3 = Label(gg, text="enter the words ")
l4 = Label(gg)
e1 = Entry(gg, textvariable=a)
b2 = Button(gg, text="submit", command=lambda: gettingtext())
readfile()
findletters()


root.mainloop()
