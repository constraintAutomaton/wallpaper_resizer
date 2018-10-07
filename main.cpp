#include <stdio.h>
#include <dirent.h> 
#include <vector>
#include <string>
#include <string.h>

using namespace std;

std::vector<char>  wallpaper_resizer(const char *wallpaper_folder)
{
	std::vector<char> wallpapers;
	DIR *dirp;
	struct dirent *directory;
	string temp;
	string string_wallpaper_folder=wallpaper_folder;
	
	dirp = opendir(wallpaper_folder);
	if (dirp)
    {
        while ((directory = readdir(dirp)) != NULL)
        {
			if (bool operator||(directory->d_name!=string("."), directory->d_name!=string("..")))
			{
				string sep="/";
				temp = sep+directory->d_name;
				temp = string_wallpaper_folder+temp;
				//printf("%s\n",temp.c_str());
				printf("%s\n",directory->d_name);
			}
				
        }

        closedir(dirp);
    }
	return wallpapers;
}
int main(int argc, char **argv)
{
	std::vector<char>  test;
	test = wallpaper_resizer("/home/bryan/Pictures/Wallpaper");
	// for (auto const& c : test)
	//	std::cout << c << ' ';
	return 0;
}
