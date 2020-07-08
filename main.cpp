#include <iostream>
#include "include/purge.hpp"
#include "include/fuzzer.hpp"
#include "include/log_book.hpp"
#include <functional>

PURGE_MAIN

bool hasNewLine(const std::string & x){
    int i = 0;
    while( x[i] != '\n'){
        i++;
    }
    return true;;
}

bool isSumGTZero(const std::vector<int> vec){
    int x = std::accumulate(vec.begin(),vec.end(),0);
    return x > 0;
}

bool test_digit(char value){
    return std::isdigit(value);
}

struct NumberClass{
    bool is_number(char x){
        return test_digit(x);
    }
};

METHODE_TEST_CASE(TEST_CLASS_METHOD,NumberClass,{},is_number,(false,'a'), ( true,'1'),(false,'b'));
FUNCTION_TEST_CASE(IS_NUMBER,test_digit, (false,'a'), ( true,'1'),(false,'b') );




SIMPLE_TEST_CASE(LOG_BOOK_TEST){
    using purge::to_string;
    REQUIRE(to_string(purge::TEST_STATE::SEGMENTATION_FAULT) == "\033[1;35m Segmentation fault\033[0m");
    REQUIRE(to_string(purge::TEST_STATE::OK) == "\033[1;32m Ok\033[0m");
    REQUIRE(to_string(purge::TEST_STATE::FAILED) == "\033[1;31m Failed\033[0m");
}


SIMPLE_TEST_CASE(CONTAINER_TEST){
    std::vector<int> vec = {0,1,2,3,-10};
    REQUIRE(isSumGTZero(vec));
}

SIMPLE_TEST_CASE(SimpleTest){

    std::cout<<"Hallo Welt"<<std::endl;
}

/*
FUZZER_CONTAINER_CASE(IS_SUM_GT_FUZZ,std::vector<int>,purge::item_rule<int>([](int &&v)->bool{ return v > 0; }),FZ){
    REQUIRE(isSumGTZero(FZ));
}

FUZZER_CONTAINER_CASE(FUZZ_HAS_NES_LINE,std::string,purge::item_rule<char>([](char &&v)->bool{ return true; }),FV){
    hasNewLine(FV);
}
*/







