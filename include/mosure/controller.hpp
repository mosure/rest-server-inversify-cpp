#pragma once

#include <mosure/request>
#include <mosure/routes>


template <
    typename Derived,
    template <typename...> typename Routes,
    typename... RouteArgs,
    template <typename...> typename Middlewares,
    typename... MiddlewareArgs
>
struct Controller {
    
};
