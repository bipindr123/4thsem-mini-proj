#python project AAT2 made by Ayush Goyal and Bipin D R
#Word game


from tkinter import *
import time
import itertools
import random

#some global variables

root = Tk()

root.geometry("1366x768+0+0")
root.title("Word game")
counter = 30

userlist = []
wordslist=[]
dictionarylist=[]
letterlist=[]
legitlist=[]

correctlist=[]

noofwordspossible=0
myscore=0

#function to generate random alphabets
def rangen():
    j = random.choice([5,6,7])
    for i in range(0,j):
        ch = random.choice('abcdefghijklmnopqrstuvwxyz')
        letterlist.append(ch)
    print(letterlist)
#removes duplicate elements
    for i in letterlist:
        if letterlist.count(i)>1:
            del letterlist[letterlist.index(i)]

    generatelist()
   


#function for genreating list of all possbile combinations from the given words
def generatelist():
    for i in range(3, len(letterlist) + 1):
        for word in itertools.permutations(letterlist, i):
            wordslist.append(''.join(word))
    readfile()

#function to read the dictionary from a file and put it into a list
def readfile():
    file1= open("small.txt","r",encoding="utf8")
    for i in file1.readlines():
        dictionarylist.append(i)
    file1.close()
    findletters()

#function to find and list all english words from the combinations
def findletters():
    loadit.config(text="loading")
    for i in wordslist:
        if dictionarylist.count(i+"\n") == 1:
            legitlist.append(i)
    print(legitlist)
    if len(legitlist)<5:
        legitlist.clear()
        dictionarylist.clear()
        letterlist.clear()
        wordslist.clear()
        rangen()
    else:
        loadit.config(text="done")
        
#funcition to check how many the user got correct and then assign a score
def score():
    for i in userlist:
        if legitlist.count(i) == 1:
            correctlist.append(i)
    print(correctlist)
    noofwordspossible = len(legitlist)
    myscore = len(correctlist)
    print(noofwordspossible)
    print(myscore)
    l6 = Label(hh, text="Words possible: " + str(legitlist)).grid(row=6, column=0, pady=10, padx=15)
    l5 = Label(gg, text="Number of words possible "+ str(noofwordspossible)).grid(row=7, column=0, pady=10, padx=15)
    l7 = Label(gg,text=" YOUR SCORE " + str(myscore),font=("Helvetica", 16)).grid(row=8, column=0, pady=10, padx=15)

#function that starts the game and provides the user with the list of random words and
def startgame(labl):
    def countit():
        global counter
        counter = counter-1
        ranwords = Label(gg,text="The random letters are :").grid(row=1,column=0)
        ranwords = Label(gg,text=letterlist,font=("Helvetica",20)).grid(row=2,column=0, pady=10, padx=15)

        labl.config(text=" Time remaining: " + str(counter), padx=20, pady=30)
        if counter!=0:
            labl.after(1000, countit)
            print(userlist)
        else:
            score()

    def enterit():
        l3.grid(row=2, column=0, pady=10, padx=15)
        e1.grid(row=3, column=0, pady=10, padx=15)
        b2.grid(row=3, column=1, pady=0, padx=0)
    countit()
    enterit()

def gettingtext():
    userlist.append(e1.get())
    l5 = Label(gg, text="entered words are " + str(userlist)).grid(row=5, column=0, pady=10, padx=15)
    e1.delete(0, END)

#doing gui using tkinter 

a = StringVar()
w = Frame(root, relief=SUNKEN)
w.pack(side=TOP, anchor=CENTER)
gg = Frame(root, relief=SUNKEN)
hh = Frame(root)
gg.pack(anchor=CENTER)
hh.pack()
loadit = Label(w)
rangen()
l1 = Label(w, text=" WORD GAME ", font=("Helvetica", 30)).grid(padx=5, pady=20)
l2 = Label(gg)
b1 = Button(w, text=" Start Game ", width=20, height=3, command=lambda: startgame(l2)).grid(padx=5, pady=10)
l2.grid(row=0, column=0)

l3 = Label(gg, text="enter the words ")
l4 = Label(gg)
e1 = Entry(gg, textvariable=a)
b2 = Button(gg, text="submit", command=lambda: gettingtext())

root.mainloop()
