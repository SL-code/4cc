#include <nobuild.hpp>

static std::string projectName = "template";
static fs::path buildDir = "build";

static std::vector<std::string>
platform_layer = 
{

};

static std::vector<fs::path> 
source_files =
{
    fs::path(".") / "code" / "main.cpp",
};

static std::vector<std::string> 
include_directories =
{
    "-Icode",
};

static std::vector<std::string> 
libraries =
{

};

static std::vector<std::string> 
libraries_directories =
{

};

int main(int argc, char** argv)
{
    isVerboseEnabled = is_in_argv("-v", argc, argv);
    isVeryVerboseEnabled = is_in_argv("-vv", argc, argv);
    GO_REBUILD_URSELF(argv[0]); 
    std::string buildType = "debug";
    std::string buildTypeDef = "-DDEBUG";
    get_build_type_and_def(buildType, buildTypeDef, argc, argv);
    VINFO("buildType: %s ", buildType.c_str());
    VINFO("buildTypeDef: %s ", buildTypeDef.c_str());
    fs::path buildPath  = buildDir / buildType;
    fs::path binaryPath = buildPath / projectName;
    INFO("buildPath: %s ", buildPath.c_str());
    INFO("binaryPath: %s ", binaryPath.c_str());

    // Should we generate the build directory
    if(!fs::exists(buildPath))
    {
        fs::create_directory(buildDir);
        fs::create_directory(buildPath);
        VINFO("Created: %s ", buildDir.c_str());
        VINFO("Created: %s ", buildPath.c_str());
    }

    // do we run or build the program
    if(is_in_argv("run", argc, argv))
    {
        INFO("Executing: %s ", binaryPath.c_str());
        system(binaryPath.c_str());
    }
    else
    {
        std::vector<std::string> build_args;
        if (std::string(buildType) == "debug")
        {
            build_args = debug_options;
        }
        else if (std::string(buildType) == "release")
        {
            build_args = release_options;
        }
        else if (std::string(buildType) == "dist")
        {
            build_args = dist_options;
        }

        std::string build_command = compiler;
        concatenate_build_command(build_command, build_args, source_files, include_directories, libraries, libraries_directories, buildTypeDef, binaryPath);

        INFO("Executing: %s", build_command.c_str());
        system(build_command.c_str());
    }

    return 0;
}
