#include "UI.h"
#include <Windows.h>
#include "CSVPlayList.h"
#include "RepositoryExceptions.h"
#include <string>
#include <assert.h>

using namespace std;

void testUndoAdd()
{
	Repository repo("Songs.txt");
	FilePlaylist* p = new CSVPlaylist{};
	Controller ctrl(repo, p, SongValidator{});
	ctrl.addSongToRepository(string("Asadf"), string("gdb"), 1.0, 35.0, string("www.c"));

	ctrl.addSongToRepository(string("BCSsadf"), string("dsgfdgdb"), 1.0, 35.0, string("www.c"));

	ctrl.removeSongFromRepository(string("BCSsadf"), string("dsgfdgdb"));

	ctrl.Undo();

	ctrl.Undo();


	ctrl.Undo();

	assert(repo.getSongs().size() == 10);




}
