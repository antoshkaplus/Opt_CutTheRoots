
#include "util.hpp"

vector<int> ToVectorInt(const vector<Point>& ps) {
    vector<int> res;
    for (const Point& p : ps) {
        res.push_back(p.x);
        res.push_back(p.y);
    }
    return res;
}

vector<Int> ToVectorInt(const vector<Root>& roots) {
    vector<int> res;
    for (const Root& r : roots) {
        res.push_back(r.plant);
        res.push_back(r.end);
    }
    return res;
}

Problem ReadProblem(istream& in) {
    Problem pr;
    in >> pr.num_plants;
    int num_point_coords;
    in >> num_point_coords;
    auto& ps = pr.points;
    ps.resize(num_point_coords/2);
    for (int i = 0; i < ps.size(); ++i) {
        in >> ps[i].x;
        in >> ps[i].y;
    }
    int num_root_inds;
    in >> num_root_inds;
    auto& rs = pr.roots;
    rs.resize(num_root_inds/2);
    for (int i = 0; i < rs.size(); ++i) {
        in >> rs[i].plant;
        in >> rs[i].end;
    }
    return pr;
}

void PrintProblem(ostream& out, const Problem& pr) {
    out << pr.num_plants << endl;
    auto ps = ToVectorInt(pr.points);
    Print(out, ps);
    auto rs = ToVectorInt(pr.roots);
    Print(out, rs);
}

void PrintSolution(ostream& out, const vector<Segment>& sol) {
    out << 2*sol.size();
    for (auto& s : sol) {
        out << s.fst.x << endl;
        out << s.fst.y << endl;
        out << s.snd.x << endl;
        out << s.snd.y << endl;
    }
    out.flush();
}

void Print(ostream& out, const vector<int>& vs) {
    out << vs.size() << endl;
    for (auto& v : vs) {
        out << v << endl;
    }
    out.flush();
}