# rest-server-inversify-cpp

[![Test Ubuntu](https://github.com/mosure/rest-server-inversify-cpp/workflows/ubuntu/badge.svg)](https://github.com/Mosure/rest-server-inversify-cpp/actions?query=workflow%3Aubuntu)
[![Test MacOS](https://github.com/mosure/rest-server-inversify-cpp/workflows/macos/badge.svg)](https://github.com/Mosure/rest-server-inversify-cpp/actions?query=workflow%3Amacos)
[![Test Windows](https://github.com/mosure/rest-server-inversify-cpp/workflows/windows/badge.svg)](https://github.com/Mosure/rest-server-inversify-cpp/actions?query=workflow%3Awindows)
[![GitHub License](https://img.shields.io/github/license/mosure/rest-server-inversify-cpp)](https://raw.githubusercontent.com/mosure/rest-server-inversify-cpp/main/LICENSE)
[![GitHub Last Commit](https://img.shields.io/github/last-commit/mosure/rest-server-inversify-cpp)](https://github.com/mosure/rest-server-inversify-cpp)
[![GitHub Issues](https://img.shields.io/github/issues/mosure/rest-server-inversify-cpp)](https://github.com/mosure/rest-server-inversify-cpp/issues)
[![Average time to resolve an issue](http://isitmaintained.com/badge/resolution/mosure/rest-server-inversify-cpp.svg)](http://isitmaintained.com/project/mosure/rest-server-inversify-cpp "Average time to resolve an issue")

C++20 REST server library

## Features
*   Cross platform (macOS, Ubuntu, Windows)
*   Coroutine support

## Documentation

## Integration

```cpp

#include <mosure/rest.hpp>

// for convenience
namespace rest = mosure::rest;

```

### Examples

#### Register a Middleware

```cpp

struct JsonMiddleware : rest::Middleware<> {
    JsonMiddleware(int foo, float bar) { }

    task<> process(rest::Context& ctx) override {
        co_return;
    }
};

inline static auto 
injectJsonMiddleware = inversify::Injectable<JsonMiddleware>::inject(
    symbols::foo,
    symbols::bar
);

```

#### Register Controllers

```cpp

struct FooController
    :
    rest::Controller<
        rest::Route<
            rest::BasePath<"/foo">,
            rest::Endpoint<rest::GET, "/", &GetFoo>,
            rest::Endpoint<rest::GET, "/bar", &GetBar>
        >,
        rest::PreMiddleware<
            JsonMiddleware
        >
    >
{
    FooController(int foo, float bar) : foo_(foo), bar_(bar) {  }

    task<rest::Response&> GetFoo(rest::Context& ctx) {
        return rest::status::code(201, foo);
    }

    task<rest::Response&> GetBar(rest::Context& ctx) {
        return rest::status::ok(bar_);
    }

    int foo_;
    float bar_;
};

template <>
struct inversify::Injectable<FooController>
    : inversify::Inject<
        symbols::foo,
        symbols::bar
    >
{ };

```

#### Create a Server

```cpp

rest::Server<BeastServer> server;

server.run("127.0.0.1", 5050);

```

## Running tests
`bazel run test`
