#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>

int handle_command(const std::vector<std::string> &args);

int main(int argc, char *argv[]) {
  std::vector<std::string> args;

  for (int i = 1; i < argc; ++i) {
    args.push_back(argv[i]);
  }

  if (!args.empty() && args[0] == "--help") {
    show_help();
    return 0;
  }

  if (args.size() >= 2 && args[1] == "--help") {
    show_help(args[0]);
    return 0;
  }
  int status = handle_command(args);

  return status;
}

int handle_command(const std::vector<std::string> &args) {
  if (args.size() < 2) {
    std::cerr << "Error: Not enough arguments provided." << std::endl;
    show_help();
    return 1;
  }

  const std::string &main_command = args[0];
  const std::string &subcommand = args[1];

  return 0;
}
