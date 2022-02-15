#include <iostream>
#include <curl/curl.h>
#include <string>
#include <memory.h>
#include <sstream>
namespace Test{
    class sayHello{
        public:
            sayHello();
            ~sayHello();
        public:
            void ToSay();
            static size_t receive_data(void *contents, size_t size, size_t nmemb, void *stream);
            static CURLcode HttpGet(const std::string & strUrl, std::string & strResponse,int nTimeout);
    };
}
