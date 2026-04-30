#include "../include/activity_parser.h"
#include "../include/api_client.h"
#include <iostream>

int main(int argc, char *argv[]) {
    //valid user argument?
  if (argc < 2) {
    std::cerr << "Usage: github-activity <username>" << std::endl;
    return 1;
  }

  std::string username = argv[1];
  GithubClient client;
  ActivityParser parser;

  // json
  std::cout << "Fetching activity for " << username << "..." << std::endl;
  std::string rawJson = client.fetchUserActivity(username);

  // process and print result
  std::string result = parser.formatOutput(rawJson);
  std::cout << "\n--- Output: ---\n" << std::endl;
  std::cout << result << std::endl;

  return 0;
}
