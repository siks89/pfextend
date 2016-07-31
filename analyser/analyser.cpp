#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

#define MAX_COMP_SEQUENCE 50

bool cmp(std::vector<std::string>  &pool,
         uint16_t min_num_iter)
{
    // control the size of the comparison
    for (uint32_t i = min_num_iter; i < (pool.size() / 2) ; ++i)
    {
        // control the starting point of the comparison
        for (uint32_t k = 0; k < (pool.size() - (i * 2)); ++k)
        {
            bool eq{true};
            // executes the comparison
            for (uint32_t j = 0; j < i; ++j)
            {
                if (pool[k + j] != pool[k+i+j])
                {
                    eq = false;
                    break;
                }
            }

            if (eq)
            {
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char *argv[])
{
    std::cout << "Analyser:" << std::endl;

    std::vector<std::string>  pool;

    std::string new_line;
    while (std::getline(std::cin, new_line, '\n'))
    {
        std::cout << "Line: " << new_line << std::endl;

        pool.push_back(new_line);

        if (pool.size() > MAX_COMP_SEQUENCE)
        {
            pool.erase(	pool.begin());
        }

        if (cmp(pool, 2))
        {
            std::cout << "Prediction: Program will not STOP!" << std::endl;
            return EXIT_SUCCESS;
        }
    }

    std::cout << "Program has stopped!" << std::endl;

    return EXIT_SUCCESS;
}
