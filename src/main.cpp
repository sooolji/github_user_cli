#include "../include/activity_parser.h"
#include "../include/api_client.h"
#include <iostream>

int main(int argc, char *argv[]) {
  // 1. Validar que el usuario pase un argumento
  if (argc < 2) {
    std::cerr << "Usage: github-activity <username>" << std::endl;
    return 1;
  }

  std::string username = argv[1];
  GithubClient client;
  ActivityParser parser;

  // 2. Obtener el JSON de la API
  std::cout << "Fetching activity for " << username << "..." << std::endl;
  std::string rawJson = client.fetchUserActivity(username);

  // 3. Procesar e imprimir el resultado
  std::string result = parser.formatOutput(rawJson);
  std::cout << "\n--- Output: ---\n" << std::endl;
  std::cout << result << std::endl;

  return 0;
}