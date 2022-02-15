#include "sayHello.h"

Test::sayHello::sayHello(){
    std::cout<<"init";
};

Test::sayHello::~sayHello(){
    std::cout<<" un init";
};

void Test::sayHello::ToSay(){
    std::cout<<"hello everybody";
}

size_t Test::sayHello::receive_data(void *contents, size_t size, size_t nmemb, void *stream){
    std::string *str = (std::string*)stream;
    (*str).append((char*)contents, size*nmemb);
    return size * nmemb;
}

CURLcode Test::sayHello::HttpGet(const std::string & strUrl, std::string & strResponse,int nTimeout){
    CURLcode res;
    CURL* pCURL = curl_easy_init();

    if (pCURL == NULL) {
        return CURLE_FAILED_INIT;
    }

    curl_easy_setopt(pCURL, CURLOPT_URL, strUrl.c_str());
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(pCURL, CURLOPT_NOSIGNAL, 1L);
    curl_easy_setopt(pCURL, CURLOPT_TIMEOUT, nTimeout);
    curl_easy_setopt(pCURL, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(pCURL, CURLOPT_WRITEFUNCTION, Test::sayHello::receive_data);
    curl_easy_setopt(pCURL, CURLOPT_WRITEDATA, (void*)&strResponse);
    res = curl_easy_perform(pCURL);
    curl_easy_cleanup(pCURL);
    return res;
}