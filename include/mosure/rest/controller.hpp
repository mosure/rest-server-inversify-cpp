#pragma once

#include <mosure/inversify/meta.hpp>

#include <mosure/rest/endpoint.hpp>
#include <mosure/rest/meta.hpp>
#include <mosure/rest/path.hpp>
#include <mosure/rest/route.hpp>


namespace mosure::rest {

    template <
        typename Derived,
        template <typename...> typename Routes,
        typename... RouteArgs,
        template <typename...> typename Middlewares,
        typename... MiddlewareArgs
    >
    struct Controller {
        
    };

    template <typename... Args>
    struct Controller {
        // TODO: Base path should always come first
        using base_path = meta::filter_t<
            is_base_path,
            Args...
        >;

        using endpoints = meta::filter_t<is_endpoint, Args...>;
        using routes = meta::filter_t<is_route, Args...>;

    };
}
