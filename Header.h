#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;


class Display
{
protected:
	string path;
	ifstream fin;


public:
	Display() :path("MyFile.txt") {};
	Display(string path) :path(path) {} ;

	virtual void openFile()
	{
		fin.open(path, ios::app);
	}
	virtual void closeFile() { fin.close(); }
	virtual void print()
	{
		char ch;
		while (fin.get(ch))
		{
			cout << ch;
		}
	}
};
class Display_ASCII :  virtual public Display
{
	
public:
	Display_ASCII():Display(path) {};
	Display_ASCII(string path) :Display(path) {};
	 void  print()
	{
		char ch;
		while (fin.get(ch))
		{
			cout << (int)ch<<endl;
		}
	}
};


class Display_Binary : virtual public Display_ASCII
{
public:
	Display_Binary(string path) :Display(path) {};
	virtual void openFile()
	{
		fin.open(path, ios::in | ios::binary);
	}
	void  print()
	{
		Display::print();
	}
};