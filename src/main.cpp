
#include <iostream>
#include <xbps_custom/commands.hpp>

int main(int argc, char* argv[]) {
    xbps_custom::Packages packages;
    packages.update_void_packages();

    xbps_custom::commands::parse(packages, argc, argv);
    std::cout << "xbps-custom" << std::endl;

    return 0;
}
