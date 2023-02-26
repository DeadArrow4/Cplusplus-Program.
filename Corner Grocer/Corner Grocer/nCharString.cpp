#include <string>
using namespace std;


string nCharString(size_t n, char c) {//prints character based on the value of n
    int i;
    std::string s;
    for (i = 0; i < n; ++i) {
        s += c;
    }
    return s;
}