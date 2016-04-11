
#pragma once

#include <vector>
#include <fstream>

#include "ant/geometry/d2.hpp"

using namespace ant;
using ant::geometry::d2::i::Point;
using ant::geometry::d2::i::Segment;
using namespace std;

struct Root {
    Index plant;
    Index end;
    
    Root() {}
    
    Root(Index plant, Index end) 
        : plant(plant), end(end) {}
};

struct Problem {
    Count num_plants;
    vector<Point> points;
    vector<Root> roots;
    
    Problem() : num_plants(0) {}
    
    Problem(Count num_plants, const vector<int>& ps, const vector<int>& rs) {
        this->num_plants = num_plants;
        for (auto i = 0; i < ps.size(); i += 2) {
            points.emplace_back(ps[i], ps[i+1]);
        }
        for (auto i = 0; i < rs.size(); i += 2) {
            roots.emplace_back(rs[i], rs[i+1]);
        }
    }
};


Problem ReadProblem(istream& in);
void PrintProblem(ostream& out, const Problem& problem);
vector<Int> ToVectorInt(const vector<Point>& points);
vector<Int> ToVectorInt(const vector<Root>& roots);
void Print(ostream& out, const vector<Int>& vs);
void PrintSolution(ostream& out, const vector<Segment>& sol);