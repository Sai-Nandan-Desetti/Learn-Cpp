/**
 * @file main.cpp
 * @author DSN
 * @brief Copy a matrix (with its dimension details) from src to dest
 * @version 0.2
 * @date 2023-09-18
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int main(int argc, char* argv[])
{
    using Row = std::vector<int>;
    using Grid = std::vector<Row>;
    using Size = Row::size_type;    
    
    if (argc == 1)
    {
        std::cerr << "Enter a filename!\n";
        std::cerr << "<.\\main.exe <src> <dest>\n";

        return -1;
    }    
    
    const char* src{ argv[1] };
    std::ifstream fin{ src, std::ios::in };

    if (!fin)
    {
        std::cerr << "Error opening the file!\n";
        return -1;            
    }

    Size m{};
    fin >> m; // number of rows
    
    Size n{};
    fin >> n; // number of cols

    // std::cout << "Rows: " << m << " Cols: " << n << '\n';
    Grid grid(m, Row(n, 0));

    for (auto& row : grid)
        for (auto& ele : row)
            fin >> ele;

    const char* dest{ argv[2] };
    std::ofstream fout{ dest, std::ios::out };
    
    fout << m << '\n' << n << '\n';
    for (const auto& row : grid)
    {
        for (const auto& ele : row)
            fout << ele << '\t';
        fout << '\n';
    }
        
    return 0;
} // fin and fout automatically close when they go out of scope 
