/// main program takes two arguments:
/// -i, -o
/// input and output file paths
/// input and output format are described in problem statement
/// -m : mehtod. for now just NaiveSearch
/// -s : score function probably

#include "util.hpp"
#include "cut_roots.hpp"

std::vector<int> CutTheRoots::makeCuts(int num_plants, 
                                       const vector<int>& int_points, 
                                       const vector<int>& int_roots) {
    Problem pr(num_plants, int_points, int_roots);
    const auto& pp = pr.points;
    
    vector<Index> ps(num_plants);
    iota(ps.begin(), ps.end(), 0);
    sort(ps.begin(), ps.end(), [&](const Index& i_0, const Index& i_1) {
        return pp[i_0].x < pp[i_1].x;
    });
    
    vector<Point> res;  
    for (Index i = 0; i < ps.size()-1; ++i) {
        int x = (pp[ps[i]].x + pp[ps[i+1]].x) / 2;
        res.push_back({x, 1});
        res.push_back({x, 2});
    }
    return ToVectorInt(res);

    
}