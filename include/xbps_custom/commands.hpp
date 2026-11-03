#pragma once

#include <string>
#include <filesystem>


#include <xbps_custom/packages.hpp>

namespace fs = std::filesystem;

namespace xbps_custom {
    namespace commands {

        /*
         * Parses the command line arguments and dispatches to the appropriate function.
         * @param packages The packages to use for parsing.
         * @param argc The number of command line arguments.
         * @param argv The command line arguments.
         */
        void parse(Packages packages, int argc, char* argv[]);

        /*
         * Creates a new package with the given name and a template skeleton.
         * @param pkgname The name of the package to create.
         */
        void new_package(const std::string& pkgname);

        /*
         * Edits the template for the given package with the given editor, default editor is nano.
         * @param pkgname The name of the package to edit.
         * @param editor The editor to use for editing the template.
         */
        void edit_template(const std::string& pkgname, const std::string& editor="");

        /*
         * Inserts files from the given directory into the packages /files.
         * @param pkgname The name of the package to insert files into.
         * @param files_dir The directory containing the files to insert.
         */
        void insert_files(const std::string& pkgname, const fs::path& files_dir);

        /*
         * Builds the package with the given name using xbps-src.
         * @param pkgname The name of the package to build.
         */
        void build_package(const std::string& pkgname);

        /*
         * Installs the package with the given name using xbps-install.
         * @param pkgname The name of the package to install.
         */
        void install_package(const std::string& pkgname);

        /*
         * Removes the package with the given name using xbps-remove.
         * @param pkgname The name of the package to remove.
         */
        void remove_package(const std::string& pkgname);

        /*
         * Lists all custom packages created by xbps-custom.
         */
        void list_packages();

        /*
         * Creates a template for a package and download link using file extation reverse engineering.
         * @param pkgname The name of the package to create a template for.
         * @param download_link The download link for the package.
         */
        void create_template(const std::string& pkgname, const std::string& download_link);

        /*
         * Updates the package with the given name to the specified version.
         * @param pkgname The name of the package to update.
         * @param version The version to update the package to.
         */
        void update_package(const std::string& pkgname, const std::string& version);

        /*
         * Connects to an existing local void-packages repository at the given path.
         * @param void_packages_path The path to the void-packages repository.
         */
        void connect_void_packages(const fs::path& void_packages_path);

    }
}
