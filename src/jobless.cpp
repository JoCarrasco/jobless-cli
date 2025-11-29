#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

int handle_command(const std::vector<std::string> &args);

int main(int argc, char *argv[]) {
  std::vector<std::string> args;
  for (int i = 1; i < argc; ++i) {
    args.push_back(argv[i]);
  }

  int status = handle_command(args);
  return status;
}

int handle_command(const std::vector<std::string> &args) {
  if (args.size() < 2) {
    std::cerr << "Error: Not enough arguments provided." << std::endl;
    return 1;
  }

  const std::string &main_command = args[0];
  const std::string &subcommand = args[1];


  return 0;
}


// NOTE(unused): When stable, integrate with other changes.
int add(const std::vector<std::string> &args) {
  // Here we have only several options to add.
  // Interactive and Single Line

  const std::string &companyName = args[0];

  const std::string &jobTitle = args[1];
  const std::string &jobDescription = args[2];
  const std::string &jobType = args[3];
  const std::string &jobUrl = args[4];
  
  
}
