from pytube import YouTube

try:

    #input the YouTube URL
    url = input("Enter the YouTube URL: ")

    yt = YouTube(url).streams.get_highest_resolution()

    print("Title:", YouTube(url).title)
    print("Views:", YouTube(url).views)
    yt.download("C:\\Users\Monster\Videos\Youtube Videos")

    print("Download complete.")

except Exception as e:
    print("An error occurred:", str(e))