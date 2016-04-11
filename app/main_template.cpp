/// main program takes two arguments:
/// -i, -o
/// input and output file paths
/// input and output format are described in problem statement
/// 
/// 


#include <chrono>
#include <fstream>

#include "ant/core/core.hpp"

#include "cut_roots.hpp"
#include "util.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ant::command_line_parser parser(argv, argc);
    string input, output;
    
    ifstream fin;
    ofstream fout;
    
    istream *in;
    ostream *out;
    
    bool timed = false;
    bool print_input = false;
    
    if (parser.exists("t")) {
        timed = true;
    }
    
    if (parser.exists("d")) {
        in = &cin;
        out = &cout;
        if (parser.exists("i")) {
            print_input = true;
            input = parser.getValue("i");
            fout.open(input);
        }
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

    Problem pr = ReadProblem(*in);
    if (print_input) {
        PrintProblem(fout, pr);
    }
    auto startTime = std::chrono::high_resolution_clock::now();
    CutTheRoots cr;
    auto ps = ToVectorInt(pr.points);
    auto rs = ToVectorInt(pr.roots);
    auto v = cr.makeCuts(pr.num_plants, ps, rs);
    auto endTime = std::chrono::high_resolution_clock::now();
    if (timed) {
        auto bound = std::chrono::seconds(10);
        if (endTime - startTime > bound) {
            return 0;
        }
    }
    Print(*out, v);
    return 0;
}
