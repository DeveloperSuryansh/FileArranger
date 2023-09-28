// FilesArranger.cpp : Defines the entry point for the application.
//

#include "FilesArranger.h"

using namespace std;

string get_ext(string strs)
{
	string str;
	for (int i = strs.size(); i > 0; i--)
	{
		if (strs[i] == '.')
		{
			str.append(strs, i+1, strs.size() - i);
			return str;
		}
	}
	return "others";
}

enum EXTS get_type(string ext)
{
	if (ext == "exe" || ext == "sys" || ext == "cmd" || ext == "bat" || ext == "dll")
	{
		return EXEC;
	}

	else if (ext == "pdf" || ext == "doc" || ext == "xls" || ext == "ppt")
	{
		return DOCS;
	}

	else if (ext == "mp3" || ext == "wav" || ext == "ogg" || ext == "m4a")
	{
		return AUDIO;
	}

	else if (ext == "mp4" || ext == "avi" || ext == "mpeg")
	{
		return VIDEO;
	}

	else if (ext == "zip" || ext == "xz" || ext == "7z" || ext == "rar")
	{
		return ARCH;
	}

	else if (ext == "jpeg" || ext == "bmp" || ext == "jpg" || ext == "png")
	{
		return IMG;
	}
	
	else if (ext == "txt" || ext == "md" || ext == "json" || ext == "csv")
	{
		return TEXT;
	}
	else
	{
		return OTHERS;
	}
}

int main()
{
	vector<string> str;
	string path;
	cout << "Enter Path to Arrange the files in it: ";
	cin >> path;

	std::filesystem::create_directory(path + "\\Audio");
	std::filesystem::create_directory(path + "\\Video");
	std::filesystem::create_directory(path + "\\Docs");
	std::filesystem::create_directory(path + "\\Executables");
	std::filesystem::create_directory(path + "\\Others");
	std::filesystem::create_directory(path + "\\Archives");
	std::filesystem::create_directory(path + "\\Images");
	std::filesystem::create_directory(path + "\\TextFiles");

	for (auto& p : std::filesystem::directory_iterator(path))
	{
		string filename;
		if (!p.is_directory())
		{
			filename = p.path().filename().string();
			cout << filename<<endl;
			
			switch (get_type(get_ext(filename)))
			{
			case EXEC:
				std::filesystem::copy(p.path(), path + "\\Executables\\" + filename);
				std::filesystem::remove(p.path());
				break;

			case DOCS:
				std::filesystem::copy(p.path(), path + "\\Docs\\" + filename);
				std::filesystem::remove(p.path());
				break;

			case AUDIO:
				std::filesystem::copy(p.path(), path + "\\Audio\\" + filename);
				std::filesystem::remove(p.path());
				break;

			case VIDEO:
				std::filesystem::copy(p.path(), path + "\\Video\\" + filename);
				std::filesystem::remove(p.path());
				break;

			case ARCH:
				std::filesystem::copy(p.path(), path + "\\Archives\\" + filename);
				std::filesystem::remove(p.path());
				break;

			case IMG:
				std::filesystem::copy(p.path(), path + "\\Images\\" + filename);
				std::filesystem::remove(p.path());
				break;
			
			case TEXT:
				std::filesystem::copy(p.path(), path + "\\TextFiles\\" + filename);
				std::filesystem::remove(p.path());
				break;
			
			case OTHERS:
				std::filesystem::copy(p.path(), path + "\\Others\\" + filename);

				break;

			default:
				break;
			}

		}

	}
	cout << "All Files are Moved to Their Correct Folders..."<<endl;
	return 0;
}
