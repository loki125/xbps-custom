
#include <iostream>
#include <xbps_custom/cli.hpp>

int main(int argc, char* argv[]) {
    // first we init/update void-packages.
    // then we check if the void-packages database is up to date with the local xbps database.
    // then we parse the command line arguments.
    std::cout << "xbps-custom" << std::endl;
    xbps_custom::cli::parse(argc, argv);
    return 0;
}
