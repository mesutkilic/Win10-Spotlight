//============================================================================
// Name        : wall_v1.cpp
// Author      : Mesut KILIÇ
// Version     : v1.1
// Copyright   : All Rights Reserved
// Description : Win10 Spotlight Wallpaper Copy Program
//============================================================================
#include "wall.h"

int screen_size=1920;
std::string path;
std::string asset_path;
std::string temp_path;
std::string script_path;
std::string bat_file_path;

vector<std::string> files;

ofstream batch;

int main(int argc, char *argv[]) {

	string cur_path=argv[0];
	string folder_name="";
	path = cur_path.substr(0, cur_path.find_last_of("\\/"));
	//cout<<cur_path<<endl;

	if (argc == 2){ screen_size = atoi(argv[1]); } //set screen size 1920
	else if (argc == 3){ screen_size = atoi(argv[1]); path = argv[2]; } //set custom path C:\user
	path= path + "\\" + folder_name ;//+"\\";

	mkdir(path.c_str()); //create folder

	asset_path= path +"Assets";
	temp_path= path +"Temp";
	script_path= path +"Scripts";

	//cout<<path<<endl;
	//cout<<asset_path<<endl;
	//cout<<temp_path<<endl;
	//cout<<script_path<<endl;

	mkdir(asset_path.c_str()); //create Assets folder
	mkdir(temp_path.c_str()); //create Temp folder
	mkdir(script_path.c_str()); //create Scripts folder

	bat_file_path =script_path + "\\vcopy.bat";
	//cout<<bat_file_path<<endl;
	batch.open(bat_file_path, ios::out);

	batch <<"cd "+ temp_path + "\n";
	batch <<"del *.* /F /Q\n";
	batch <<"cd %localappdata%\\Packages\\Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy\\LocalState\\Assets\n";
	batch <<"copy *.* " + temp_path + "\n";
	batch <<"cd " + temp_path + "\n";
	batch <<"ren *.* *.jpg";
	batch.close();

	cout <<"Starting vcopy.bat File...\n";
	system(bat_file_path.c_str());
	cout <<"vcopy.bat file finished\n";

  read_directory(temp_path,files);
  files.erase(files.begin(),files.begin()+2);

  for(int i=0; i<(int)files.size(); ++i){ cout<<files.at(i)<<endl;  }
  cout<<files.size()<<" files found: \n";

  dimens dfiles[files.size()+1];

  cout<<"Getting Dimensions...";

  for(int i=0; i<(int)files.size(); ++i){
  	GetImageSize(temp_path,files.at(i), dfiles[i]);
  }
  cout<<"\tdone.\n";

  cout<<"Removing unnecessary Files\n";
  for(int i=0; i<(int)files.size(); ++i){
  	if(dfiles[i].x() != screen_size){
  		//delete file
  		cout<<"removing : "<<files.at(i).c_str();
  	  if( remove( files.at(i).c_str() ) != 0 )
  	    perror( "\tError" );
  	  else
  	    puts( "\tSuccess" );
  	}
  }

  files.clear();

  /*
  read_directory(temp_path,files);
  files.erase(files.begin(),files.begin()+2);

  for(int i=0; i<(int)files.size(); ++i){
    cout<<files.at(i)<<endl;
  }
  cout<<files.size()<<" new files found: \n";
  */

	bat_file_path =script_path + "\\vpaste.bat";
	//cout<<bat_file_path<<endl;
	batch.open(bat_file_path, ios::out);

	batch <<"cd " + temp_path + "\n";
	batch <<"copy *.* " + asset_path + "\n";
	batch <<"del *.* /F /Q\n";
	batch.close();

	cout <<"Starting vpaste.bat File...\n";
	system(bat_file_path.c_str());
	cout <<"vpaste.bat file finished\n";

  system("PAUSE");

  return 0;

}
