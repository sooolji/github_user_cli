#ifndef API_CLIENT_H
#define API_CLIENT_H

#include <curl/curl.h>
#include <string>

// class to fetch data from github api

#include <string>
class GithubClient {
private:
  const std::string baseUrl = "https://api.github.com/users/";

public:
  GithubClient() = default;
  ~GithubClient() = default;
  std::string fetchUserActivity(const std::string &username);
};

#endif