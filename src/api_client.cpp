#include "../include/api_client.h"
#include <iostream>

// every new piece of date added to the string
static size_t
WriteCallback(void *contents, size_t size, size_t nmemb,
              std::string *userp) { // void* is a generic pointer from c
  size_t totalSize = size * nmemb;
  try {
    userp->append(static_cast<const char *>(
                      contents), // append is more efficient that looping and
                                 // pushing_back each char. also im type casting
                                 // into char* because contents is a void* and
                                 // append takes a char*
                  totalSize);
  } catch (std::bad_alloc &e) { // if the string can't allocate more memory
                                // (ram), it throws an exception
    return 0;                   // memory error
  }

  return totalSize;
}

std::string GithubClient::fetchUserActivity(const std::string &username) {

  CURL *curl;
  CURLcode res;
  std::string readBuffer; // json goes here
  long httpCode = 0;

  curl = curl_easy_init();
  if (curl) {
    const std::string url = baseUrl + username + "/events";

    // 1. config url
    curl_easy_setopt(curl, CURLOPT_URL,
                     url.c_str()); //.c_str() get a "c-style" version of a c++
                                   // std::string because libcurl is a c library

    // 2. github require user-agent else 403
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "github-cli-app");

    // 3. config callback
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    // 4. get
    res = curl_easy_perform(curl);

    // 5. network errors
    if (res != CURLE_OK) {
      // cerr -> standard Error
      std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res)
                << std::endl;
    }

    // 6. code status
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

    if (httpCode != 200) {
      std::cerr << "Error  " << httpCode << std::endl;
      if (httpCode == 404)
        std::cerr << "User not found." << std::endl;
      curl_easy_cleanup(curl);
      return "";
    }

    // 7. always cleanup
    curl_easy_cleanup(curl);
  }

  return readBuffer; // 8. return raw json
}