//I had to make a shell using some given functions. Upon further thought I should have utilized a stack. That would have
//made things fairly trivial compared to the way I did this before.
/*
 * Please solve the following puzzle.
 * Limit to the C++11 standard library.
 * Be succinct yet readable. You should not exceed more than 200 lines.
 * Consider adding comments and asserts to help the understanding.
 * If you are using a mac, code can be compiled with clang++ -std=c++11 source-file
 * If you are using a linux, you can compile running g++ -std=c++11 source-file
 */

#include <assert.h>
#include <string>

/*
 * include other files here
 */
#include <deque>
#include <iostream>

using namespace std;
/*
 * change the code here.
 */


struct Shell {
    string EndLocation = "";
    deque <string> PathWay;//A long list of strings that represent our pathway
    string AnalyzePath(string FullPath){
        cout<<"Called A Cd: " << FullPath << endl;
        while((FullPath[0] == '/') && (FullPath.length() > 1)){//Account for cd "/"
            cout << "ASKING TO CD ROOT\n";
            //Go Back To The Root
            PathWay.clear();
            return AnalyzePath(FullPath.substr(1, FullPath.length()));
        }
        if(FullPath == "/"){
            return FullPath;
        }
        else{//We have a serious pathway
            string BuildingDir = "";
            for(int i = 0;  i<FullPath.length(); i++){
                char CurrentChar = FullPath[i];
                BuildingDir += CurrentChar;//Add our current Character to our Directory
                if(BuildingDir == ".."){//If we are currently looking at a back by one
                    cout << "Deleting A Layer: " << PathWay.back() << endl;
                    BuildingDir = "";
                    PathWay.pop_back();
                }
                else if(BuildingDir == "./"){
                    cout << "Nothin\n";
                    BuildingDir = "";
                }
                else if(CurrentChar == '/' || i==FullPath.length()-1){
                    cout<<"Adding Layer: " << BuildingDir << endl;
                    PathWay.push_back(BuildingDir);
                    BuildingDir = "";
                }

            }
            //ACCUMULATE OUR VECTOR
            string AccumulatedVector = "/";
            for(auto const& s : PathWay){
                AccumulatedVector += s;
            }
            cout << "CURRENTLY: " << AccumulatedVector << endl;
            return AccumulatedVector;
        }

    }
	//Go to a path in our directory
	Shell & cd(const char * const path) {
	    string CMD = path;
	    EndLocation = AnalyzePath(CMD);
	    while(EndLocation[EndLocation.length()-1] == '/'){
            EndLocation.pop_back();
        }
        return *this;//This is the object IE Shell
    }
	string path(void) const {
	    if(EndLocation =="")
            return "/";
	    cout<<"EndLocation is " << EndLocation <<endl;
        return EndLocation;
    }
};

/*
 * test cases
 */
int main(int, char * *) {
	Shell shell;
	assert(shell.path() == "/");

	shell.cd("/");
	assert(shell.path() == "/");
    cout << "TEST 1 COMPLETE\n\n";

	shell.cd("usr/..");
	assert(shell.path() == "/");
    cout << "TEST 2 COMPLETE\n\n";

	shell.cd("usr").cd("local");
	shell.cd("../local").cd("./");
	assert(shell.path() == "/usr/local");
    cout << "TEST 3 COMPLETE\n\n";
	shell.cd("..");
	assert(shell.path() == "/usr");
    cout << "TEST 4 COMPLETE\n\n";
	shell.cd("//lib///");
	assert(shell.path() == "/lib");

	return 0;
}
