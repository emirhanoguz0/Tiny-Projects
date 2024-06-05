from pytube import YouTube
import tkinter as tk
from tkinter import messagebox

def get_entry_data():
    url = entry1.get()
    YouTube(url).streams.get_highest_resolution().download("C:\\Users\Monster\Videos\Youtube Videos")
    down_message()

def down_message():
    messagebox.showinfo("Download Complete", f"Title: {YouTube(url).title} Views: {YouTube(url).views}")

try:
    main_window = tk.Tk()
    main_window.geometry("350x200")
    main_window.title("YouTube Video Downloader")

    label1 = tk.Label(main_window, text="YouTube Url:", font= "Helvetica 13")
    label1.pack()

    entry1 = tk.Entry(main_window)
    entry1.pack()

    download_button = tk.Button(main_window, text="Download", command=get_entry_data)
    download_button.pack()

    exit_button = tk.Button(main_window, text="Exit", command=main_window.quit)
    exit_button.pack()


    #print()
    #print()

    main_window.mainloop()
except Exception as e:
    print("An error occurred:", str(e))