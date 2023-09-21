#include <Common.h>
#include "plugin_common.h"
#include "types.h"
#include "utility.h"

namespace Hooks {
extern uint64_t v_gameDir;
extern int64_t SUB_19E03E0_ADDR;
extern int64_t SUB_19E0200_ADDR;
typedef uint64_t(*gfxLoader_t)(long long a1, const char *path, long long a3, unsigned int a4, unsigned int a5);
typedef char(*xml_omt_Loader_t)(long long a1,  char *path, char* ex, long long a4, long long a5);
typedef uint64_t(*GXT2_t)(char *const a1, char *a2, char* a3, uint64_t a4, uint64_t a5, uint64_t a6, ...);
typedef char*(*DataFunc_t)(char* a1, _BYTE* a2);
//typedef double(*fcxLoader_t)(long long Type, int32_t a2, __m128 _XMM0);
typedef u8(*contentIsExist_t)(long long a1, char *path, long long a3);
typedef char*(*omtLoader_t)(uint64_t a1, char* path, char* ex, uint64_t a4, uint8_t a5);
typedef char(*xmlLoader_t)(uint64_t a1, char* path, uint64_t a3, uint64_t a4, uint64_t a5, char a6, uint64_t a7);
extern gfxLoader_t gfxLoader_Stub;
extern GXT2_t GXT2_Stub;
extern DataFunc_t DataFunc_Stub;
//extern fcxLoader_t fcxLoader_Stub;
extern contentIsExist_t contentIsExist_Stub;
extern omtLoader_t omtLoader_Stub;
extern xml_omt_Loader_t xml_omt_Loader_Stub;
extern xmlLoader_t xmlLoader_Stub;
uint64_t gfxLoader_hook(long long a1, const char *path, long long a3, unsigned int a4, unsigned int a5);
char xml_omt_Loader_hook(long long a1, char *path, char* ex, long long a4, long long a5);
uint64_t GXT2_hook(char *const a1,  char *a2, char* a3, uint64_t a4, uint64_t a5, uint64_t a6, ...);
char* DataFunc_hook(char* a1, _BYTE* a2);
//double fcxLoader_hook(long long Type, int32_t a2, __m128 _XMM0);
u8 contentIsExist_hook(long long a1, char *path, long long a3);
char* omtLoader_hook(uint64_t a1, char* path, char* ex, uint64_t a4, uint8_t a5);
char xmlLoader_hook(uint64_t a1,  char* path, uint64_t a3, uint64_t a4, uint64_t a5, char a6, uint64_t a7);
};
