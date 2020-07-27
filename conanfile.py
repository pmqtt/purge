
from conans import ConanFile, CMake,tools

class PurgeConan(ConanFile):
    name = "purge"
    version = "0.1"
    license = "Apache 2"
   
    url = "https://github.com/pmqtt/purge"
    #description = "<Description of Purge here>"
    #topics = ("<Put some tag here>", "<here>", "<and here>")
    #settings = "os", "compiler", "build_type", "arch"
    #options = {"shared": [True, False]}
    #default_options = {"shared": False}
    generators = "cmake"
    exports_sources = "include/*"
    def source(self):
        self.run("git clone https://github.com/pmqtt/purge.git")
        

    def build(self):
        cmake = CMake(self)
        # Explicit way:
        # self.run('cmake %s/hello %s'
        #          % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.hpp", dst="include", src="include")

    def package_info(self):
        self.cpp_info.libs = [""]

