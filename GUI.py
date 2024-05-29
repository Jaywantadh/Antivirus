from tkinter import *
from tkinter import filedialog
import subprocess
from PIL import Image, ImageTk
import threading


global process_rtm

root = Tk()

root.title("ANTIVIRUS")
root.geometry("1440x900")
root.resizable(0,0)
root.configure(bg="#262626")

file_path = ""


def open_file():
    global file_path
    file_path = filedialog.askopenfilename()
    if file_path:
        file_label.config(text="Chosen path: " + file_path)
    else:
        file_label.config(text="No path selected")

def open_directory():
    global file_path
    file_path = filedialog.askdirectory()
    if file_path:
        file_label.config(text="Chosen path: " + file_path)
    else:
        file_label.config(text="No path selected")
