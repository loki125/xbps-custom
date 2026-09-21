
#include <iostream>
#include <xbps_custom/cli.hpp>

int main(int argc, char* argv[]) {
    xbps_custom::Packages packages;
    packages.update();

    xbps_custom::cli::parse(packages, argc, argv);
    std::cout << "xbps-custom" << std::endl;

    return 0;
}
