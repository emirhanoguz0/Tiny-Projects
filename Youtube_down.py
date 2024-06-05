from pytube import YouTube
import tkinter as tk
from tkinter import messagebox

def get_entry_data():
    url = entry1.get()
    YouTube(url).streams.get_highest_resolution().download("C:\\Users\Monster\Videos\Youtube Videos")

try:
    main_window = tk.Tk()
    main_window.geometry("400x200")
    main_window.title("YouTube Video Downloader")

    label1 = tk.Label(main_window, text="YouTube Url:")
    label1.pack()

    entry1 = tk.Entry(main_window, text="")
    entry1.pack()

    download_button = tk.Button(main_window, text="Download", command=get_entry_data)
    download_button.pack()


    #print("Title:", YouTube(url).title)
    #print("Views:", YouTube(url).views)

    #print("Download complete.")
    main_window.mainloop()
except Exception as e:
    print("An error occurred:", str(e))