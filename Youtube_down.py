from pytube import YouTube
import tkinter as tk
from tkinter import messagebox

def get_entry_data():
    url = entry1.get()
    down_message(url)
    YouTube(url).streams.get_highest_resolution().download("C:\\Users\Monster\Videos\Youtube Videos")
    entry1.delete(0,tk.END)



def down_message(url):
    messagebox.showinfo("Download Complete", f"Title: {YouTube(url).title} \nViews: {YouTube(url).views}")

try:
    main_window = tk.Tk()
    main_window.geometry("350x175+600+200") #+y+x
    main_window.resizable(width=False, height=False)
    main_window.title("YouTube Video Downloader")

    label1 = tk.Label(main_window, text="YouTube Url:", font= "Helvetica 11")
    label1.grid(row=0, column=0)

    entry1 = tk.Entry(main_window,width=30)
    entry1.grid(row=0, column=1)

    download_button = tk.Button(main_window, text="Download", command=get_entry_data, width=8,height=2)
    download_button.grid(row=1, column=1)

    exit_button = tk.Button(main_window, text="Exit", command=main_window.quit)
    exit_button.grid(row=2, column=1)

    main_window.mainloop()
except Exception as e:
    print("An error occurred:", str(e))