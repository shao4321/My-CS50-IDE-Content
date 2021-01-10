import re
from datetime import datetime
from datetime import date

"""__repr__ doesnt support looping through list and printing out its available list contents"""
class Artist():

    def __init__(self, name):
        self.name = name
        self.albums = []

    def __repr__(self):
        albums_list = re.sub('[\[\]\,]', '', str(self.albums))
        albums_list_name = str(self.albums[0].album_name)
        return f"{self.name} has the following albums:\n" + albums_list_name

    def add_album(self, album):
        if not isinstance(album, Album):
            raise Exception("Invalid album...")
        self.albums.append(album)


class Album():

    def __init__(self, name, code):
        self.album_name = name
        self.album_code = code
        self.songs = []
        self.playlists = []

    def __repr__(self):
        string_song_list = re.sub('[\[\]\,]', '', str(self.songs))
        playlist_list = re.sub('[\[\]\,]', '', str(self.playlists))
        return f"Name of Album: {self.album_name}\n" + '\n' + "Songs:" + string_song_list + '\n' + "Playlists:\n" + playlist_list

    def add_song(self, song):
        if not isinstance(song, Song):
            raise Exception("Invalid song...")
        self.songs.append(song)


    def add_playlist(self, playlist):
        if not isinstance(playlist, Playlist):
            raise Exception("Invalid playlist...")
        if playlist not in self.playlists:
            self.playlists.append(playlist)
        for song in playlist.songs:
            if song not in self.songs:
                self.songs.append(song)


class Playlist(Album):

    def __init__(self, name):
        self.playlist_name = name
        self.songs = []

    def __repr__(self):
        string_song_list = re.sub('[\[\]\,]', '', str(self.songs))
        return f"Name of Playlist: {self.playlist_name}\n" + string_song_list


class Song():

    def __init__(self, title, code, date):
        self.song_title = title
        self.song_code = code
        self.song_date_composed = date

    def __repr__(self):
        return f"\nSong Title: {self.song_title}\nSong Code: {self.song_code}\nDate Composed: {self.song_date_composed}\n"


song_1 = Song('Blue Sky', '001', date(2020, 10, 10))
song_2 = Song('Blue Ocean', '002', date(2020, 11, 11))
song_3 = Song('Red Sea', '003', date(2020, 9, 9))
song_4 = Song('Red Waters', '004', date(2020, 8, 8))
song_5 = Song('Red Cage', '005', date(2020, 7, 7))

playlist_1 = Playlist('Blues')
playlist_1.add_song(song_1)
playlist_1.add_song(song_2)

playlist_2 = Playlist('Reds')
playlist_2.add_song(song_4)
playlist_2.add_song(song_5)

album_1 = Album('Colors', '901')
album_1.add_song(song_3)
album_1.add_playlist(playlist_1)

artist_1 = Artist('Jack')
artist_1.add_album(album_1)

playlist_1.add_song(song_5)
album_1.add_playlist(playlist_1)
# print(playlist_1.songs[0].song_title)
# print(song_1)
print(artist_1)
