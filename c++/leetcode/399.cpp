/*
//399. Evaluate Division
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]

Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]

Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
    **/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
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

            string v1_s;
            string v2_s;
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

        void processing1(const vector<M>& mappings, const vector<vector<string>>& queries,
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

        vector<double> ama_calcEquation_01(const vector<vector<string>>& equations,
                                    const vector<double>& values, const vector<vector<string>>& queries) {

            vector<M> mappings;
            buildMaping(equations, values, mappings);

            vector<double> out_vals;
            processing1(mappings, queries, out_vals);
            return out_vals;
        }

        
        vector<double> sample_calcEquation01 (const vector<vector<string>>& equations,
                                           const vector<double>& values,
                                           const vector<vector<string>>& queries) {
            vector<double> ans;
            // graph[A][B] := A / B
            unordered_map<string, unordered_map<string, double>> graph;

            for (int i = 0; i < equations.size(); ++i) {
                const string& A = equations[i][0];
                const string& B = equations[i][1];
                graph[A][B] = values[i];
                graph[B][A] = 1 / values[i];
            }

            for (const auto& q : queries) {
                const string& A = q[0];
                const string& C = q[1];
                if (!graph.count(A) || !graph.count(C))
                    ans.push_back(-1);
                else
                    ans.push_back(divide(graph, A, C, unordered_set<string>()));
            }

            return ans;
        }

        void buildMaping2 (const vector<vector<string>>& equations,
                                    const vector<double>& values,
                           std::map<string, std::map<string, double>> &out)
        {
            int n = values.size();
            for (int i = 0; i < n; i++)
            {
                string A = equations[i][0];
                string B = equations[i][1];
                double V = values[i];
                out[A][B] = V;
                out[B][A] = 1.0/V;
            }
        }

        double processing_indirect (std::map<string, std::map<string, double>> &mappings,
                                    std::map<string, double> &b_map,
                                    const string &v1_s, const string &v2_s)
        {
            //["a","b"] ,  ["b","c"]  ==> ["a", "c"]
            for (const auto &[k,v] : b_map)
            {
                if (mappings.find(k) != mappings.end())
                {
                    std::map<string, double> &c_map = mappings[k];
                    if (c_map.find(v2_s)  != c_map.end())
                    {
                        return v * c_map[v2_s];
                    }                                    
                }
            }
            return -1;
        }

        void processing2(std::map<string, std::map<string, double>> &mappings,
                         const vector<vector<string>>& queries,
                         vector<double> &out_vals)
            {
                out_vals.clear();
                for (auto d : queries)
                {
                    string v1_s = d[0];
                    string v2_s = d[1];
                    if (mappings.find(v1_s) == mappings.end() )
                    {
                        out_vals.push_back(-1);
                        continue;
                    }
                    
                    std::map<string, double> &b_map = mappings[v1_s];
                    if (b_map.find(v2_s) != b_map.end())
                    {
                        double val = b_map[v2_s];
                        out_vals.push_back (val);
                        continue;
                    }

                    double val = processing_indirect (mappings, b_map, v1_s, v2_s);
                    out_vals.push_back (val);
                }
            }
        
        vector<double> ama_calcEquation_02(const vector<vector<string>>& equations,
                                    const vector<double>& values, const vector<vector<string>>& queries)
        {
            std::map<string, std::map<string, double>> mappings;
            buildMaping2 (equations, values, mappings);
            
            vector<double> out_vals;
            processing2(mappings, queries, out_vals);

            return out_vals;
        }

 private:
        // return A / C
        double divide(
            const unordered_map<string, unordered_map<string, double>>& graph,
            const string& A, const string& C, unordered_set<string>&& seen) {
            if (A == C)
                return 1.0;

            seen.insert(A);

            // value := A / B
            for (const auto& [B, value] : graph.at(A)) {
                if (seen.count(B))
                    continue;
                const double res = divide(graph, B, C, move(seen));  // B / C
                if (res > 0)                                         // valid result
                    return value * res;  // A / C = (A / B) * (B / C)
            }

            return -1;  // invalid result
        }
  
    public:
        vector<double> calcEquation(const vector<vector<string>>& equations,
                                    const vector<double>& values, const vector<vector<string>>& queries) {
            //return ama_calcEquation_02 (equations, values, queries);
            return sample_calcEquation01 (equations, values, queries);
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
