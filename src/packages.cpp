#include <xbps_custom/packages.hpp>

namespace xbps_custom {
    Packages::Packages() : m_void_packages_dir(VOID_PKGS_DIR)
    {}

    Packages::~Packages()
    {}

    void Packages::update_void_packages()
    {

    }

    fs::path Packages:: install_void_packages()
    {
        return fs::path();
    }

    void Packages::sync_local_packages()
    {

    }
}
