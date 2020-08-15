#include <iostream>
#include <string>

int main (int argc, char* argv[]) {
    std:: string count;
    getline(std::cin,count);
    const int length = std::stoi(count);
    std::cout << length << std::endl;
    const int numOfnum = 2;
    int tupleArray[length][numOfnum]{};
    
    for (int i = 0; i < length; i++) {
        for (int k = 0; k < length; k++) {
            for (int m = 0; m < numOfnum; m++) {
                std::cout << tupleArray[k][m] << " ";
            }
            std::cout << std:: endl;
        }
        for (int j = 0; j < numOfnum; j++){
            std::cin >> tupleArray[i][j];
        }
        // std:: cout << i << std:: endl;
        // std:: cout << "sum " << tupleArray[i][0] << " " << tupleArray[i][1] << std::endl;
        // std::string x,y;
        // x = std::cin.get();
        // std::cin.ignore(100,' ');
        // y = std::cin.get();
        // std::cin.ignore(100, '\n');
        // tupleArray[i][0] = std::stoi(x);
        // tupleArray[i][1] = std::stoi(y);
        // std::cout << "sum " << tupleArray[i][0] << " " << tupleArray[i][1] << std::endl;
    }


    // for (int i = 0; i < length; i++) {
    //     for (int j = 0; j < numOfnum; j++){
    //         std::cout << "num " << tupleArray[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
        
            
        


    std::string end;
    getline(std::cin, end);

    return 0;
}