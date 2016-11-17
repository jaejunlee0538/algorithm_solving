//
// Created by ub1404 on 16. 11. 16.
//

#ifndef UNTITLED_COMBINATIONS_H
#define UNTITLED_COMBINATIONS_H

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>


template <typename T>
void printResult(const std::vector<std::vector<T>>& result){
    for(const auto& v:result){
        for(const auto& data:v) {
            std::cout << data << " ";
        }
        std::cout<<std::endl;
    }
}

template <typename T>
std::vector<std::vector<T>> combinations(const std::vector<T>& input, size_t len){
    std::vector<std::vector<T>> result;
    if(len == 1){
        for(size_t i=0;i<input.size();i++){
            result.push_back({input[i]});
        }
        return result;
    }

    for (size_t i = 0; i < input.size(); i++) {
        //Creating sub-vector for the next recursion
        std::vector<T> sub_input;
        for (size_t k = 0; k < input.size(); k++) {
            if (k != i) {
                sub_input.push_back(input[k]);
            }
        }
        //recursive call
        std::vector<std::vector<T>> tmp = combinations(sub_input, len - 1);

        //add to result
        T first = input[i];
        std::for_each(tmp.begin(), tmp.end(),[&result, first](const std::vector<T>& after){
            result.push_back({first});
            result.back().reserve(result.size()+after.size());
            std::copy(after.begin(), after.end(), std::back_inserter(result.back()));
        });
    }
    return result;
}


namespace combination2 {
    struct combinations
    {
        typedef std::vector<int> combination_t;

        // initialize status
        combinations(int N, int len) :
                completed(N < 1 || len > N),
                generated(0),
                N(N), len(len)
        {
            for (int c = 1; c <= len; ++c)
                curr.push_back(c);
        }

        // true while there are more solutions
        bool completed;

        // count how many generated
        int generated;

        // get current and compute next combination
        combination_t next()
        {
            combination_t ret = curr;

            // find what to increment
            completed = true;
            for (int i = len - 1; i >= 0; --i) {
                if (curr[i] < N - len + i + 1) {
                    int j = curr[i] + 1;
                    while (i <= len)
                        curr[i++] = j++;
                    completed = false;
                    ++generated;
                    break;
                }
            }
            return ret;
        }

    private:
        const int N, len;
        combination_t curr;
    };

}





#endif //UNTITLED_COMBINATIONS_H
