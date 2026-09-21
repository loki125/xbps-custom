
#include <iostream>
#include <xbps-custom/cli.hpp>

int main(int argc, char* argv[]) {
    std::cout << "xbps-custom" << std::endl;
    xbps_custom::cli::parse(argc, argv);
    return 0;
}
