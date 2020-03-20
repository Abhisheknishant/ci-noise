#!/bin/sh -x

case "${TRAVIS_COMPILER}" in
  gcc-*)
    compiler_version="${TRAVIS_COMPILER#gcc-*}"

    apt-cache show "${TRAVIS_COMPILER}" >/dev/null 2>/dev/null
    if [ $? -eq 0 ]; then
      sudo apt-get install -y {gcc,c++}-${compiler_version}
    fi

    sudo add-apt-repository -y 'ppa:ubuntu-toolchain-r/test'
    sudo apt-get install -y gcc-${compiler_version} g++-${compiler_version}

    if [ $? -ne 0 ]; then
      echo "Unable to install compiler: ${TRAVIS_COMPILER}" >&2
      exit 1
    fi

    CC="gcc-${compiler_version}"
    CXX="g++-${compiler_version}"

    ;;

  clang-*)
    compiler_version="${TRAVIS_COMPILER#clang-*}"

    apt-cache show "${TRAVIS_COMPILER}" >/dev/null 2>/dev/null
    if [ $? -eq 0 ]; then
      sudo apt-get install -y clang-${compiler_version}
    fi

    sudo apt-key adv --fetch-keys "https://apt.llvm.org/llvm-snapshot.gpg.key"
    sudo add-apt-repository -y "deb http://apt.llvm.org/${TRAVIS_DIST}/ llvm-toolchain-${TRAVIS_DIST}-${compiler_version} main"
    sudo apt-get install -y clang-${compiler_version}

    if [ $? -ne 0 ]; then
      echo "Unable to install compiler: ${TRAVIS_COMPILER}" >&2
      exit 1
    fi

    CC="clang-${compiler_version}"
    CXX="clang++-${compiler_version}"

    ;;
esac

echo "#!/bin/sh" > ~/.ci-compiler-config.sh
echo "CC=\"${CC}\"" >> ~/.ci-compiler-config.sh
echo "CXX=\"${CXX}\"" >> ~/.ci-compiler-config.sh
chmod 0755 ~/.ci-compiler-config.sh