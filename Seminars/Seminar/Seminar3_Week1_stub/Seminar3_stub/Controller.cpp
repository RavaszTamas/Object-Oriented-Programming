#include "Controller.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

void Controller::addSongToRepository(const std::string& artist, const std::string& title, double minutes, double seconds, const std::string& source)
{
	Song s{ artist, title, Duration{minutes, seconds}, source };
	this->repo.addSong(s);
}

void Controller::addSongToPlaylist(const Song& song)
{


	// TODO
}

vector<Song> Controller::addAllSongsByArtistToPlaylist(const std::string& artist)
{
	// get all the songs from the repository
	std::vector<Song> songs = this->repo.getSongs();
	this->playlist.resize(songs.size());
	auto it = copy_if(songs.begin(), songs.end(), this->playlist.begin(), [artist](Song& song) {return song.getArtist() == artist; });

	this->playlist.resize(std::distance(playlist.begin(), it));
	return playlist;
	// use STL algorithms and lambdas
}