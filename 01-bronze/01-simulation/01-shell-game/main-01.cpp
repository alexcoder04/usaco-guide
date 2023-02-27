// this is my original solution, written entirely by me

#include <iostream>
#include <fstream>
#include <vector>
#include <array>

using namespace std;

int main(){
    string line;

    ifstream infile;
    infile.open("shell.in");

    if (!infile.is_open()) {
        cout << "failed to open the file" << endl;
        return 1;
    }

    int swaps_number;
    getline(infile, line);
    swaps_number = stoi(line);

    vector <vector<int>> steps(swaps_number);

    for (int i = 0; i < swaps_number; ++i) {
        getline(infile, line);

        steps[i].push_back(line[0] - '0' - 1);
        steps[i].push_back(line[2] - '0' - 1);
        steps[i].push_back(line[4] - '0' - 1);
    }

    for (int i = 0; i < steps.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << steps[i][j];
        }
        cout << endl;
    }

    infile.close();

    int max_right_guesses = 0;
    for (int i = 0; i <= 2; ++i) {
        array <bool, 3> shells = {false, false, false};
        shells[i] = true;
        int right_guesses = 0;

        for (int i = 0; i < steps.size(); ++i) {
            bool s = shells[steps[i][0]];
            shells[steps[i][0]] = shells[steps[i][1]];
            shells[steps[i][1]] = s;
            if (shells[steps[i][2]]) {
                right_guesses++;
            }
        }

        if (right_guesses > max_right_guesses) {
            max_right_guesses = right_guesses;
        }
    }

    ofstream outfile;
    outfile.open("shell.out");
    outfile << max_right_guesses;
    outfile.close();

    //cout << max_right_guesses << endl;
    return 0;
}

