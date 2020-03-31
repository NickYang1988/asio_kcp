# Install & Compiling

[kcp](https://github.com/skywind3000/kcp) is a A Fast and Reliable ARQ Protocol (Can use at UDP).

This project wrap kcp by boost asio. Making it easy to use.
And it's a bench test for kcp also.

## Compiling

### Prerequisites

boost 1.72.0+ (_We like using the newest boost version._)

```bash
# OSX
brew install boost
# OR
# Linux
# download the source code and compiling yourself
```

```bash
git clone -b xd https://github.com/NickYang1988/asio_kcp.git
git submodule update --init
mkdir cmake_build/debug && cd cmake_build/debug
cmake -DCMAKE_BUILD_TYPE=debug ../../
make -j8
```

-----

## The original help

## ddd安装

https://www.gnu.org/software/ddd/
or
brew install Caskroom/cask/xquartz
brew install ddd
导入证书:  http://blog.plotcup.com/a/129

## 调试命令

 a. 打日志, 过滤掉timer的日志
    ./asio_kcp_server/asio_kcp_server 0.0.0.0 12345 2>&1 | grep --line-buffered -v -e deadline_timer -e "ec=system:0$" -e "|$" >>bserver.txt
 b. 过滤掉asio日志
    ./asio_kcp_client/asio_kcp_client 120.26.200.117 23457 500 2>/dev/null