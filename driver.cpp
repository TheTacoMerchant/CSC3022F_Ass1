#include "taggerhead.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main()
{
    std::string command;
    std::cout << "Enter command: ";
    std::cin >> command;
    std::vector<BRGMAR044::TagStruct> tags;

    while (command != "q")
    {
        if (command == "r")
        {
            std::string filename;
            std::cout << "Enter  the name of the input file: ";
            std::cin >> filename;
            tags = BRGMAR044::parse(filename, tags);
        }
        if (command == "p")
        {
            for (int i = 0; i < tags.size(); i++)
            {
                std::cout << tags[i].tag_name << "\n";
            }
        }
        if (command == "d")
        {
            std::ofstream outfile("tag.txt");
            std::string outstring;
            for (int i = 0; i < tags.size(); i++)
            {
                outstring = outstring + "Tag name: " + tags[i].tag_name + "\n" + "Number of pairs: " + std::to_string(tags[i].pair_nr) + "\n" + "Text: " + tags[i].text + "\n\n";
            }
            outfile << outstring;
            outfile.close();
        }
        if (command == "l")
        {
            std::string tagname;
            std::cout << "Enter  the name of the tag: ";
            std::cin >> tagname;
            for (int i = 0; i < tags.size(); i++)
            {
                if (tags[i].tag_name == tagname)
                {
                    std::cout << "Tag name: " << tagname << "\n";
                    std::cout << "Number of pairs: " << tags[i].pair_nr << "\n";
                    std::cout << "Text: " << tags[i].text << "\n";
                }
            }
        }
        std::cout << "Enter command: ";
        std::cin >> command;
    }
    return 0;
}
