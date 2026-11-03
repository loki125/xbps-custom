#include <stdexcept>
#include <vector>
#include <string>
#include <utility>
#include <functional>
#include <type_traits>

#include "commands.hpp"


namespace xbps_custom {
    namespace commands {

        /*
         * struct for keeping data on the cli commands
         */
        struct Command {
            std::string description;
            std::string usage;
            std::function<void(const std::vector<std::string>&)> execute;
        };

        // 1. Helper that unpacks vector elements into the function's arguments
        template <typename Func, typename... Args, std::size_t... Is>
        void invoke_helper(Func func, const std::vector<std::string>& args, std::index_sequence<Is...>) {
            // std::decay_t strips 'const' and '&', so it constructs T from args[Is]
            func(std::decay_t<Args>{args[Is]}...);
        }

        // 2. ONE single template that handles ANY number of arguments
        template <typename... Args>
        Command make_cmd(std::string desc, std::string usage, void(*func)(Args...)) {
            return Command{
                std::move(desc),
                std::move(usage),
                [func](const std::vector<std::string>& args) {
                    constexpr std::size_t expected_args = sizeof...(Args);

                    if (args.size() < expected_args) {
                        throw std::runtime_error(
                            "Expected " + std::to_string(expected_args) +
                            " arguments, but got " + std::to_string(args.size())
                        );
                    }

                    // Generate compile-time index sequence: 0, 1, 2, ... N
                    invoke_helper<decltype(func), Args...>(
                        func, args, std::index_sequence_for<Args...>{}
                    );
                }
            };
        }

        const std::unordered_map<std::string, Command> registry = {
            {"list",    make_cmd("List custom packages", "", list_packages)},

            {"new",     make_cmd("Create package skeleton", "<pkgname>", new_package)},
            {"build",   make_cmd("Build with xbps-src",     "<pkgname>", build_package)},
            {"install", make_cmd("Install package",         "<pkgname>", install_package)},
            {"remove",  make_cmd("Remove package",          "<pkgname>", remove_package)},
            {"connect", make_cmd("Connect to void-packages","<path>",    connect_void_packages)},

            {"update",  make_cmd("Update version",          "<pkgname> <version>", update_package)},
            {"create",  make_cmd("Create template",         "<pkgname> <url>",     create_template)},
            {"insert",  make_cmd("Insert files",            "<pkgname> <dir>",     insert_files)},
        }; /// string to func table for the cli commands
    }
}
