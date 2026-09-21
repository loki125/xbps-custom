#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;

inline const char* safe_getenv(const char* key, const char* default_value = "") {
    const char* env = std::getenv(key);
    return (env != nullptr) ? env : default_value;
}

namespace xbps_custom
{
    const fs::path VOID_PKGS_DIR = safe_getenv("VOID_PKGS_DIR", "/var/lib/xbps-custom/void-packages");

}
