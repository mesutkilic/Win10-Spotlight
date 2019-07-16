#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED

/*
 *
 *Mesut KILIÇ
 *All Rights Reserved.
 *
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <fstream>
#include <vector>
#include <string>

#include <sys/types.h>
#include <dirent.h>

#include <shlwapi.h>
#include <windows.h>

using namespace std;

class dimens{
public:
  dimens():x_(0),y_(0){};

  const int& x(){return x_;}
  void x(int x_new){x_=x_new;}

  const int& y(){return y_;}
  void y(int y_new){y_=y_new;}

private:
  int x_;
  int y_;
};


bool GetImageSize(std::string& path,std::string& filename, int *x,int *y);
bool GetImageSize(std::string& path,std::string& filename, dimens& dim);

void read_directory(const std::string& name, vector<std::string>& v);
void read_directory2(std::string& name, vector<std::string>& v);

#endif // WALL_H_INCLUDED
