/// this project is used to test new methods on real data
/// 


#include "util.hpp"
#include "cut_roots.hpp"

int main(int argc, const char * argv[]) {
    auto input = "./../temp/input.txt";
    auto output = "./../temp/output.txt";
    ifstream in(input);
    ofstream out(output);
    
    auto pr = ReadProblem(in);
    CutTheRoots cr;
    auto ps = ToVectorInt(pr.points);
    auto rs = ToVectorInt(pr.roots);
    auto res = cr.makeCuts(pr.num_plants, ps, rs);
    Print(out, res);
}