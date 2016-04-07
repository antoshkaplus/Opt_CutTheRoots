/// main program takes two arguments:
/// -i, -o
/// input and output file paths
/// input and output format are described in problem statement
/// -m : mehtod. for now just NaiveSearch
/// -s : score function probably

#include <chrono>
#include <fstream>

#include "ant/core/core.hpp"

#include "cut_roots.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ant::command_line_parser parser(argv, argc);
    string input, output;
    
    ifstream fin(input);
    ofstream fout(output);
    
    istream *in;
    ostream *out;
    
    bool timed = false;
    if (parser.exists("t")) {
        timed = true;
    }
    
    if (parser.exists("d")) {
        in = &cin;
        out = &cout;
    } else {
        if (parser.exists("i")) {
            input = parser.getValue("i");
            fin.open(input);
            in = &fin;
        } else {
            cerr << "unable to find input file path";
            return 1;
        }
        if (parser.exists("o")) {
            output = parser.getValue("o");
            fout.open(output);
            out = &fout;
        } else {
            cerr << "unable to find output file path";
            return 1;
        }
    }

    vector<string> board = ReadBoard(*in);
    
    auto startTime = std::chrono::high_resolution_clock::now();
    FragileMirrors fm;
    auto v = fm.destroy(board);
    auto endTime = std::chrono::high_resolution_clock::now();
    if (timed) {
        auto bound = std::chrono::seconds(10);
        if (endTime - startTime > bound) {
            return 0;
        }
    }
    PrintSolution(*out, v);
    return 0;
}


int NP;
cin >> NP;

int Npoints;
cin >> Npoints;
vector<int> points(Npoints);
getVector(points);

int Nroots;
cin >> Nroots;
vector<int> roots(Nroots);
getVector(roots);

CutTheRoots cr;
vector<int> ret = cr.makeCuts(NP, points, roots);

cout << ret.size() << endl;
for (int i = 0; i < ret.size(); ++i) {
    cout << ret[i] << endl;
}
cout.flush();
