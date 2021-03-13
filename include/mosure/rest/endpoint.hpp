#pragma once

#include <mosure/inversify/meta.hpp>

#include <mosure/rest/meta.hpp>
#include <mosure/rest/method.hpp>
#include <mosure/rest/path.hpp>


namespace mosure::rest {

    template <
        Method Method_,
        Path Path_,
        MemFn F
    >
    struct Endpoint {
        constexpr static auto function = F.function;

        using value = Paths<Path_>;
    };

    // TODO: is this still used?
    template <typename T>
    using is_endpoint = mosure::inversify::meta::is_specialization<
        T,
        Endpoint
    >;
}
