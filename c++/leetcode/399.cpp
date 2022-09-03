#include <iostream>
#include <vector>
using namespace std;
#include "basic/utils.hpp"

namespace
{
    class Solution {
        struct M
        {
            M() { }
            M(string v1, string v2, double out)
                {
                    this->v1_s = v1;
                    this->v2_s = v2;
                    this->out_val = out;
                }

            string v1_s, v2_s;
            double out_val;
        };

        void buildMaping(const vector<vector<string>>& equations,
                         const vector<double>& values,
                         vector<M>& out_mappings)
            {
                out_mappings.clear();
                int n = equations.size();
                for (int i = 0; i < n; i++) {
                    string v1_s = equations[i][0];
                    string v2_s = equations[i][1];
                    double div_v = values[i];
                    M m1(v1_s, v2_s, div_v);
                    M m2(v2_s, v1_s, 1.0 / div_v);
                    out_mappings.push_back(m1);
                    out_mappings.push_back(m2);
                }
            }

        bool searchMapping(const vector<M>& mappings,
                           const string &v1_s,
                           const string &v2_s, M &out)
            {
                M m1, m2;
                bool found_m1 = false;
                bool found_m2 = false;

                for (auto d : mappings)
                {
                    if (d.v1_s == v1_s &&
                        d.v2_s == v2_s)
                    {
                        out = d;
                        return true;
                    }
                    if (d.v1_s == v1_s)
                    {
                        m1 = d;
                        found_m1 = true;
                        continue;
                    }
                    if (d.v2_s == v2_s)
                    {
                        m2 = d;
                        found_m2 = true;
                    }
                    if (found_m1 && found_m2)
                        break;
                }
                if (found_m1 && found_m2)
                {
                    if (m1.v2_s == m2.v1_s)
                    {
                        M m(m1.v1_s, m2.v2_s, m1.out_val * m2.out_val);
                        out = m;
                        return true;
                    }
                }
                return false;
            }

        void processing(const vector<M>& mappings, const vector<vector<string>>& queries,
                        vector<double> &out_vals)
            {
                out_vals.clear();
                for (auto d : queries)
                {
                    string v1_s = d[0];
                    string v2_s = d[1];
                    M out;
                    if (searchMapping(mappings, v1_s, v2_s, out))
                    {
                        out_vals.push_back (out.out_val);
                    }
                    else
                        out_vals.push_back(-1);
                }
            }

    public:
        vector<double> calcEquation(const vector<vector<string>>& equations,
                                    const vector<double>& values, const vector<vector<string>>& queries) {

            vector<M> mappings;
            buildMaping(equations, values, mappings);

            vector<double> out_vals;
            processing(mappings, queries, out_vals);
            return out_vals;
        }
    };

    void dump_result(const string& title,
                            const vector<double>& out_vals)
    {
        leetcode::utils::dump_vector (title, out_vals);
    }
}

int leetcode_399_main(int argc, char** argv)
{
    Solution s1;
    vector<double> out_vals1 = s1.calcEquation(
        { {"a", "b"},{"b", "c"} }, { 2.0, 3.0 },
        { {"a", "c"},{"b", "a"},{"a", "e"},{"a", "a"},{"x", "x"} });
    dump_result("Example1", out_vals1);
    
    vector<double> out_vals2 = s1.calcEquation(
        { {"a", "b"}, {"b", "c"}, {"bc", "cd"} },
        { 1.5, 2.5, 5.0 },
        { {"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"} });
    dump_result("Example2", out_vals2);
    
    vector<double> out_vals3 = s1.calcEquation(
        { {"a", "b"} }, { 0.5 },
        { {"a", "b"},{"b", "a"},{"a", "c"},{"x", "y"} });
    dump_result("Example3", out_vals3);
    
    return 0;
}
