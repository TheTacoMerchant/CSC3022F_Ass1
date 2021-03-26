#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "taggerhead.h"


namespace BRGMAR044{

std::string remove_newline(std::string str){
    std::string output;
    output.reserve(str.size());
    for(size_t i = 0; i < str.size(); ++i)
        if(str[i] != '\n') output += str[i];
    
    return output;
}

std::vector<TagStruct> parse(std::string filename, std::vector<TagStruct> tagarr){
        std::string curr_tag, curr_endtag;
        std::ifstream myfile(filename);      
        std::string filestring((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());
        filestring = remove_newline(filestring);
        while (filestring.find("<") != std::string::npos){
            std::string curr_text;
            curr_tag = filestring.substr(filestring.find("<")+1, filestring.find(">")-1);
            filestring = filestring.substr(filestring.find(">")+1);
            curr_text = filestring.substr(0,filestring.find("</"));
            filestring = filestring.substr(filestring.find(curr_tag+">")+1 + curr_tag.length());
            bool is_new = true;
            for (int i = 0; i < tagarr.size(); i++){
                if (tagarr[i].tag_name == curr_tag){
                    tagarr[i].pair_nr = tagarr[i].pair_nr+1;
                    tagarr[i].text = tagarr[i].text + ":" + curr_text;
                    is_new = false;
                }
            }
            if (is_new){
                struct TagStruct ts = {curr_tag, 1, curr_text};
                tagarr.push_back(ts);
            }
        }
        return tagarr;
}
}



