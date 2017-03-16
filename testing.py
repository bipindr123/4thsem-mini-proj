from Tkinter import *
import time

root = Tk()

root.geometry("500x400+0+0")
root.title("Word game")
counter =0

def buttoncalled(labl):
    def countit():
        global counter
        counter=counter+1
        labl.config(text=str(counter))
        labl.after(1000,countit)
    countit()
    def enterit():
        l3.pack()
    enterit()




w =  Frame(root, relief=SUNKEN, width = 750, height = 450 , bg="red")
w.pack(side=TOP, anchor=CENTER)
gg = Frame(root, relief=SUNKEN, width = 750, height = 450 , bg="blue")
gg.pack(anchor=W)
l1 = Label(w, text=" WORD GAME ", font=("Helvetica", 20)).grid(padx=5, pady=10)
l2 = Label(gg, text="hi")
b1 = Button(w,text=" Start Game ", width = 20, height = 3, command = lambda: buttoncalled(l2) ).grid(padx=5,pady=10)
l2.pack()
l3 = Label(gg,text="enter values")

root.mainloop()
