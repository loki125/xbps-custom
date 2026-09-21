#include <string>
#include <filesystem>

namespace fs = std::filesystem;

namespace xbps_custom {
    namespace cli {
        /*
         * Parses the command line arguments and dispatches to the appropriate function.
         * @param argc The number of command line arguments.
         * @param argv The command line arguments.
         */
        void parse(int argc, char* argv[]);

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
    }
}
