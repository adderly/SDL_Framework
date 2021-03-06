


#ifndef LOG
#define LOG

#include<fstream>
#include<iostream>
#include<cstdlib>
#include<string>
#include<exception>
using namespace std;
class Log
{
    std::ofstream ofile;
    std::ifstream check;
    std::string defaultDir;
public:
    Log();
    Log(const string defaultLocation);
    void openf();
    void write_to_f(const string which,const string data);
    void closef();
    bool checkFolderExistance();
    ~Log();
};

static Log* logger;


static void saveLog(std::string data)
{
    logger = new Log();
    logger->write_to_f("Testing",data);
}
static void saveLog(std::string filename,std::string data)
{
    logger = new Log();
    logger->write_to_f(filename,data);
}


#endif


