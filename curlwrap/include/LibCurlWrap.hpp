#ifndef LIB_CURL_WRAP_HPP
#define LIB_CURL_WRAP_HPP

#include <string>

namespace libcurlwrap
{

// init_curl should only be called once within a given process.
void init_curl();

class LibCurlWrap
{
public:
    LibCurlWrap();
    ~LibCurlWrap(); 
    std::string getXHTML(std::string url);
    void appendResult(std::string rply);

private:
    void       *_conn;
    char        _errorBuffer[10240];
    std::string _result;

};

}
#endif
