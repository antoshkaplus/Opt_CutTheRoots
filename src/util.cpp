
#include "util.hpp"

vector<int> ToVectorInt(vector<Point>& ps) {
    vector<int> res;
    for (Point& p : ps) {
        res.push_back(p.x);
        res.push_back(p.y);
    }
    return res;
}

Problem ReadProblem(istream& in) {
    Problem pr;
    cin >> pr.num_plants;
    int num_point_coords;
    cin >> num_point_coords;
    auto& ps = pr.points;
    ps.resize(num_point_coords/2);
    for (int i = 0; i < ps.size(); ++i) {
        in >> ps[i].x;
        in >> ps[i].y;
    }
    int num_root_inds;
    cin >> num_root_inds;
    auto& rs = pr.roots;
    rs.resize(num_root_inds/2);
    for (int i = 0; i < rs.size(); ++i) {
        in >> rs[i].plant;
        in >> rs[i].end;
    }
    return pr;
}

void PrintSolution(ostream& out, vector<Segment>& sol) {
    out << 2*sol.size();
    for (auto& s : sol) {
        out << s.fst.x << endl;
        out << s.fst.y << endl;
        out << s.snd.x << endl;
        out << s.snd.y << endl;
    }
    out.flush();
}

void Print(ostream& out, vector<int>& vs) {
    out << vs.size() << endl;
    for (auto& v : vs) {
        out << v << endl;
    }
    out.flush();
}