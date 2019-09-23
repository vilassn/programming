#include <bits/stdc++.h>
using namespace std;

struct am_sinkInfo_s {
   public:
    int regid;
    std::string filePath;
};

int main ()
{
    //string str = "aplay output.wav";
    string str = "aplay sample.wav";
    const char *command = str.c_str();
 
    cout << "Command: " << command << endl;
    int status = system(command);
    cout << "Status: " << status << endl;
    
    cout << "Size of Structure " << sizeof(am_sinkInfo_s) << endl;
    return 0;
}
