#pragma once

#include <mosure/inversify/meta.hpp>

#include <mosure/rest/meta.hpp>
#include <mosure/rest/path.hpp>


namespace mosure::rest {

    template <typename... Args>
    struct Route {
        using value = Paths<Args::value...>;
    };

    // TODO: is this still used?
    template <typename T>
    using is_route = mosure::inversify::meta::is_specialization<
        T,
        Route
    >;

    // Specialization with base path
    template <
        Path Path_,
        typename... Args
    >
    struct Route<Path_, Args...> {
        using value = Paths<
            PathConcat<Path_, Args::value>...
        >;
    };

}
