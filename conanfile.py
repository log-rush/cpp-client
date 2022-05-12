from conans import ConanFile, CMake, tools
from conans.errors import ConanInvalidConfiguration
import os

from importlib_metadata import requires

class LogRushConan(ConanFile):
    name = "logrush"
    description = "C++ LogRush Client"
    homepage = "https://github.com/logrush/cpp-client"
    license = "MIT"
    topics = ("LogRush", "Logging", "Logs", "Remote")
    url = "https://github.com/conan-io/conan-center-index"
    generators = "cmake", "cmake_find_package"
    settings = "os", "arch", "compiler", "build_type"
    exports_sources = "*"
    version = "1.0.0"
    requires = "libcurl/7.82.0"

    cmake = None

    def _configure_cmake(self):
        if self.cmake:
            return self.cmake
        self.cmake = CMake(self)
        self.cmake.configure(source_folder="./")

    def config_options(self):
        pass

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="./")
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.configure(source_folder="./")
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["logrush"]

