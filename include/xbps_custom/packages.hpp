#include <filesystem>

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
         * Updates void-packages and syncs it to local xbps database.
         */
        void update();

        /**
         * Checks for available updates.
         * @return True if updates are available, false otherwise.
         */
        bool check_updates();

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
