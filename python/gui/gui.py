import tkinter as tk
from PIL import Image, ImageTk

r = tk.Tk()

r.title("Shafayet")
r.geometry("500x500")

r.maxsize(500, 500)
r.minsize(500, 500)

im = Image.open("/mnt/f/my_programs/phitron/python/gui/1.jpg")


photo = ImageTk.PhotoImage(im)

label = tk.Label(image=photo)
label.pack()


r.mainloop()
