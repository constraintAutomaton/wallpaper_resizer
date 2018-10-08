#include <stdio.h>
#include <dirent.h> 
#include <string>
#include <string.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <X11/Xlib.h>
#include <cstdlib>
#include <iostream>


using namespace std;

void wallpaper_resizer(const char *wallpaper_folder)
{
	DIR *dirp;
	struct dirent *directory;
	string temp;
	string string_wallpaper_folder=wallpaper_folder;
	cv::Mat image;
	Display* d = XOpenDisplay(NULL);
	Screen*  s = DefaultScreenOfDisplay(d);
	string output_folder_string=string_wallpaper_folder+string("/wallpaper_resized");
	
	
	const int dir_err = system(strdup((string("mkdir -p ")+output_folder_string).c_str()));
	if (-1 == dir_err)
	{
		printf("Error creating directory!n");
		exit(1);
	}
	
	dirp = opendir(wallpaper_folder);
	if (dirp)
    {
        while ((directory = readdir(dirp)) != NULL)
        {
			if (directory->d_name!=string(".") && directory->d_name!=string("..") && directory->d_name!=string("wallpaper_resized") )
			{
				string sep="/";
				temp = sep+directory->d_name;
				temp = string_wallpaper_folder+temp;
				image = cv::imread(temp);
				try
				{
					cv::resize(image,image,cv::Size(s->width,s->height));
					cv::imwrite(strdup((output_folder_string+sep+directory->d_name).c_str()),image);
				}
				catch (...)
				{
					cout << directory->d_name << endl;
				}
			}
		}
        closedir(dirp);
	}
}

int main(int argc, char **argv)
{
	char *folder = new char[10000];
	cout<< "Enter the wallpaper path: "<< endl;
	cin >> folder ;
	wallpaper_resizer(folder);
	return 0;
}
