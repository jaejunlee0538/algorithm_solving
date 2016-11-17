#include <algorithm>
#include <vector>
#include "combinations.h"

int main(){
    std::vector<int> sample = {1,2,3,2};

    {
        auto combs = combinations(sample, 3);
//    printResult(combs);
        std::cout << "Total : " << combs.size() << " permutations" << std::endl;
    }

    {
        std::cout<<"------------------------------"<<std::endl;
        std::cout<<"Using std::next_permutation"<<std::endl;
        size_t count = 0;
        //sample must be sorted!!
        std::sort(sample.begin(), sample.end());

        do{
            count++;
//            for(const auto& v: sample){
//                std::cout<<v<<" ";
//            }
//            std::cout<<std::endl;
        }while(std::next_permutation(sample.begin(), sample.end()));
        std::cout<<"Total : "<<count<<" permutations"<<std::endl;
    }
    {
        std::cout<<"------------------------------"<<std::endl;

        typedef combination2::combinations::combination_t combination_t;
        combination2::combinations comb(4, 2);
        while(!comb.completed){
            combination_t c = comb.next();
            for(auto& v:c){
                std::cout<<v<<" ";
            }
            std::cout<<std::endl;
        }
    }

    return 0;
}