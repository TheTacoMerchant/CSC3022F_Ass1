#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

struct TagStruct
{
    std::string tag_name;
    int pair_nr;
    std::string text;
};

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
            curr_text = filestring.substr(0,filestring.find("<"));
            filestring = filestring.substr(filestring.find(">")+1);
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

int main(){
    std::string command;
    std::cout << "Enter command: ";
    std::cin >> command;
    std::vector<TagStruct> tags;

    while (command != "q"){
        if (command == "r"){
            std::string filename;
            std::cout << "Enter  the name of the input file: ";
            std::cin >> filename;
            tags = parse(filename, tags);
        }
        if (command == "p"){
            for (int i=0; i<tags.size();i++){
                std::cout<<tags[i].tag_name<<"\n";
            }
        }
        if (command == "d"){
            std::ofstream outfile("tag.txt");
            std::string outstring;
            for (int i=0;i<tags.size();i++){
                outstring = outstring + "Tag name: " + tags[i].tag_name + "\n" + "Number of pairs: " + std::to_string(tags[i].pair_nr)q + "\n" + "Text: " + tags[i].text + "\n\n";
            }
            outfile << outstring;
            outfile.close();
        }
        if (command == "l"){
            std::string tagname;
            std::cout << "Enter  the name of the tag: ";
            std::cin >> tagname;
            for (int i=0;i<tags.size();i++){
                if (tags[i].tag_name == tagname){
                    std::cout << "Tag name: " << tagname<<"\n";
                    std::cout << "Number of pairs: " << tags[i].pair_nr<<"\n";
                    std::cout << "Text: " << tags[i].text<<"\n";
                }
            }
        }
        std::cout << "Enter command: ";
        std::cin >> command;
    }
}



