

#include <iostream>
#include <string>
#include<fstream>
#include<string.h>


using namespace std;



int main(int argc, char* argv[])
{
    fstream f1;
    string str, str1;

    string line;

    if (argc == 1) {

    cout << "Give a string from which to search for: ";
    getline(cin >> ws, str);

    cout << "Give search string: ";
    getline(cin >> ws, str1);

    size_t found = str.find(str1);
    
    if (found != string::npos) {
    cout << "\"" << str1 << "\" found in \"" << str << "\" in position " << found << endl;
    }

    else {
        cout << "\"" << str1 << "\" NOT found in \"" << str << "\""<< endl; 
    }
    }

   //     istringstream line_stream(string input);
   // cin <<word<< filename;
    if (argc == 3){
    ifstream file;

    file.open(argv[2]);

    if (file.fail())
    {
        cout << "File failed to open." << endl;
        return 1;
    }

    while (getline(file, line)) {
        if (line.find(argv[1]) != string::npos) {
            cout << line << endl;
        }
    }
    }
    if (argc == 4){
    ifstream file;
    int line_counter;



    file.open(argv[3]);

    int n_count = 0;

    if (file.fail())
    {
        cout << "File failed to open." << endl;
        return 1;
    }

    while (getline(file, line)) {
        line_counter++;
        if (line.find(argv[2]) != string::npos) {
            cout << line_counter << ":\t" << line << endl;
            n_count++;

        }

    }
        cout << endl << "Occurrences of line containing \"" << argv[2] << "\": " << n_count;

    }


    return 0;
}