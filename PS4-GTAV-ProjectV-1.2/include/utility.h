#include <Common.h>
#include "plugin_common.h"
#include "types.h"
#include <stdbool.h>

unsigned char *hexstrtochar2(const char *hexstr, s64 *size);
void sys_proc_rw(u64 address, void *data, u64 length);
bool file_exists (char *filename);
void memcpy_p(u64 Address, const void *Data, u64 Length);
bool hex_prefix(const char *str);

// http://www.cse.yorku.ca/~oz/hash.html
constexpr inline u64 djb2_hash(const char *str);

u64 patch_hash_calc(const char *title, const char *name, const char *app_ver,
                    const char *title_id, const char *elf);
void patch_data1(const char* patch_type_str, u64 addr, const char *value, uint32_t source_size, uint64_t jump_target);

void Sleep(unsigned int milliseconds);
void WriteJump(uint64_t address, uint64_t destination);
void ReadMemory(uint64_t address, void *buffer, int length);
void WriteMemory(uint64_t address, void *buffer, int length);
int ISDIGIT (char c);
int ISALPHA(int c);
int ISUPPER(int ch);
int ISSPACE(int c);
u32 pattern_to_byte(const char* pattern, uint8_t* bytes);
u8* PatternScan(uint64_t module_base, uint32_t module_size, const char* signature);
char* toLower(char* s);
char * StrToLower(char *str);
bool gfx_exists_ (const char* path, const char *filename);
 char* file_exists_(const char *data_path,  char* a2);
char* toLoweRiii(char* strr);
char* pprintf(const char *format, ...);
