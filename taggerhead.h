#include <vector>
#include <string>

#ifndef _tagger_h
#define _tagger_h
namespace BRGMAR044
{
    struct TagStruct
    {
        std::string tag_name;
        int pair_nr;
        std::string text;
    };
    std::string remove_newline(std::string str);
    std::vector<TagStruct> parse(std::string filename, std::vector<TagStruct> tagarr);
    int main();
}
#endif