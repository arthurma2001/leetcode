#include "utils.hpp"
namespace leetcode
{
    namespace utils
    {
        void dumpBool (const string &title, bool e)
        {
            fprintf (stderr, "%s: %s\n", title.c_str(), e ? "true" : "false");
        }
        
        void dump_bool (const string &title, bool e)
        {
            dumpBool (title, e);
        }
    }
}
