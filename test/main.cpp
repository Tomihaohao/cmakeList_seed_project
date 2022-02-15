#include <iostream>
#include "sayHello.h"
using namespace std;
using namespace Test;
int main(int agec, char **argv) {
	cout << "Hello world" << endl;
    Test::sayHello *hello = new Test::sayHello();
    hello->ToSay();
    string strURL = "http://www.baidu.com";
    string strResponse;
    CURLcode nRes = Test::sayHello::HttpGet(strURL, strResponse,300);
    size_t nSrcLength = strResponse.length();
    cout<<strResponse;
    delete hello;
    
    return 0;
}