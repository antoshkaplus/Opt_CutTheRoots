
#pragma once

#include <vector>

#include "ant/geometry/d2.hpp"

using namespace ant;
using ant::geometry::d2::i::Point;
using ant::geometry::d2::i::Segment;
using namespace std;

struct Root {
    int plant;
    int end;
};

struct Problem {
    Count num_plants;
    vector<Point> points;
    vector<Root> roots;
    
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
vector<int> ToVectorInt(vector<Point>& points);
void Print(ostream& out, vector<int>& vs);
void PrintSolution(ostream& out, vector<Segment>& sol);