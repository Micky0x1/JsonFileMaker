#include <iostream>
#include <string>
#include <fstream>

class Json_Maker
{
    public :
    static void Main() {
        std::string select;
        std::cout << "//.help == shows all commands" << '\n' << "//.close == closes program" << std::endl;
        std::cout << "//.new == makes new file" << '\n' << "JsonFileMaker $: ";
        std::cin >> select;
        if(select == ".new") TheNew(), Main();
        if(select == ".close") TheClose();
        if(select == ".help") TheHelp();
        else std::cout << "Unexpected command !" << std::endl, Main();
    }

    static void TheNew() {
        std::cout << "File name : ";
        std::string file_name, key_name, value_type, value;
        std::cin >> file_name;
        std::cout << "Key name : ";
        std::cin >> key_name;
        std::cout << "Type of value : ";
        std::cin >> value_type;
        std::cout << "Value : ";
        std::cin >> value;
        value.insert(0, value_type);
        GetKeysAndValues(key_name, value, file_name);
    }

    static void TheClose() {
        exit(0);
    }

    static void TheHelp() {
        std::cout << "-s to make string" << '\n' << "-d to make digit" << std::endl;
        std::cout << "-a to make array" << '\n' << "-o to make object" << std::endl;
        std::cout << "-end to finish array or object" << '\n' << ".exit to exit" << std::endl;
        Main();
    }
    static void GetKeysAndValues(std::string key, std::string value, std::string NameOfFile) {
        std::string whole;
        whole+='"';
        whole+=key;
        whole+='"';
        whole+=" : ";
        if(value[1] == 's') {
            value.erase(0, 2);
            whole+='"';
            whole+=value;
            whole+='"';
        }
        else if(value[1] == 'd') {
            value.erase(0, 2);
            whole+=value;
        }
        std::ofstream file;
        file.open("C:\\MyPrograms\\JsonFileMaker\\JsonFiles\\" + NameOfFile + ".json");    
        file << "{\n";
        file << "   " + whole;
        file << "\n}";
        file.close();
        Main();
    }
};

int main() {
    Json_Maker User;
    User.Main();
    return 0;
}