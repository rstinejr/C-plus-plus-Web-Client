#include <LibCurlWrap.hpp>
#include <curl/curl.h>

#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace libcurlwrap;

extern "C"
{
	// Callback by which libcurl provides the replies of HTTP requests.
	// This callback is global across the process; the "userdata" value
	// is used to demultiplex, as it were, the replies, and send them to 
	// the appropriate requestor, so that multiple instances of LibCurlWrap 
	// can be instantiated and run concurrently.
    static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
    {
		std::stringstream rply_strm;
        for (size_t i = 0; i < nmemb; i++)
        {
            rply_strm << ptr[i];
        }

        ((LibCurlWrap *) userdata)->appendResult(rply_strm.str());

    	return nmemb;
    }
}

//
// Wrapper around libcur's curl_global_init method.
// Should be called only once pre process.
void init_curl()
{
	  CURLcode ret = curl_global_init(CURL_GLOBAL_SSL);
	  if ( ret )
	  {
		    std::stringstream err_strm;
		    err_strm << "Failure initializing curl: " << ret;
		    throw std::runtime_error(err_strm.str());
	  }
}

LibCurlWrap::LibCurlWrap()
{
	_conn = curl_easy_init();
	if (_conn == NULL)
	{
        throw std::runtime_error("Failure initializing curl.");
	}

    curl_easy_setopt(_conn, CURLOPT_VERBOSE,        false);
    curl_easy_setopt(_conn, CURLOPT_ERRORBUFFER,    _errorBuffer);
    curl_easy_setopt(_conn, CURLOPT_WRITEFUNCTION,  write_callback);
    curl_easy_setopt(_conn, CURLOPT_WRITEDATA,      (void *) this); 
    curl_easy_setopt(_conn, CURLOPT_HTTPGET,        true);
    curl_easy_setopt(_conn, CURLOPT_SSL_VERIFYPEER, false);
	
	// Some websites "won't talk" to a client if they don't recognize the user agent string.
    curl_easy_setopt(_conn, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2227.0 Safari/537.36");
}

LibCurlWrap::~LibCurlWrap()
{
	if ( _conn )
	{
		curl_easy_cleanup(_conn);
	}
}

void LibCurlWrap::appendResult(std::string rply)
{
    _result += rply;
}

std::string LibCurlWrap::getXHTML(std::string url)
{
    curl_easy_setopt(_conn, CURLOPT_URL, url.c_str());
    curl_easy_perform(_conn);

    return _result;
}
