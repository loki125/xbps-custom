#pragma once

#include <filesystem>

#include <xbps_custom/utils.hpp>

namespace fs = std::filesystem;

namespace xbps_custom {

    /*
     * Responsible for managing void-packages and syncing it to the local xbps database.
     */
    class Packages {
    public:
        Packages();
        ~Packages();

        /**
         * Updates void-packages's git repository.
         */
        void update_void_packages();

        /**
         * Installs repo void-packages.
         * @return Path to the installed void-packages directory.
         */
        fs::path install_void_packages();

        /**
         * Syncs .xbps packages from local database to void-packages.
         */
        void sync_local_packages();

    private:
        fs::path m_void_packages_dir;
    };
}
