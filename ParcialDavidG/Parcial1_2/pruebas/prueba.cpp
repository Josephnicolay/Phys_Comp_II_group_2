#include <iostream>
#include <fstream>
#include <string>

using namespace std;

std::string getFileContents (std::ifstream&);            //Gets file contents

int main(int argc, char *argv[])
{
    char err=1+'0';
    char name[20]={'a','s','c','i','i','/','a','h','o','r','c','a','d','o',err,'.','d','a','t'};
    
    std::cout<<name<<std::endl;

    std::ifstream Reader (name);             //Open file

    std::string Art = getFileContents (Reader);       //Get file
    
    std::cout << Art << std::endl;               //Print it to the screen

    Reader.close ();                           //Close file

    return 0;
}

std::string getFileContents (std::ifstream& File)
{
    std::string Lines = "";        //All lines
    
    if (File)                      //Check if everything is good
    {
	while (File.good ())
	{
	    std::string TempLine;                  //Temp line
	    std::getline (File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character
	    
	    Lines += TempLine;                     //Add newline
	}
	return Lines;
    }
    else                           //Return error
    {
	return "ERROR File does not exist.";
    }
}
