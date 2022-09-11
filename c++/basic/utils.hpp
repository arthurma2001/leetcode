#include <iostream>     // std::cout, std::ios
#include <sstream>      // std::ostringstream
#include <string>
#include <vector>
using namespace std;

namespace leetcode
{
    namespace utils
    {
        template<typename T>
        void dump_vector (const string& title,
                          const vector<T>& vals)
        {
            std::ostringstream ss;
            ss << title << " = { ";

            int n = vals.size();
            for (int i = 0; i < n; i++)
            {
                const T &v = vals[i];
                ss << v;
                if (i < n-1) ss << ",";
            }
            ss << " }";
            fprintf(stderr, "%s\n", ss.str().c_str());
        }

        template<typename T>
        void dump_val (const string& title, T val)
        {
            return dump_vector<T>(title, { val } );
        }

        template<typename T>
        void dump_vectors (const string& title,
                           const vector< vector<T> >& vals_lst)
        {
            std::ostringstream ss;
            ss << title << " = { ";

            for (const auto &vals : vals_lst)
            {
                ss <<  " { ";
                int n = vals.size();
                for (int i = 0; i < n; i++)
                {
                    const T &v = vals[i];
                    ss << v;
                    if (i < n-1) ss << ",";
                }
                ss << " }, ";
            }
            ss << " } ";
            fprintf(stderr, "%s\n", ss.str().c_str());
        }

        void dumpBool (const string &title, bool e);
        void dump_bool (const string &title, bool e);
    }
}
