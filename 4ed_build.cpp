/* ls.gl - 2023
4coder development build rule. */

// TOP

#include <cstdarg>
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__linux__)
#include <libgen.h>         // dirname
#include <unistd.h>         // readlink
#include <linux/limits.h>   // PATH_MAX
#endif

#define function static
#define internal static
bool isVerboseEnabled = false;
bool isVeryVerboseEnabled = false;

namespace fs = std::filesystem;

// Debug utilities
bool is_in_argv(std::string str, int argc, char** argv);
void VLOG(FILE *stream, const char* tag, const char* fmt, va_list args);
void VVLOG(FILE *stream, const char* tag, const char* fmt, va_list args);
void VINFO(const char* fmt, ...);
void WARN(const char* fmt, ...);
void VWARN(const char* fmt, ...);
void ERROR(const char* fmt, ...);
void VERROR(const char* fmt, ...);
void PANIC(const char* fmt, ...);
void VPANIC(const char* fmt, ...);

// Build utilities
void standard_build(const std::string build_type);

int main(int argc, char **argv)
{
    isVerboseEnabled = is_in_argv("-v", argc, argv);

    const char* build_type = "dist";
    if (is_in_argv("debug", argc, argv))
    {
        build_type = "debug";
    }
    else if (is_in_argv("release", argc, argv))
    {
        build_type = "release";
    }
    else if (is_in_argv("dist", argc, argv))
    {
        build_type = "dist";
    }

    if(!fs::exists(BUILD_DIR))
    {
        fs::create_directory(BUILD_DIR);
        INFO("Created: %s ", BUILD_DIR);
    }

    std::string build_path = BUILD_DIR PATH_SEPARATOR;
    build_path += build_type;
    if (!fs::exists(build_path))
    {
        fs::create_directory(build_path);
        INFO("Created: %s ", build_path.c_str());
    }

    standard_build(build_type);

    //#elif defined(PACKAGE_DEMO_X64)
    //    package(&arena, cdir, Tier_Demo, Arch_X64);
    //
    //#elif defined(PACKAGE_DEMO_X86)
    //    package(&arena, cdir, Tier_Demo, Arch_X86);
    //
    //#elif defined(PACKAGE_SUPER_X64)
    //    package(&arena, cdir, Tier_Super, Arch_X64);
    //
    //#elif defined(PACKAGE_SUPER_X86)
    //    package(&arena, cdir, Tier_Super, Arch_X86);
    //
    //#else
    //# error No build type specified.
    //#endif

    //return(error_state);
}
bool is_in_argv(std::string str, int argc, char** argv)
{
    bool isIn = false;
    for(int i = 0; i < argc; ++i)
    {
        if(std::string(argv[i]) == str)
        {
            isIn = true;
            break;
        }
    }

    return isIn;
}


void VLOG(FILE *stream, const char* tag, const char* fmt, va_list args)
{
    if(isVerboseEnabled || isVeryVerboseEnabled)
    {
        fprintf(stream, "[%s] ", tag);
        vfprintf(stream, fmt, args);
        fprintf(stream, "\n");
    }
}

void VVLOG(FILE *stream, const char* tag, const char* fmt, va_list args)
{
    if(isVeryVerboseEnabled)
    {
        fprintf(stream, "[%s] ", tag);
        vfprintf(stream, fmt, args);
        fprintf(stream, "\n");
    }
}

void INFO(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    VLOG(stderr, "INFO", fmt, args);
    va_end(args);
}

void VINFO(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    VVLOG(stderr, "INFO", fmt, args);
    va_end(args);
}

void WARN(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    VLOG(stderr, "WARN", fmt, args);
    va_end(args);
}

void VWARN(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    VVLOG(stderr, "WARN", fmt, args);
    va_end(args);
}

void ERROR(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    VLOG(stderr, "ERROR", fmt, args);
    va_end(args);
}

void VERROR(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    VVLOG(stderr, "ERROR", fmt, args);
    va_end(args);
}

void PANIC(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    VLOG(stderr, "PANIC", fmt, args);
    va_end(args);
    exit(1);
}

void VPANIC(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    VVLOG(stderr, "PANIC", fmt, args);
    va_end(args);
    exit(1);
}

//void concatenate_build_command(std::string& build_command,
//                               const std::vector<std::string>& build_args,
//                               const std::vector<fs::path>& source_files,
//                               const std::vector<std::string>& include_directories,
//                               const std::vector<std::string>& libraries,
//                               const std::vector<std::string>& libraries_directories,
//                               const std::string& buildTypeDef,
//                               const fs::path& binaryPath)
//{
//    build_command += " ";
//    for (size_t i = 0; i < build_args.size(); i++)
//    {
//        build_command += build_args[i];
//        build_command += " ";
//        VINFO("Appended argument %s to the build command", build_args[i].c_str());
//    }
//
//    for (size_t i = 0; i < source_files.size(); i++)
//    {
//        build_command += source_files[i].string();
//        build_command += " ";
//        VINFO("Appended source %s to the build command", source_files[i].c_str());
//    }
//
//    for (size_t i = 0; i < include_directories.size(); i++)
//    {
//        build_command += include_directories[i];
//        build_command += " ";
//        VINFO("Appended include directory %s to the build command", include_directories[i].c_str());
//    }
//
//    for (size_t i = 0; i < libraries.size(); i++)
//    {
//        build_command += libraries[i];
//        build_command += " ";
//        VINFO("Appended libraries %s to the build command", libraries[i].c_str());
//    }
//
//    for (size_t i = 0; i < libraries_directories.size(); i++)
//    {
//        build_command += libraries_directories[i];
//        build_command += " ";
//        VINFO("Appended libraries directories %s to the build command", libraries_directories[i].c_str());
//    }
//
//    build_command += (buildTypeDef);
//    build_command += " -o ";
//    build_command += (binaryPath.string());
//}

#if defined(_WIN32) || defined(_WIN64)
#define PATH_SEPARATOR "\\"
#else
#define PATH_SEPARATOR "/"
#endif

// DETERMINE COMPILER
#if defined(_WIN32) || defined(_WIN64)
#pragam message("This should be a check to determine if we compile with microsoft's compiler not if we are cmompiling for windows");
#define compiler "cl"

#undef  debug_flags
#define debug_flags\
" -Zi"\
" -DDO_CRAZY_EXPENSIVE_ASSERTS"\

#undef  release_flags
#define release_flags\
" -O2"\

#undef  dist_flags
#define dist_flags\
" ..\\non-source\\res\\icon.res"
" "

#undef  analyze_flags
#define analyze_flags " "

#undef  warning_flags
#define warning_flags\
" -W4"\
" -wd4310"\
" -wd4100"\
" -wd4201"\
" -wd4505"\
" -wd4996"\
" -wd4127"\
" -wd4510"\
" -wd4512"\
" -wd4610"\
" -wd4390"\
" -wd4611"\
" -wd4189"\
" -WX"\

#undef  compile_flags
#define compile_flags\
" -GR-"\
" -EHa-"\
" -nologo"\
" -FC"\

#undef  common_libraries
#define common_libraries\
" user32.lib"\
" winmm.lib"\
" gdi32.lib"\
" opengl32.lib"\
" comdlg32.lib"\
" userenv.lib"\

#define CL_ICON "..\\non-source\\res\\icon.res"

#if defined(_WIN64)
#undef  libraries
#define libraries\
common_libraries
" " FOREIGN_WIN "\\x64\\freetype.lib"

#define x64_flags\
" -DFTECH_64_BIT"\

#define arch_specific_flags\
x64_flags\
CL_ICON

#elif defined(_WIN32)
#undef  libraries
#define libraries\
common_libraries
" " FOREIGN_WIN "\\x86\\freetype.lib"

#define x32_flags\
" -DFTECH_32_BIT"\


#define arch_specific_flags\
x32_flags\
CL_ICON

#endif

#undef  debug_build_flags\
#define debug_build_flags\
compile_flags\
debug_flags\
analyze_flags\
warning_flags\


#undef  release_build_flags\
#define release_build_flags\
compile_flags\
release_flags\
debug_flags\
analyze_flags\
warning_flags\


#undef  dist_build_flags\
#define dist_build_flags\
compile_flags\
dist_flags\
analyze_flags\
warning_flags\


#define debug_build_command\
compiler\
debug_build_flags\
libraries\
arch_specific_flags\

#define release_build_command\
compiler\
release_build_flags\
libraries\
arch_specific_flags\

#define dist_build_command\
compiler\
dist_build_flags\
libraries\
arch_specific_flags\


#elif defined(__GNUG__)
#define compiler "g++"

#undef  compile_flags
#define compile_flags\
" -std=c++11"\
" -D_GNU_SOURCE"\
" -fPIC"\
" -fno-threadsafe-statics"\

///" -pthread"\


#undef  debug_flags
#define debug_flags\
" -ggdb -g3 -fno-eliminate-unused-debug-symbols -fvar-tracking -fno-eliminate-unused-debug-types"\


#undef  release_flags
#define release_flags\
" -Og"\


#undef  dist_flags
#define dist_flags\
" -O3"\


#undef  analyze_flags
#define analyze_flags\
" -fanalyzer -Wanalyzer-too-complex"\


#undef  warning_flags
#define warning_flags\
" -Wall -Weffc++ -pedantic -Wextra -Wcast-align -Wcast-qual -Wconversion -Wdisabled-optimization"\
" -Wfloat-equal -Wformat=2 -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wimport -Winit-self"\
" -Winline -Winvalid-pch -Wlong-long -Wctor-dtor-privacy -Wlogical-op -Wmissing-declarations"\
" -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel"\
" -Wstrict-overflow=5 -Wundef -Wno-unused -Wmissing-field-initializers -Wmissing-format-attribute"\
" -Wmissing-include-dirs -Wmissing-noreturn -Wpacked -Wpadded -Wpointer-arith -Wredundant-decls"\
" -Wshadow -Wstack-protector -Wstrict-aliasing=2 -Wswitch-default -Wswitch-enum -Wunreachable-code"\
" -Wunused -Wunused-parameter -Wvariadic-macros -Wno-write-strings -Wno-unused-result"\


#undef  common_libraries
#define common_libraries\
" -lX11 -lpthread -lm -lrt -lGL"\
" -ldl -lXfixes -lfreetype  "\


#undef  libraries
#define libraries\
common_libraries\

#if __x86_64__ || __ppc64__
#define x64_flags\
" -m64 -DFTECH_64_BIT"\

#define arch_specific_flags\
x64_flags\

#else
#define x32_flags\
" -m32 -DFTECH_32_BIT"\

#define arch_specific_flags\
x32_flags\

#endif

#define SHIP_MODE_DEFINE " -DSHIP_MODE"
#define FRED_SUPERL_DEFINE " -DFRED_SUPER"
#define FRED_INTERNAL_DEFINE " -DFRED_INTERNAL"

#define debug_build_binary_command\
compiler\
compile_flags\
" -Wno-write-strings"\
debug_flags\
analyze_flags\
warning_flags\
libraries\
arch_specific_flags\
FRED_INTERNAL_DEFINE\
FRED_SUPERL_DEFINE\


#define release_build_binary_command\
compiler\
compile_flags\
" -Wno-write-strings"\
release_flags\
debug_flags\
analyze_flags\
warning_flags\
libraries\
arch_specific_flags\
FRED_SUPERL_DEFINE\


#define dist_build_binary_command\
compiler\
compile_flags\
" -Wno-write-strings"\
dist_flags\
libraries\
arch_specific_flags\
FRED_SUPERL_DEFINE\


#define shared_flag " -shared"

#define debug_build_shared_command\
debug_build_binary_command\
shared_flag\

#define release_build_shared_command\
release_build_binary_command\
shared_flag\

#define dist_build_shared_command\
dist_build_binary_command\
shared_flag\

#elif defined(__clang__) && defined(__APPLE__)
#define compiler "clang++"

# define CLANG_OPTS \
"-Wno-write-strings -Wno-deprecated-declarations " \
"-Wno-comment -Wno-switch -Wno-null-dereference " \
"-Wno-tautological-compare -Wno-unused-result " \
"-Wno-missing-declarations -Wno-nullability-completeness " \
"-std=c++11 "

#define compile_flags CLANG_OPTS


#define CLANG_LIBS_COMMON \
"-framework Cocoa -framework QuartzCore " \
"-framework CoreServices " \
"-framework OpenGL -framework IOKit -framework Metal -framework MetalKit "

#define CLANG_LIBS_X64 CLANG_LIBS_COMMON \
FOREIGN "/x64/libfreetype-mac.a"

#define CLANG_LIBS_X86 CLANG_LIBS_COMMON \
FOREIGN "/x86/libfreetype-mac.a"

#if __x86_64__ || __ppc64__
#define libraries  CLANG_LIBS_X64
#else
#define libraries  CLANG_LIBS_X86
#endif

#undef  debug_flags
#define debug_flags\
" -ggdb"\
" -g3"\
" -fno-eliminate-unused-debug-symbols"\
" -fvar-tracking"\
" -fno-eliminate-unused-debug-types"\


#undef  release_flags
#define release_flags\
" -Og"\


#undef  dist_flags
#define dist_flags\
" -O3"\


#undef  analyze_flags
#define analyze_flags\
" -fanalyzer"\
" -Wanalyzer-too-complex"\


#undef  warning_flags
#define warning_flags\
" -Weverything"\

#if __x86_64__ || __ppc64__
#define x64_flags\
" -m64"\
" -DFTECH_64_BIT"\

#define arch_specific_flags\
x64_flags\

#else
#define x32_flags\
" -m32"\
" -DFTECH_32_BIT"\

#define arch_specific_flags\
x32_flags\

#endif

#define debug_build_binary_command\
compiler\
CLANG_OPTS\
compile_flags\
debug_flags\
analyze_flags\
warning_flags\
libraries\
arch_specific_flags\

#define release_build_binary_command\
compiler\
CLANG_OPTS\
compile_flags\
release_flags\
debug_flags\
analyze_flags\
warning_flags\
libraries\
arch_specific_flags\

#define dist_build_binary_command\
compiler\
CLANG_OPTS\
compile_flags\
dist_flags\
libraries\
arch_specific_flags\

#define shared_flag " -shared"
#define SHIP_MODE_DEFINE " -DSHIP_MODE"
#define FRED_SUPERL_DEFINE " -DFRED_SUPER"
#define FRED_INTERNAL_DEFINE " -DFRED_INTERNAL"

#define debug_build_shared_command\
debug_build_binary_command\
shared_flag

#define release_build_shared_command\
release_build_binary_command\
shared_flag

#define dist_build_shared_command\
dist_build_binary_command\
shared_flag

#endif


#if defined(_WIN32) || defined(_WIN64)
#define DLL ".dll"
#else
#define DLL ".so"
#endif


//
// Universal directories
//

#define BUILD_DIR   "build"
#define CODE_PATH   "code"
#define CUSTOM_PATH CODE_PATH PATH_SEPARATOR "custom"

#define PACK_DIR  "non-source" PATH_SEPARATOR "distributions"
#define SITE_DIR  "non-source" PATH_SEPARATOR "site"

#define FOREIGN   "non-source" PATH_SEPARATOR "foreign"
#define FREETYPE2 FOREIGN PATH_SEPARATOR "freetype2"


#define SHARED_FILE "4ed_app_target.cpp"
#define SHARED_NAME "4ed_app" DLL

//
// Platform layer file tables
//

#if defined(_WIN32) || defined(_WIN64)
#define PLATFORM_LAYER CODE_PATH PATH_SEPARATOR "platform_win32" PATH_SEPARATOR "win32_4ed.cpp";
#elif defined(__linux__)
#define PLATFORM_LAYER CODE_PATH PATH_SEPARATOR "platform_linux" PATH_SEPARATOR "linux_4ed.cpp";
#else //MAC
#define PLATFORM_LAYER CODE_PATH PATH_SEPARATOR "platform_mac"   PATH_SEPARATOR "mac_4ed.mm";
#endif

#define BINARY_FILE PLATFORM_LAYER
#define BINARY_NAME "4ed"
//char** exports     = {"app_get_functions", 0};

//-Icode -Icode/custom -Inon-source/foreign/freetype2
const char* includes[] = { CUSTOM_PATH, FREETYPE2, 0, };
const char* defines[] = { FRED_INTERNAL_DEFINE, 0, };
const char* default_custom_target = CUSTOM_PATH PATH_SEPARATOR "4coder_default_bindings.cpp";


internal void
buildsuper(std::string build_type)
{
    std::string build_super_command =
#if defined(_WIN32)
    CUSTOM_PATH PATH_SEPARATOR "bin" PATH_SEPARATOR "buildsuper_x86-win.bat";
#elif defined(_WIN64)
    CUSTOM_PATH PATH_SEPARATOR "bin" PATH_SEPARATOR "buildsuper_x64-win.bat";
#elif defined(__linux__)
#if __x86_64__ || __ppc64__
    CUSTOM_PATH PATH_SEPARATOR "bin" PATH_SEPARATOR "buildsuper_x64-linux.sh";
#else
    CUSTOM_PATH PATH_SEPARATOR "bin" PATH_SEPARATOR "buildsuper_x32-linux.sh";
#endif
#elif defined(__APPLE__)
#if __x86_64__ || __ppc64__
    CUSTOM_PATH PATH_SEPARATOR "bin" PATH_SEPARATOR "buildsuper_x64-mac.sh";
#else
    CUSTOM_PATH PATH_SEPARATOR "bin" PATH_SEPARATOR "buildsuper_x32-mac.sh";
#endif
#endif

    //char *build_command = fm_str(arena, "\"", cdir, "/", build_script, "\" \"", file, "\"");
    //if (This_OS == Platform_Windows){
    //  build_command = fm_str(arena, "call ", build_command);
    //}
    system(build_super_command.c_str());
}

void build_main(bool update_local_theme, const std::string build_type)
{

    std::string build_shared_command;
    std::string build_binary_command;

    if (build_type == "debug")
    {
        INFO("debug_build_shared_command: %s", debug_build_shared_command );
        build_shared_command = debug_build_shared_command;
        build_binary_command = debug_build_binary_command;
    }
    else if (build_type == "release")
    {
        INFO("release_build_shared_command: %s", release_build_shared_command );
        build_shared_command = release_build_shared_command;
        build_binary_command = release_build_binary_command;
    }
    else if (build_type == "dist")
    {
        INFO("dist_build_shared_command: %s", dist_build_shared_command );
        build_shared_command = dist_build_shared_command;
        build_binary_command = dist_build_binary_command;
    }
	else
	{
		WARNING("No valid build type was given, distribution will be used");
        INFO("dist_build_shared_command: %s", dist_build_shared_command );
        build_shared_command = dist_build_shared_command;
        build_binary_command = dist_build_binary_command;
	}

    // BUILD THE SHARED LIBRARY
    {
        build_shared_command += " -I" CODE_PATH;
        if (includes != 0)
        {
            for (int i = 0; includes[i] != 0; ++i)
            {
                build_shared_command += " -I";
                build_shared_command += includes[i];
            }
        }

        if (defines != 0)
        {
            for (int i = 0; defines[i] != 0; ++i)
            {
                //build_shared_command += " -D";
                build_shared_command += defines[i];
            }
        }

#if defined(_WIN32) || defined(_WIN64)
        PANIC("IMPLEMENT THE EXPORT PART OF THE BUILD FOR THE WINDOWS PLATFORM");
#endif

        //build_shared_command += " -I\"" CODE_PATH "\"";
        build_shared_command += " " CODE_PATH PATH_SEPARATOR SHARED_FILE;

        build_shared_command += " -o " BUILD_DIR PATH_SEPARATOR;
        build_shared_command += build_type;
        build_shared_command += PATH_SEPARATOR SHARED_NAME;

        INFO("build command %s:", build_shared_command.c_str());
        system(build_shared_command.c_str());
    }

    {
        const char* temp[] = {CUSTOM_PATH, FREETYPE2, CODE_PATH PATH_SEPARTOR "platform_all", CODE_PATH PATH_SEPARTOR "platform_unix", 0};
        const char **inc = (const char**)temp;

        build_binary_command += " -I" CODE_PATH;
        if (inc != 0)
        {
            for (int i = 0; inc[i] != 0; ++i)
            {
                build_binary_command += " -I";
                build_binary_command += inc[i];
            }
        }

        if (defines != 0)
        {
            for (int i = 0; defines[i] != 0; ++i)
            {
                build_binary_command += defines[i];
            }
        }

#if defined(_WIN32) || defined(_WIN64)
        PANIC("IMPLEMENT THE EXPORT PART OF THE BUILD FOR THE WINDOWS PLATFORM");
#endif


		build_binary_command += " -I\"" CODE_PATH "\"";
		build_binary_command += " " BINARY_FILE;

        build_binary_command += " -o " BUILD_DIR PATH_SEPARATOR;
        build_binary_command += build_type;
        build_binary_command += PATH_SEPARATOR BINARY_NAME;

        INFO("build command %s:", build_binary_command.c_str());
        system(build_binary_command.c_str());

    }

    if (update_local_theme){
        //char *themes_folder = fm_str(arena, "../build/themes");
        //char *source_themes_folder = fm_str(arena, "ship_files/themes");
        //fm_clear_folder(themes_folder);
        //fm_make_folder_if_missing(arena, themes_folder);
        //fm_copy_all(source_themes_folder, themes_folder);
    }
}

void standard_build(const std::string build_type)
{
    buildsuper(build_type);
    build_main(true, build_type);
}

//internal char*
//get_4coder_dist_name(Arena *arena, u32 platform, char *tier, u32 arch){
//    char *name = fm_str(arena, "4coder-" MAJOR_STR "-" MINOR_STR "-" PATCH_STR "-", tier);
//    if (platform != Platform_None){
//        name = fm_str(arena, name, "-", platform_names[platform]);
//    }
//    if (arch != Arch_None){
//        name = fm_str(arena, name, "-", arch_names[arch]);
//    }
//    return(name);
//}
//
//function void
//package_for_arch(Arena *arena, u32 arch, char *cdir, char *build_dir, char *pack_dir, i32 tier, char *tier_name,  char *current_dist_tier, u32 flags, char** dist_files, i32 dist_file_count){
//    //char *arch_name  = arch_names[arch];
//    //char *parent_dir = fm_str(arena, current_dist_tier, "_", arch_name);
//    //char *dir        = fm_str(arena, parent_dir, SLASH "4coder");
//    //char *zip_dir    = fm_str(arena, pack_dir, SLASH, tier_name, "_", arch_name);
//    //
//    //printf("\nBUILD: %s_%s\n", tier_name, arch_name);
//    //printf(" parent_dir = %s;\n", parent_dir);
//    //printf(" dir = %s;\n", dir);
//    //printf(" zip_dir = %s;\n", zip_dir);
//    //fflush(stdout);
//    //
//    //buildsuper(arena, cdir, fm_str(arena, default_custom_target), arch);
//    //build_main(arena, cdir, false, flags, arch);
//    //
//    //fm_clear_folder(parent_dir);
//    //fm_make_folder_if_missing(arena, parent_dir);
//    //
//    //fm_make_folder_if_missing(arena, dir);
//    //fm_copy_file(fm_str(arena, build_dir, "/4ed" EXE), fm_str(arena, dir, "/4ed" EXE));
//    //fm_copy_file(fm_str(arena, build_dir, "/4ed_app" DLL), fm_str(arena, dir, "/4ed_app" DLL));
//    //fm_copy_file(fm_str(arena, build_dir, "/custom_4coder" DLL), fm_str(arena, dir, "/custom_4coder" DLL));
//    //
//    //if (tier == Tier_Demo){
//    //    dist_file_count -= 1;
//    //}
//    //
//    //for (i32 j = 0; j < dist_file_count; j += 1){
//    //    fm_copy_all(dist_files[j], dir);
//    //}
//    //
//    //if (tier == Tier_Super){
//    //    char *custom_src_dir = fm_str(arena, cdir, SLASH, "custom");
//    //    char *custom_dst_dir = fm_str(arena, dir, SLASH, "custom");
//    //    fm_make_folder_if_missing(arena, custom_dst_dir);
//    //    fm_copy_all(custom_src_dir, custom_dst_dir);
//    //}
//    //
//    //char *dist_name = get_4coder_dist_name(arena, This_OS, tier_name, arch);
//    //char *zip_name = fm_str(arena, zip_dir, SLASH, dist_name, ".zip");
//    //fm_make_folder_if_missing(arena, zip_dir);
//    //fm_zip(parent_dir, "4coder", zip_name);
//}
//
////internal u32
////tier_flags(Tier_Code code){
////    u32 result = 0;
////    switch (code){
////        case Tier_Super:
////        {
////            result = SUPER;
////        }break;
////    }
////    return(result);
////}
//
//internal void
//package(Arena *arena, char *cdir, Tier_Code tier, Arch_Code arch){
//    // NOTE(allen): meta
//    //char *build_dir = fm_str(arena, BUILD_DIR);
//    //char *pack_dir = fm_str(arena, PACK_DIR);
//    //char *dist_files[2];
//    //dist_files[0] = fm_str(arena, "../non-source/dist_files");
//    //dist_files[1] = fm_str(arena, "ship_files");
//    //
//    //printf("build dir: %s\n", build_dir);
//    //printf("pack dir: %s\n", pack_dir);
//    //printf("dist files: %s, %s\n", dist_files[0], dist_files[1]);
//    //fflush(stdout);
//    //
//    //u32 base_flags = SHIP | DEBUG_INFO | OPTIMIZATION;
//    //
//    //fm_make_folder_if_missing(arena, pack_dir);
//    //
//    //char *tier_name = tier_names[tier];
//    //u32 flags = base_flags | tier_flags(tier);
//    //Temp_Memory temp = begin_temp(arena);
//    //char *current_dist_tier = fm_str(arena, ".." SLASH "current_dist_", tier_name);
//    //package_for_arch(arena, arch, cdir, build_dir, pack_dir, tier, tier_name, current_dist_tier, flags, dist_files, ArrayCount(dist_files));
//    //end_temp(temp);
//}



// BOTTOM

