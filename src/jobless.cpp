#include <iostream>
#include <string>
#include <vector>

// Forward declarations
void show_help (const std::string& command = "");
// Forward declaration f the main command handler function
int handle_command(const std::vector<std::string>& args);

void show_help (const std::string& command) {
	if (command == "new") {
	std::cout << "Usage: jobless new <subcommand> [options]\n";
        std::cout << "\n";
        std::cout << "Subcommands for 'new':\n";
        std::cout << "  jobsearch     Initializes a new job search tracking session.\n";
        std::cout << "\n";
        std::cout << "Options for 'new jobsearch':\n";
        std::cout << "  --with-job    Flag indicating the search is being conducted while currently employed.\n";
        std::cout << "                This changes the initial tracking status.\n";		
	} else {
		 // Default (main) help message
        std::cout << "Jobless CLI - Job Application Tracker\n";
        std::cout << "=====================================\n";
        std::cout << "\n";
        std::cout << "Usage: jobless <command> [subcommand] [options]\n";
        std::cout << "\n";
        std::cout << "Available Commands:\n";
        std::cout << "  new           Start a new session or resource. (e.g., 'jobless new jobsearch')\n";
        std::cout << "  --help        Show general help or help for a specific command (e.g., 'jobless new --help').\n";
        std::cout << "\n";
        std::cout << "For specific command help, use: jobless <command> --help\n";

	}

}

int main(int argc, char* argv[]) {
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

int handle_command(const std::vector<std::string>& args) {
	if (args.size() < 2) {
		std::cerr << "Error: Not enough arguments provided." << std::endl;
		show_help();
		return 1;
	}

	const std::string& main_command = args[0];
	const std::string& subcommand = args[1];

	return 0;
}	

